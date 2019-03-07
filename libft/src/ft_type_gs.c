/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_gs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrouvroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 11:52:25 by nrouvroy          #+#    #+#             */
/*   Updated: 2018/09/18 12:05:43 by nrouvroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_getlenwstrprec(wchar_t *str, int prec, int l)
{
	if (*str == '\0' || prec <= 0)
		return (l);
	else if (*str <= 0x7F)
		return (ft_getlenwstrprec(str + 1, prec - 1, l + 1));
	else if (*str <= 0x7FF && prec >= 2)
		return (ft_getlenwstrprec(str + 1, prec - 2, l + 2));
	else if (*str <= 0xFFFF && prec >= 3)
		return (ft_getlenwstrprec(str + 1, prec - 3, l + 3));
	else if (*str <= 0x10FFFF && prec >= 4)
		return (ft_getlenwstrprec(str + 1, prec - 4, l + 4));
	else
		return (l);
}

size_t	ft_getlenwstr(wchar_t *str)
{
	size_t	l;

	l = 0;
	while (*str)
	{
		if (*str <= 0x7F)
			l++;
		else if (*str <= 0x7FF)
			l += 2;
		else if (*str <= 0xFFFF)
			l += 3;
		else if (*str <= 0x10FFFF)
			l += 4;
		str++;
	}
	return (l);
}

int		ft_type_gs(va_list ap, t_conv *conv, t_data *data)
{
	int		l;
	wchar_t	*str;

	str = va_arg(ap, wchar_t*);
	if (str == NULL)
		str = L"(null)";
	l = conv->f[9] ? ft_getlenwstrprec(str, conv->f[7], 0) : ft_getlenwstr(str);
	if (conv->f[5] > l)
		ft_wstrwlen(conv, l, str, data);
	else
	{
		ft_putnwstr_fd(str, l, 1);
		data->count += l;
	}
	return (0);
}

int		ft_wstrwlen(t_conv *conv, int l, wchar_t *str, t_data *data)
{
	char	*sb;

	if (!(sb = ft_strnew(conv->f[5] - l)))
		return (ERROR);
	sb = ft_memset(sb, !conv->f[0] && conv->f[1] ? '0' : ' ', conv->f[5] - l);
	if (conv->f[0])
	{
		ft_putnwstr_fd(str, l, 1);
		write(1, sb, conv->f[5] - l);
	}
	else
	{
		write(1, sb, conv->f[5] - l);
		ft_putnwstr_fd(str, l, 1);
	}
	data->count += conv->f[5];
	free(sb);
	return (1);
}
