/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrouvroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 15:06:07 by nrouvroy          #+#    #+#             */
/*   Updated: 2018/09/19 10:40:22 by nrouvroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_noflags(t_conv *conv)
{
	int	i;

	i = -1;
	while (++i < 8)
		if (conv->f[i] || conv->f[9])
			return (0);
	return (1);
}

int		ft_empty_proc(t_conv *conv, t_data *data)
{
	char	*str;

	if (conv->f[5])
	{
		if (!(str = ft_strnew(conv->f[5] - 1)))
			return (ERROR);
		str = ft_memset(str, conv->f[1] ? '0' : ' ', conv->f[5] - 1);
		ft_printaddstr(str, data);
		free(str);
	}
	return (0);
}

int		ft_type_b(va_list ap, t_conv *conv, t_data *data)
{
	char	*str;

	if (!(str = ft_type_u_len(ap, conv, 2)))
		return (ERROR);
	if (!ft_noflags(conv))
		if (!(str = ft_type_u_flags(str, conv)))
			return (ERROR);
	ft_printaddstr(str, data);
	free(str);
	return (0);
}

int		ft_type_per(va_list ap, t_conv *conv, t_data *data)
{
	char *s;

	ap = NULL;
	if (!(s = ft_strnew(1)))
		return (ERROR);
	while ((!conv->f[1] || conv->f[0]) && conv->f[5]-- > 1)
		if (!(s = ft_strjoinfn(s, " ")))
			return (ERROR);
	while (conv->f[1] && conv->f[5]-- > 1)
		if (!(s = ft_strjoinfn(s, "0")))
			return (ERROR);
	s = conv->f[0] ? ft_strjoinnf("%", s) : ft_strjoinfn(s, "%");
	ft_printaddstr(s, data);
	free(s);
	return (0);
}

char	*ft_type_u_utils_utils(char *stb)
{
	if (ft_strlen(stb) >= 2)
		stb[ft_strlen(stb) - 2] = '\0';
	else
		*stb = '\0';
	return (stb);
}
