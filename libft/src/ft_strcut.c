/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrouvroy <nrouvroy@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 20:56:37 by nrouvroy          #+#    #+#             */
/*   Updated: 2018/11/05 13:50:55 by nrouvroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Takes a string and cuts it in two strings, the first one is n char long.
** second one is strlen(str)-n long.
**
** the string tab is not null-terminated ! use it as ret = ft_strcut(str, 3);
** ret[0] and ret[1]. (individual strings are null-terminated)
*/

char	**ft_strcut(char *str, int n)
{
	char **ret;

	ret = (char **)malloc(sizeof(char*) * 2);
	ret[0] = ft_strsub(str, 0, n);
	ret[1] = ft_strsub(str, n, ft_strlen(str) - n - 1);
	return (ret);
}
