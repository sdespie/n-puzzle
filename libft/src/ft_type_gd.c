/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_gd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrouvroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 12:51:11 by nrouvroy          #+#    #+#             */
/*   Updated: 2018/09/18 12:04:24 by nrouvroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_type_d_der(t_conv *conv, char *str)
{
	char	*strb;

	if (conv->f[4] && conv->f[0])
		if (str[0] == '+' && str[1] == ' ')
		{
			strb = ft_mjoin(3, "+", str + 2, " ");
			free(str);
			str = strb;
		}
	return (str);
}

char	*ft_type_d_der_mdr(t_conv *conv, char *str, size_t l)
{
	l = 0;
	while (conv->f[3] && str[l] == ' ')
		l++;
	if (str[l] != '-' && l > 0)
		str[l - 1] = '+';
	return (str);
}

int		ft_type_gd(va_list ap, t_conv *conv, t_data *data)
{
	conv->f[8] = 3;
	conv->f[6] = 'l';
	return (ft_type_d(ap, conv, data));
}

int		ft_type_i(va_list ap, t_conv *conv, t_data *data)
{
	return (ft_type_d(ap, conv, data));
}
