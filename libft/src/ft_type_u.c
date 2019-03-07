/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrouvroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 13:21:53 by nrouvroy          #+#    #+#             */
/*   Updated: 2018/09/18 12:58:44 by nrouvroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_type_u(va_list ap, t_conv *conv, t_data *data)
{
	char	*str;

	if (!(str = ft_type_u_len(ap, conv, 10)))
		return (ERROR);
	if (!ft_noflags(conv))
		if (!(str = ft_type_u_flags(str, conv)))
			return (ERROR);
	ft_printaddstr(str, data);
	free(str);
	return (0);
}

int	ft_type_gu(va_list ap, t_conv *conv, t_data *data)
{
	conv->f[8] = 8;
	conv->f[6] = 'l';
	return (ft_type_u(ap, conv, data));
}
