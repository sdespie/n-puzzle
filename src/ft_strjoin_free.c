/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-spie <sde-spie@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 14:25:50 by sde-spie          #+#    #+#             */
/*   Updated: 2019/01/16 16:35:02 by sde-spie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"

char				*ft_strjoin_free(char *s1, char *s2, int nb)
{
	char			*newstr;
	unsigned int	i;
	unsigned int	len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	newstr = ft_strnew(len);
	if (!newstr)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s1))
	{
		newstr[i] = s1[i];
		i++;
	}
	while (i < len)
	{
		newstr[i] = s2[i - ft_strlen(s1)];
		i++;
	}
	(nb != 1) ? ft_strdel(&s1) : 0;
	(nb >= 1) ? ft_strdel(&s2) : 0;
	return (newstr);
}
