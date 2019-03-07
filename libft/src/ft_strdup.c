/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrouvroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 15:09:02 by nrouvroy          #+#    #+#             */
/*   Updated: 2018/07/16 15:27:27 by nrouvroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char *dst;
	char *ret;

	if ((dst = (char*)malloc(sizeof(char) * (ft_strlen(src) + 1))) == NULL)
		return (NULL);
	ret = dst;
	while (*src)
		*ret++ = *src++;
	*ret = '\0';
	return (dst);
}
