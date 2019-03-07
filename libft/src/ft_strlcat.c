/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrouvroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 16:40:20 by nrouvroy          #+#    #+#             */
/*   Updated: 2018/06/21 14:39:36 by nrouvroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*pdst;
	const char	*psrc;
	size_t		n;
	size_t		dst_len;

	pdst = dst;
	psrc = src;
	n = size;
	while (n-- != 0 && *pdst != '\0')
		pdst++;
	dst_len = pdst - dst;
	n = size - dst_len;
	if (n == 0)
		return (dst_len + ft_strlen(psrc));
	while (*psrc != '\0')
	{
		if (n != 1)
		{
			*pdst++ = *psrc;
			n--;
		}
		psrc++;
	}
	*pdst = '\0';
	return (dst_len + (psrc - src));
}
