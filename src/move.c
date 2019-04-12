/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-spie <sde-spie@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 14:25:50 by sde-spie          #+#    #+#             */
/*   Updated: 2019/04/12 13:37:08 by adefonta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"

/*
** Moves are centered around the 0 pisition. So up is moving a tile up, to 0, ..
*/

void 		up(t_state *state)
{
    int		pos;
	int		size;

	pos = state->zero;
	size = state->board_size;
	if (pos < state->board_count - size)
 	{
    	state->board[pos] = state->board[pos + size];
		state->board[pos + size] = 0;
    	state->zero = pos + size;
    }
}

void 		down(t_state *state)
{
	int		pos;
	int		size;

	pos = state->zero;
	size = state->board_size;
	if (pos >= size)
	{
		state->board[pos] = state->board[pos - size];
		state->board[pos - size] = 0;
		state->zero = pos - size;
    }
}

void 		right(t_state *state)
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

void 		left(t_state *state)
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

char		*move_newcopy(char *src, int old_size, int new_size)
{
	char *new_moves;

	if (!(new_moves = (char *)calloc(sizeof(char), new_size)))
		return (NULL);
	ft_strncpy(new_moves, src, old_size);
	return (new_moves);
}

static char	*expand(char *src, int new_size)
{
	char *new_moves;
	if (src == NULL)
	{
		if (!(new_moves = (char *)calloc(sizeof(char), new_size)))
			return (NULL);
	}
	else
	{
		if (!(new_moves = (char *)realloc(src, sizeof(char) * new_size)))
			return (NULL);
	}
	// ft_strncpy(new_moves, src, new_size);
	return (new_moves);
}

int			move_add(t_state *pre_move, t_state *state, char move)
{
	int		new_size;
	char	*new_moves;

	new_size = 0;
	state->g += 1;
	state->pre_move = pre_move;
	state->move = move;
	// if (state->moves_size <= state->g)
	// {
	// 	new_size = state->moves_size + NBR_MOVES_ADD;
	// 	if (!(state->moves = expand(state->moves, new_size)))
	// 		return (KO);
	// 	state->moves_size = new_size;
	// 	// free(state->moves);
	// 	// state->moves = new_moves;
	//
	// }
	// state->moves[state->g - 1] = move;

	return (OK);
}
