/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrouvroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 21:47:37 by nrouvroy          #+#    #+#             */
/*   Updated: 2018/06/13 21:58:36 by nrouvroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*psrc;
	unsigned char	*pdst;
	unsigned char	x;

	psrc = (unsigned char *)src;
	pdst = (unsigned char *)dst;
	x = c;
	while (n-- > 0)
		if ((*pdst++ = *psrc++) == x)
			return (pdst);
	return (NULL);
}
