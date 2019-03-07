/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrouvroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 16:01:12 by nrouvroy          #+#    #+#             */
/*   Updated: 2018/06/17 15:04:13 by nrouvroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dst, const char *src)
{
	int i;
	int j;

	i = -1;
	j = (int)ft_strlen(dst);
	while (*(src + ++i))
		*(dst + j++) = *(src + i);
	*(dst + j) = '\0';
	return (dst);
}
