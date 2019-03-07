/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrouvroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 13:23:37 by nrouvroy          #+#    #+#             */
/*   Updated: 2018/09/18 14:54:17 by nrouvroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_type_x(va_list ap, t_conv *conv, t_data *data)
{
	char	*str;

	if (!(str = ft_type_u_len(ap, conv, 16)))
		return (ERROR);
	if (!ft_strcmp("0", str))
		conv->f[2] = 0;
	if (!ft_noflags(conv))
		if (!(str = ft_type_u_flags(str, conv)))
			return (ERROR);
	ft_printaddstr(str, data);
	free(str);
	return (0);
}

int	ft_type_gx(va_list ap, t_conv *conv, t_data *data)
{
	char	*str;

	if (!(str = ft_type_u_len(ap, conv, 16)))
		return (ERROR);
	if (!ft_strcmp("0", str))
		conv->f[2] = 0;
	ft_str_toupper(str);
	if (!ft_noflags(conv))
		if (!(str = ft_type_u_flags(str, conv)))
			return (ERROR);
	ft_printaddstr(str, data);
	free(str);
	return (0);
}
