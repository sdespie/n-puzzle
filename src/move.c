/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-spie <sde-spie@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 14:25:50 by sde-spie          #+#    #+#             */
/*   Updated: 2019/05/18 18:34:35 by adefonta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"

/*
** Moves are centered around the 0 pisition. So up is moving a tile up, to 0, ..
*/

void	up(t_state *state)
{
	int	pos;
	int	size;

	pos = state->zero;
	size = state->board_size;
	if (pos < state->board_count - size)
	{
		state->board[pos] = state->board[pos + size];
		state->board[pos + size] = 0;
		state->zero = pos + size;
	}
}

void	down(t_state *state)
{
	int	pos;
	int	size;

	pos = state->zero;
	size = state->board_size;
	if (pos >= size)
	{
		state->board[pos] = state->board[pos - size];
		state->board[pos - size] = 0;
		state->zero = pos - size;
	}
}

void	right(t_state *state)
{
	int		pos;
	int		size;

	pos = state->zero;
	size = state->board_size;
	if ((pos) % size != 0)
	{
		state->board[pos] = state->board[pos - 1];
		state->board[pos - 1] = 0;
		state->zero = pos - 1;
	}
}

void	left(t_state *state)
{
	int		pos;
	int		size;

	pos = state->zero;
	size = state->board_size;
	if ((pos + 1) % size != 0)
	{
		state->board[pos] = state->board[pos + 1];
		state->board[pos + 1] = 0;
		state->zero = pos + 1;
	}
}

int		move_add(t_state *pre_move, t_state *state, char move)
{
	state->g += 1;
	state->pre_move = pre_move;
	state->move = move;
	return (OK);
}
