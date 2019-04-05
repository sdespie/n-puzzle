/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-spie <sde-spie@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 14:25:50 by sde-spie          #+#    #+#             */
/*   Updated: 2019/04/05 16:02:08 by adefonta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"

int     is_valid_number(t_puzzle *puzzle, char *number)
{
    puzzle->error_p = 0;
    puzzle->error_sign = 0;
    if (ft_atoi2(number, puzzle) == ft_atol2(number, puzzle)\
        && ft_atoi2(number, puzzle) > 0 && !puzzle->error_p\
        && puzzle->error_sign < 2)
        return (1);
    else
        return (0);
}

int		ft_abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}
