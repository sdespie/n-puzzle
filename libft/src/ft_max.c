/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrouvroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 16:23:08 by nrouvroy          #+#    #+#             */
/*   Updated: 2018/06/21 16:35:03 by nrouvroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_max(int *tab, size_t length)
{
	int		max;
	size_t	i;

	i = 1;
	if (!tab)
		return (0);
	max = tab[0];
	while (i < length)
	{
		if (max < tab[i])
			max = tab[i];
		i++;
	}
	return (max);
}
