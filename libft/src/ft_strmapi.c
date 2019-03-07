/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrouvroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 12:55:30 by nrouvroy          #+#    #+#             */
/*   Updated: 2018/06/18 15:24:33 by nrouvroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *str, char (*f)(unsigned int, char))
{
	char	*ret;
	int		i;

	if (!str)
		return (NULL);
	if (!(ret = ft_strnew(ft_strlen(str))))
		return (NULL);
	i = -1;
	while (*(str + ++i))
		*(ret + i) = f(i, *(str + i));
	return (ret);
}
