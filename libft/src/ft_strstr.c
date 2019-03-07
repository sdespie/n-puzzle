/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrouvroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 18:18:25 by nrouvroy          #+#    #+#             */
/*   Updated: 2018/06/17 15:44:37 by nrouvroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *substr)
{
	size_t len;

	len = ft_strlen(substr);
	if (len == 0)
		return ((char *)str);
	while (*str)
		if (!ft_memcmp(str++, substr, len))
			return ((char*)(str - 1));
	return (NULL);
}
