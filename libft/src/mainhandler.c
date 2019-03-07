/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainhandler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrouvroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 16:52:48 by nrouvroy          #+#    #+#             */
/*   Updated: 2018/08/28 15:09:46 by nrouvroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_get_str_len(intmax_t n)
{
	size_t i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

char	*ft_pf_itoa(intmax_t n)
{
	char			*str;
	size_t			len;
	uintmax_t		ncpy;

	len = ft_get_str_len(n);
	ncpy = n;
	if (n < 0)
	{
		ncpy = -n;
		len++;
	}
	if (!(str = ft_strnew(len)))
		return (NULL);
	str[--len] = ncpy % 10 + '0';
	while (ncpy /= 10)
		str[--len] = ncpy % 10 + '0';
	if (n < 0)
		*str = '-';
	return (str);
}

int		ft_count(int value, int base)
{
	int count;

	count = 0;
	if (value == 0)
		return (1);
	while (value != 0)
	{
		value = value / base;
		count++;
	}
	return (count);
}

char	*ft_pf_uitoa_base(uintmax_t value, int base)
{
	intmax_t	i;
	uintmax_t	n;
	int			conv[128];
	char		*tab;
	char		*str;

	tab = "0123456789abcdef\0";
	if (!value)
		return (ft_strdup("0"));
	i = 0;
	n = (intmax_t)value;
	while (n > 0)
	{
		conv[i++] = n % base;
		n /= base;
	}
	if (!(str = ft_strnew(i)))
		return (NULL);
	i -= 1;
	while (i >= 0)
		str[n++] = tab[conv[i--]];
	return (str);
}
