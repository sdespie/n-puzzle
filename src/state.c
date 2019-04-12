/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adefonta <adefonta@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 19:28:37 by adefonta          #+#    #+#             */
/*   Updated: 2019/04/12 14:46:39 by adefonta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"

t_state		*state_create(int count, int size)
{
	t_state	*state;
	int		x_zero;
	int		y_zero;

	(DEBUG_HARD) ? ft_printf("state_create::start::\n") : 0;
	if (!(state = (t_state *)ft_memalloc(sizeof(t_state))))
		return (NULL);
	if (!(state->board = board_create(count)))
	{
		free(state);
		return (NULL);
	}
	state->board_count = count;
	state->board_size = size;
	x_zero = (size + 1) / 2 - 1;
	y_zero = size / 2;
	state->zero = x_zero + y_zero * size;
	return (state);
}

static int	copy(t_state *base, t_state *dst)
{
	(DEBUG_HARD) ? ft_printf("state::copy::start::\n") : 0;
	board_copy(dst->board, base->board, base->board_count);
	dst->g = base->g;
	dst->zero = base->zero;
	dst->moves_size = base->moves_size;
	(DEBUG_HARD) ? ft_printf("state::copy::end::\n") : 0;
	return (OK);
}

t_state		*state_newmove(t_state *base, char move)
{
	t_state	*new_state;

	(DEBUG_HARD) ? ft_printf("state_newmove::start::\n") : 0;
	new_state = NULL;
	if ((new_state = state_create(base->board_count, base->board_size)))
	{
		if (copy(base, new_state) == KO)
		{
			free_state(new_state);
			return (NULL);
		}
		if (move == UP)
			up(new_state);
		else if (move == DOWN)
			down(new_state);
		else if (move == RIGHT)
			right(new_state);
		else if (move == LEFT)
			left(new_state);
		move_add(base, new_state, move);
	}
	(DEBUG_HARD) ? ft_printf("state_newmove::end::\n") : 0;
	return (new_state);
}

 t_state		*state_insort(t_state *queue, t_state *new_state)
 {
 	t_state	*tmp;
 	t_state	*pre;

	(DEBUG_SORT) ? ft_printf("state_insort::start\n") : 0;
 	new_state->next = NULL;
 	pre = (queue) ? queue->pre : NULL;
 	tmp = queue;
 	while (tmp && tmp->h < new_state->h)
 	{
 		pre = tmp;
 		tmp = tmp->next;
 	}
	new_state->pre = pre;
	if (tmp)
		tmp->pre = new_state;
 	if (pre == NULL)
 	{
 		new_state->next = tmp;
 		return (new_state);
 	}
 	else
 	{
 		pre->next = new_state;
 		new_state->next = tmp;
 	}
	(DEBUG_SORT) ? ft_printf("state_insort::end\n") : 0;
 	return (queue);
 }
