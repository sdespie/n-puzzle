/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structinit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrouvroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 14:18:10 by nrouvroy          #+#    #+#             */
/*   Updated: 2018/09/17 14:20:09 by nrouvroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_data	*ft_data_init(const char *string, t_data *data)
{
	if (!(data = (t_data*)malloc(sizeof(t_data))))
		return (NULL);
	if (!(data->ret = ft_strdup(string)))
		return (NULL);
	data->str = data->ret;
	data->count = 0;
	return (data);
}

t_conv	*ft_conv_init(t_data *data, t_conv *conv)
{
	int	count;

	count = -1;
	if (!(conv = (t_conv*)malloc(sizeof(t_conv))))
		return (NULL);
	while (++count < 10)
		conv->f[count] = 0;
	count = 1;
	conv->f[8] = 16;
	while (*data->str && !ft_iso(1, *data->str) && ft_iso(0, *data->str))
	{
		data->str++;
		count++;
	}
	data->str -= count - 1;
	if (!(conv->to_conv = (char*)malloc(sizeof(char) * count + 1)))
		return (NULL);
	conv->to_conv = ft_strncpy(conv->to_conv, data->str, count);
	*(conv->to_conv + count) = '\0';
	data->str += count;
	conv->free = conv->to_conv;
	return (conv);
}

void	ft_conv_free(t_conv *conv)
{
	free(conv->free);
	free(conv);
}

int		ft_iso(int mode, char c)
{
	char *str;

	if (!mode)
		str = ".0123456789 #+-lhjz\0";
	else if (mode == 1)
		str = "diouDsSpOUxXcCb%\0";
	else if (mode == 2)
		str = "lhjz\0";
	else if (mode == 3)
		str = "sd#.0123456789-+ lhjziouDSpOUxXcCb%\0";
	else
		return (0);
	while (*str)
		if (c == *str++)
			return (1);
	return (0);
}
