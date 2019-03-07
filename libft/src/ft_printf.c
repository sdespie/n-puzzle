/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrouvroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 14:17:45 by nrouvroy          #+#    #+#             */
/*   Updated: 2018/09/18 11:58:40 by nrouvroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	t_data	*data;
	int		l;

	data = NULL;
	if (!(data = ft_data_init(format, data)))
		return (ERROR);
	va_start(ap, format);
	while (*data->str)
	{
		if (*data->str != '%')
			ft_printadd(*(data->str++), data);
		else if (ft_repart(ap, data) < 0)
		{
			free(data->ret);
			free(data);
			return (ERROR);
		}
	}
	va_end(ap);
	l = data->count;
	free(data->ret);
	free(data);
	return (l);
}

int		ft_repart(va_list ap, t_data *data)
{
	int		ret;
	t_conv	*conv;

	conv = NULL;
	data->str++;
	if (!*data->str)
		return (0);
	if (*data->str == '%' && ((ret = ft_percent_hand(data)) == -1 || ret == 0))
		return (ret);
	if (!(conv = ft_conv_init(data, conv)))
		return (ERROR);
	while (*conv->to_conv)
	{
		if (!ft_iso(3, *conv->to_conv))
		{
			return (ft_wconv(data, conv));
		}
		if (ft_parse(conv) == ERROR)
			return (ERROR);
		conv->to_conv++;
	}
	if (ft_process(ap, conv, data) == ERROR)
		return (ERROR);
	ft_conv_free(conv);
	return (1);
}

int		ft_wconv(t_data *data, t_conv *conv)
{
	if (!conv->f[0])
		if (ft_empty_proc(conv, data) < 0)
			return (ERROR);
	ft_printadd(*conv->to_conv, data);
	if (conv->f[0])
		if (ft_empty_proc(conv, data) < 0)
			return (ERROR);
	free(conv->free);
	free(conv);
	return (0);
}

int		ft_parse(t_conv *conv)
{
	char	c;
	char	*fs;
	int		i;

	fs = "-0#+ .123456789lhzjsSpdDioOuUxXcCb%\0";
	c = *conv->to_conv;
	i = 0;
	while (c != fs[i] && fs[i] != '\0')
		i++;
	if (fs[i] == '\0')
		return (ERROR);
	if (i >= 0 && i <= 4)
		return ((conv->f[i] = 1));
	if (i >= 19 && i <= 34 && conv->f[8] == 16)
		return ((conv->f[8]) = i - 19);
	if (i >= 6 && i <= 14 && !conv->f[5])
	{
		conv->f[5] = ft_atoi(conv->to_conv);
		return (*(conv->to_conv += ft_getdigitnbr(conv->f[5]) - 1));
	}
	else
		return (ft_parse_util(i, conv));
}

int		ft_parse_util(int i, t_conv *conv)
{
	if (i == 5 && *(conv->to_conv + 1) != '.')
	{
		conv->f[9] = 1;
		conv->f[7] = ft_atoi(conv->to_conv + 1);
		if (!conv->f[7])
		{
			while (*(conv->to_conv + 1) == '0')
				conv->to_conv++;
		}
		else
			conv->to_conv += ft_getdigitnbr(conv->f[7]);
		return (0);
	}
	else if (i >= 15 && i <= 18)
		return ((conv->f[6] = ft_getlength(conv->to_conv, conv)));
	return (0);
}
