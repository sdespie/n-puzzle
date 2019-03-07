/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrouvroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 16:23:08 by nrouvroy          #+#    #+#             */
/*   Updated: 2018/06/21 16:35:21 by nrouvroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_min(int *tab, size_t length)
{
	int		min;
	size_t	i;

	i = 1;
	if (!tab)
		return (0);
	min = tab[0];
	while (i < length)
	{
		if (min > tab[i])
			min = tab[i];
		i++;
	}
	return (min);
}
