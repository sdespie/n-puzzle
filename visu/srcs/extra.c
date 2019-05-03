/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adefonta <adefonta@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 20:51:05 by adefonta          #+#    #+#             */
/*   Updated: 2019/05/03 16:46:54 by adefonta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "visu.h"

int		coord_to_pos(int x, int y, int width)
{
	return ((int)(x + y * width));
}

char	*strint(char *base, int data)
{
	char	*s_data;

	if (!(s_data = ft_itoa(data)))
		return (NULL);
	return (ft_strjoin_free(base, s_data, 1));
}

void	ft_bzero_double(double *s, size_t n)
{
	while (n--)
		s[n] = 0;
}
