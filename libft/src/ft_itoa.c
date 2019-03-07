/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrouvroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 16:22:12 by nrouvroy          #+#    #+#             */
/*   Updated: 2018/09/18 16:36:43 by nrouvroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_itoa_get_str_len(int n)
{
	size_t i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

char			*ft_itoa(int n)
{
	char			*str;
	size_t			len;
	unsigned int	ncpy;

	len = ft_itoa_get_str_len(n);
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
