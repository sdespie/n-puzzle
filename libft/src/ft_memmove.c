/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrouvroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 22:13:16 by nrouvroy          #+#    #+#             */
/*   Updated: 2018/06/17 14:36:14 by nrouvroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*psrc;
	char	*pdst;
	size_t	i;

	i = -1;
	psrc = (char *)src;
	pdst = (char *)dst;
	if (psrc < pdst)
		while ((int)(--len) >= 0)
			*(pdst + len) = *(psrc + len);
	else
		while (++i < len)
			*(pdst + i) = *(psrc + i);
	return (dst);
}
