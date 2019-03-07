/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_o.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrouvroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 13:20:53 by nrouvroy          #+#    #+#             */
/*   Updated: 2018/09/18 12:09:13 by nrouvroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_type_o(va_list ap, t_conv *conv, t_data *data)
{
	char	*str;

	if (!(str = ft_type_u_len(ap, conv, 8)))
		return (ERROR);
	if (conv->f[2] && ft_strcmp(str, "0"))
		if (!(str = ft_strjoinnf("0", str)))
			return (ERROR);
	if (!ft_noflags(conv))
		if (!(str = ft_type_u_flags(str, conv)))
			return (ERROR);
	ft_printaddstr(str, data);
	free(str);
	return (1);
}

int	ft_type_go(va_list ap, t_conv *conv, t_data *data)
{
	conv->f[8] = 6;
	conv->f[6] = 'l';
	return (ft_type_o(ap, conv, data));
}
