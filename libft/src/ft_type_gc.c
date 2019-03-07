/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_gc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrouvroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 13:25:52 by nrouvroy          #+#    #+#             */
/*   Updated: 2018/09/18 12:01:49 by nrouvroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_type_gc(va_list ap, t_conv *conv, t_data *data)
{
	wchar_t	chr;
	size_t	lc;

	chr = (wchar_t)va_arg(ap, wint_t);
	lc = chrsize(chr);
	if (ft_noflags(conv))
	{
		ft_putwchar_fd(chr, 1);
		data->count += lc;
	}
	else if ((size_t)conv->f[5] > lc)
	{
		if (ft_type_gc_util(conv, chr, lc, data) < 0)
			return (ERROR);
	}
	else
	{
		ft_putwchar_fd(chr, 1);
		data->count += lc;
	}
	return (0);
}

int		ft_type_gc_util(t_conv *conv, wchar_t chr, size_t lc, t_data *data)
{
	char	*stb;

	if (!(stb = ft_strnew(conv->f[5] - lc)))
		return (ERROR);
	stb = ft_memset(stb, !conv->f[0] && conv->f[1] ? '0' :
			' ', conv->f[5] - lc);
	if (conv->f[0])
	{
		ft_putwchar_fd(chr, 1);
		write(1, stb, conv->f[5] - lc);
	}
	else
	{
		write(1, stb, conv->f[5] - lc);
		ft_putwchar_fd(chr, 1);
	}
	data->count += conv->f[5];
	free(stb);
	return (1);
}

size_t	chrsize(wchar_t chr)
{
	if (chr <= 0x7F)
		return (1);
	else if (chr <= 0x7FF)
		return (2);
	else if (chr <= 0xFFFF)
		return (3);
	else if (chr <= 0x10FFFF)
		return (4);
	else
		return (0);
}
