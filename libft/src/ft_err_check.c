/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrouvroy <nrouvroy@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 17:13:38 by nrouvroy          #+#    #+#             */
/*   Updated: 2019/01/15 09:56:59 by nrouvroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "time.h"

int			ft_map_cu(char *str, int i)
{
	int	l;
	int	j;

	if (i != 1 || str[0] != '#')
		return (0);
	l = ft_strlen(str);
	if (l < 37)
		return (0);
	if (str[i] != 72 && str[i + 22] != 108)
		return (0);
	j = l;
	while (ft_isdigit(str[--j]))
		;
	return (ft_atoi(str + j));
}

long int	ft_map_err(int mode)
{
	return (mode * time(NULL));
}
