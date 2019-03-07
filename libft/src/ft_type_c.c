/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrouvroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 13:24:51 by nrouvroy          #+#    #+#             */
/*   Updated: 2018/09/17 17:58:07 by nrouvroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_type_c_flags(t_conv *conv, char c)
{
	char	*stb;

	if (!(stb = ft_strnew(conv->f[5])))
		return (NULL);
	stb = ft_memset(stb, !conv->f[0] && conv->f[1] ? '0' : ' ', conv->f[5]);
	if (conv->f[0])
		stb[0] = c;
	else
		stb[conv->f[5] - 1] = c;
	return (stb);
}

void	ft_type_c_util(t_conv *conv, char c, t_data *data)
{
	if (conv->f[0])
		ft_printadd(c, data);
	while (conv->f[5]-- > 1)
		ft_printadd(conv->f[1] ? '0' : ' ', data);
	if (!conv->f[0])
		ft_printadd(c, data);
}

int		ft_type_c(va_list ap, t_conv *conv, t_data *data)
{
	char	c;
	char	*stb;

	if (conv->f[6] == 'l')
	{
		conv->f[6] = 0;
		return (ft_type_gc(ap, conv, data));
	}
	c = va_arg(ap, int);
	if (ft_noflags(conv) || ((conv->f[4] || c == '\0' || conv->f[9] ||
					conv->f[0]) && !conv->f[5]))
		ft_printadd(c, data);
	else if (c == '\0')
		ft_type_c_util(conv, c, data);
	else if (conv->f[5])
	{
		if (!(stb = ft_type_c_flags(conv, c)))
			return (ERROR);
		ft_printaddstr(stb, data);
		free(stb);
	}
	return (0);
}
