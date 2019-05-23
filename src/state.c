/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adefonta <adefonta@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 19:28:37 by adefonta          #+#    #+#             */
/*   Updated: 2019/05/21 19:57:43 by adefonta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"

t_state		*state_create(int count, int size)
{
	t_state	*state;
	int		x_zero;
	int		y_zero;

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
	board_copy(dst->board, base->board, base->board_count);
	dst->g = base->g;
	dst->eval = base->eval;
	dst->zero = base->zero;
	return (OK);
}

t_state		*state_newmove(t_state *base, char move)
{
	t_state	*new_state;

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
	return (new_state);
}

t_state		*state_insort(t_state *queue, t_state *new_state)
{
	t_state	*tmp;
	t_state	*pre;

	new_state->next = NULL;
	pre = (queue) ? queue->pre : NULL;
	tmp = queue;
	while (tmp && tmp->eval < new_state->eval)
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
	return (queue);
}
