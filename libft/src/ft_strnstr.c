/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrouvroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 18:16:56 by nrouvroy          #+#    #+#             */
/*   Updated: 2018/06/21 14:23:17 by nrouvroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *substr, size_t len)
{
	if (!*str && !*substr)
		return ("");
	while (*str)
	{
		if (len < ft_strlen(substr))
			break ;
		if (ft_strlen(str) < ft_strlen(substr))
			break ;
		if (ft_memcmp(str, substr, ft_strlen(substr)) == 0)
			return ((char*)str);
		len--;
		str++;
	}
	return (NULL);
}
