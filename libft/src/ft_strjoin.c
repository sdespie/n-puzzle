/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrouvroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 13:38:29 by nrouvroy          #+#    #+#             */
/*   Updated: 2018/09/17 17:27:40 by nrouvroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;

	if (!s1 || !s2)
		return (NULL);
	if ((s = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1)) != NULL)
	{
		s = ft_strcat(s, s1);
		s = ft_strcat(s, s2);
	}
	return (s);
}
