/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_toupper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrouvroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 15:46:23 by nrouvroy          #+#    #+#             */
/*   Updated: 2018/09/06 13:41:48 by nrouvroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_toupper(char *str)
{
	char	*ret;

	if (!str || !*str)
		return (str);
	ret = str;
	while (*str)
	{
		*str = ft_toupper(*str);
		str++;
	}
	return (ret);
}
