/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heuristic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-spie <sde-spie@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 19:10:55 by sde-spie          #+#    #+#             */
/*   Updated: 2019/04/12 03:11:04 by adefonta         ###   ########.fr       */
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
	//ft_printf("+++ NEW +++\n");
	while (state->board[j] != value)
		j++;
	//ft_printf("i = %d, value = %d, j = %d\n", i, value, j);
	dist += ft_abs((j % puzzle->board_size) - (i % puzzle->board_size));
	dist += ft_abs((j / puzzle->board_size) - (i / puzzle->board_size));
	return (dist);
}

//Manhattan Distance : calc the number of move to do for all the tiles

void 	manhanttan(t_puzzle *puzzle, t_state *state)
{
	int i;

	i = -1;
	state->h = 0;
	while (++i < puzzle->board_count)
		state->h += man_dist(puzzle, state, i);
}

//Hamming Distance : calc the number of missplaced tiles

void h(t_puzzle *puzzle, t_state *state)
{
	int		i;

	i = 0;
	state->h = 0;
	while (i < puzzle->board_count)
	{
		if (puzzle->goal[i] != state->board[i])
			state->h += 1;
		i++;
	}
}

// Euclidean

void e(t_puzzle *puzzle, t_state *state)
{
	int i;

	i = 0;
	state->h = 0;
	while (i < puzzle->board_count)
		state->h += eucl_dist(puzzle, state, i);
}
