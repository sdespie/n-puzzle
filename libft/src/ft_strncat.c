/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrouvroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 16:24:50 by nrouvroy          #+#    #+#             */
/*   Updated: 2018/06/14 16:56:56 by nrouvroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dst, const char *src, size_t len)
{
	char	*ret;

	ret = dst;
	while (*dst)
		dst++;
	while (len--)
		if (!(*dst++ = *src++))
			return (ret);
	*dst = '\0';
	return (ret);
}
