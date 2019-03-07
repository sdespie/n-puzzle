/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrouvroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 21:00:48 by nrouvroy          #+#    #+#             */
/*   Updated: 2018/06/13 22:44:33 by nrouvroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	unsigned char *psrc;
	unsigned char *pdst;

	pdst = (unsigned char *)dst;
	psrc = (unsigned char *)src;
	while (len--)
		*pdst++ = *psrc++;
	return (dst);
}
