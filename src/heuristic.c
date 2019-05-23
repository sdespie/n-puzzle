/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heuristic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-spie <sde-spie@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 19:10:55 by sde-spie          #+#    #+#             */
/*   Updated: 2019/05/22 22:52:05 by adefonta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"

int		eucl_dist(t_puzzle *puzzle, t_state *state, int i)
{
	int	value;
	int	j;
	int	dist;

	dist = 0;
	j = 0;
	value = puzzle->goal[i];
	while (state->board[j] != value)
		j++;
	dist += pow((j % puzzle->board_size) - (i % puzzle->board_size), 2);
	dist += pow((j / puzzle->board_size) - (i / puzzle->board_size), 2);
	return ((int)sqrt(dist));
}

int		man_dist(t_state *state, int *goal, int i)
{
	int	value;
	int	j;
	int	dist;

	dist = 0;
	j = 0;
	value = goal[i];
	while (state->board[j] != value)
		j++;
	dist += ft_abs((j % state->board_size) - (i % state->board_size));
	dist += ft_abs((j / state->board_size) - (i / state->board_size));
	return (dist);
}

void	manhanttan(t_puzzle *puzzle, t_state *state)
{
	int i;

	i = -1;
	state->h = 0;
	while (++i < puzzle->board_count)
		state->h += man_dist(state, puzzle->goal, i);
}

void	h(t_puzzle *puzzle, t_state *state)
{
	int		i;

	i = -1;
	state->h = 0;
	while (++i < puzzle->board_count)
		if (puzzle->goal[i] != state->board[i])
			state->h += 1;
}

void	e(t_puzzle *puzzle, t_state *state)
{
	int i;

	i = -1;
	state->h = 0;
	while (++i < puzzle->board_count)
		state->h += eucl_dist(puzzle, state, i);
}
