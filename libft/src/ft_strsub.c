/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrouvroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 13:33:54 by nrouvroy          #+#    #+#             */
/*   Updated: 2018/06/18 14:31:26 by nrouvroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *str, unsigned int start, size_t len)
{
	char	*s;

	if (!str)
		return (NULL);
	if ((s = ft_strnew(len)) != NULL)
		ft_strncpy(s, str + start, len);
	return (s);
}
