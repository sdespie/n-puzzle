/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrouvroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 15:57:01 by nrouvroy          #+#    #+#             */
/*   Updated: 2018/06/18 14:59:35 by nrouvroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countwords(char const *str, char c)
{
	int	count;
	int	sub;

	count = 0;
	sub = 0;
	while (*str != '\0')
	{
		if (sub == 1 && *str == c)
			sub = 0;
		if (sub == 0 && *str != c)
		{
			sub = 1;
			count++;
		}
		str++;
	}
	return (count);
}
