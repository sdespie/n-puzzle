/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_isupper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrouvroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 15:36:53 by nrouvroy          #+#    #+#             */
/*   Updated: 2018/06/21 15:37:45 by nrouvroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_str_isupper(const char *str)
{
	if (!str || !*str)
		return (0);
	while (*str)
		if (!ft_isupper(*str++))
			return (0);
	return (1);
}
