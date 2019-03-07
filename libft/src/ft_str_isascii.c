/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_isascii.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrouvroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 15:34:54 by nrouvroy          #+#    #+#             */
/*   Updated: 2018/06/21 15:35:19 by nrouvroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_str_isascii(const char *str)
{
	if (!str || !*str)
		return (0);
	while (*str)
		if (!ft_isascii(*str++))
			return (0);
	return (1);
}
