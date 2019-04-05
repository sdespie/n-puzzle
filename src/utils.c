/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-spie <sde-spie@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 14:25:50 by sde-spie          #+#    #+#             */
/*   Updated: 2019/04/05 18:02:50 by adefonta         ###   ########.fr       */
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

void		queue_is_sort(t_state *queue)
{
	int		is_sort;
	int		pre_eval;
	int		count;
	t_state	*tmp;

	is_sort = OK;
	pre_eval = -1;
	count = 0;
	tmp = queue;
	while (tmp)
	{
		count += 1;
		if (pre_eval >= 0 && pre_eval > tmp->eval)
			is_sort = KO;
		pre_eval = tmp->eval;
		tmp = tmp->next;
	}
	if (IS_SORT)
	{
		ft_printf("The queue count %d elem and is", count);
		(is_sort) ? ft_printf(" sort\n") : ft_printf(" not sort!!!\n");
	}
}
