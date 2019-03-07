/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrouvroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 16:12:58 by nrouvroy          #+#    #+#             */
/*   Updated: 2018/06/21 16:21:05 by nrouvroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long int	ft_pow(int n, int exp)
{
	long long int res;

	if (exp == 0)
		return (1);
	if (exp % 2 == 0)
	{
		res = ft_pow(n, exp / 2);
		return (res * res);
	}
	else
	{
		return (n * ft_pow(n, exp - 1));
	}
}
