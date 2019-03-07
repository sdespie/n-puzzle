/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrouvroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 12:00:03 by nrouvroy          #+#    #+#             */
/*   Updated: 2018/06/18 14:22:53 by nrouvroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *str, char (*f)(char))
{
	char	*ret;
	int		i;

	if (!str || !f)
		return (NULL);
	if (!(ret = ft_strnew(ft_strlen(str))))
		return (NULL);
	i = -1;
	while (*(str + ++i))
		*(ret + i) = f(*(str + i));
	return (ret);
}
