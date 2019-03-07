/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrouvroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 12:51:59 by nrouvroy          #+#    #+#             */
/*   Updated: 2018/09/18 12:11:44 by nrouvroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_type_p(va_list ap, t_conv *conv, t_data *data)
{
	char	*str;

	if (!(str = ft_pf_uitoa_base(va_arg(ap, unsigned long int), 16)))
		return (ERROR);
	if ((ft_noflags(conv) || (!ft_strcmp(str, "0") && !conv->f[5])) &&
			!conv->f[9])
	{
		if (!(str = ft_strjoinnf("0x", str)))
			return (ERROR);
	}
	else if (conv->f[9] && !conv->f[7] && !conv->f[5])
	{
		free(str);
		if (!(str = ft_strdup("0x")))
			return (ERROR);
	}
	else
	{
		conv->f[2] = 1;
		if (!(str = ft_type_u_flags(str, conv)))
			return (ERROR);
	}
	ft_printaddstr(str, data);
	free(str);
	return (1);
}
