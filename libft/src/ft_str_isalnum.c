/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_isalnum.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrouvroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 15:16:31 by nrouvroy          #+#    #+#             */
/*   Updated: 2018/06/21 15:47:05 by nrouvroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_str_isalnum(const char *str)
{
	if (!str || !*str)
		return (0);
	while (*str)
		if (!ft_isalnum(*str++))
			return (0);
	return (1);
}
