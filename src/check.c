/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-spie <sde-spie@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 14:25:50 by sde-spie          #+#    #+#             */
/*   Updated: 2019/05/18 21:19:19 by adefonta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"

static int	get_index(int *list, int value)
{
	int i;

	i = 0;
	while (list[i] != value)
		i++;
	return (i);
}

static int	calc_inversion(t_puzzle *p)
{
	int	*done;
	int	ipuzzle;
	int igoal;
	int nb_inv;

	done = (int*)malloc(sizeof(int) * p->board_count);
	nb_inv = 0;
	ft_memset(done, 0, (size_t)(sizeof(int) * p->board_count));
	igoal = -1;
	while (++igoal < p->board_count)
	{
		ipuzzle = -1;
		while (++ipuzzle < get_index(p->opened->board, p->goal[igoal]))
			if (done[p->opened->board[ipuzzle]] == 0)
				nb_inv++;
		done[p->goal[igoal]] = 1;
	}
	return (nb_inv);
}

int			check_error(t_puzzle *puzzle)
{
	int n_inv;
	int dist;
	int i;

	i = -1;
	dist = 0;
	n_inv = calc_inversion(puzzle);
	while (++i < puzzle->board_count)
		dist += man_dist(puzzle, puzzle->opened, i);
	if ((dist % 2 == 0 && n_inv % 2 == 0) || (dist % 2 != 0 && n_inv % 2 != 0))
		return (OK);
	return (KO);
}

int			check_nextmoves(t_state *state, char next_moves[MAX_MOVES])
{
	int		nb_moves;
	int		pos;
	int		size;
	int		state_precheck;

	pos = state->zero;
	size = state->board_size;
	nb_moves = 0;
	state_precheck = (state->board_size <= 5 || !state->pre_move);
	if (pos < state->board_count - size && (state_precheck ||
		state->pre_move->move != DOWN))
		next_moves[nb_moves++] = UP;
	if (pos >= size && (state_precheck || state->pre_move->move != UP))
		next_moves[nb_moves++] = DOWN;
	if ((pos) % size != 0 && (state_precheck ||
		state->pre_move->move != LEFT))
		next_moves[nb_moves++] = RIGHT;
	if ((pos + 1) % size != 0 && (state_precheck ||
		state->pre_move->move != RIGHT))
		next_moves[nb_moves++] = LEFT;
	return (nb_moves);
}

int			check_valid_start(t_puzzle *puzzle)
{
	if (puzzle->heuristic == NULL || puzzle->search == NULL)
	{
		ft_printf("NO HEURISTIC OR SEARCH\n");
		return (KO);
	}
	if (multiple(puzzle->opened) == KO || check_error(puzzle) == KO)
	{
		ft_printf("PUZZLE NOT VALID\n");
		return (KO);
	}
	return (OK);
}
