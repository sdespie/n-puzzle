/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adefonta <adefonta@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 19:28:37 by adefonta          #+#    #+#             */
/*   Updated: 2019/04/05 03:45:00 by adefonta         ###   ########.fr       */
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
	board_copy(dst, base->board);
	dst->g = base->g;
	dst->x_zero = base->x_zero;
	dst->y_zero = base->y_zero;
	dst->zero = base->zero;
	dst->moves_size = base->moves_size;
	if (!(dst->moves = move_newcopy(base->moves, base->moves_size)))
		return (KO);
	return (OK);
}

t_state		*state_newmove(t_state *base, char move)
{
	t_state	*new_state;

	(DEBUG_HARD) ? ft_printf("state_newmove::start::\n") : 0;
	new_state = NULL;
	if (!(new_state = state_create(base->board_count, base->board_size)))
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
		move_add(new_state, move);
	}
	return (new_state);
}

t_state		*state_insort(t_state *queue, t_state *new_state)
{
	t_state	*tmp;
	t_state	*pre;

	new_state->next = NULL;
	pre = NULL;
	tmp = queue;
	while (tmp && tmp->eval <= new_state->eval)
	{
		pre = tmp;
		tmp = tmp->next;
	}
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

int			state_is_new(t_state *queue, t_state *new_state)
{
	int		i;
	int		state;
	t_state	*tmp;

	tmp = queue;
	state = OK;
	while (tmp && state == OK)
	{
		if (tmp->h == new_state->h && tmp->hash == new_state->hash)
		{
			i = -1;
			state = KO;
			while (state == KO && ++i < new_state->board_count)
			{
				if (tmp->board[i] != new_state->board[i])
					state = OK;
			}
		}
		tmp = tmp->next;
	}
	return (state);
}
