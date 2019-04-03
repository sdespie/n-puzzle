/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heuristic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-spie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 19:10:55 by sde-spie          #+#    #+#             */
/*   Updated: 2018/11/30 15:18:23 by sde-spie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"

int		eucl_dist(t_puzzle *puzzle, t_state *state, int i)
{
	int		value;
	int 	j;
	int 	dist;

	dist = 0;
	j = 0;
	value = puzzle->goal[i];
	while (state->board[j] != value)
		j++;
	dist += pow((j % puzzle->board_size) - (i % puzzle->board_size), 2);
	dist += pow((j / puzzle->board_size) - (i / puzzle->board_size), 2);
	return ((int)sqrt(dist));
}

int		man_dist(t_puzzle *puzzle, t_state *state, int i)
{
	int		value;
	int 	j;
	int 	dist;

	dist = 0;
	j = 0;
	value = puzzle->goal[i];
	while (state->board[j] != value)
		j++;
	dist += ABS((j % puzzle->board_size) - (i % puzzle->board_size));
	dist += ABS((j / puzzle->board_size) - (i / puzzle->board_size));
	return (dist);
}

//Manhattan Distance : calc the number of move to do for all the tiles

void 	manhanttan(t_puzzle *puzzle, t_state *state)
{
	int i;

	i = 0;
	state->h = 0;
	while (i < puzzle->board_size)
		state->h += man_dist(puzzle, state, i);
	state->g += 1;
}

//Hamming Distance : calc the number of missplaced tiles

void h(t_puzzle *puzzle, t_state *state)
{
	int		i;

	i = 0;
	state->h = 0;
	while (i < puzzle->board_size)
	{
		if (puzzle->goal[i] != state->board[i])
			state->h += 1;
		i++;
	}
	state->g += 1;
}

// Euclidean

void e(t_puzzle *puzzle, t_state *state)
{
	int i;

	i = 0;
	state->h = 0;
	while (i < puzzle->board_size)
		state->h += eucl_dist(puzzle, state, i);
	state->g += 1;
}
