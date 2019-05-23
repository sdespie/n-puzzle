/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adefonta <adefonta@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 01:52:36 by adefonta          #+#    #+#             */
/*   Updated: 2019/05/23 20:09:56 by adefonta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"

static int	treat_new_state(t_puzzle *puzzle, t_state *new_state)
{
	int	hash_state;

	puzzle->heuristic(puzzle, new_state);
	puzzle->search(new_state);
	hash_state = hash_process(puzzle->map, new_state);
	if (hash_state == ERROR)
		return (error_exit("Error: calloc expand error."));
	if (hash_state == OK)
	{
		if (!sort_newstate(puzzle, new_state))
			return (KO);
		new_state->id = puzzle->nb_state_create++;
	}
	else
	{
		free_state(new_state);
		puzzle->nb_state_del += 1;
	}
	return (OK);
}

static int	test_next_state(t_puzzle *puzzle, t_state *base_state)
{
	int		i;
	int		nb_moves;
	char	next_moves[MAX_MOVES];
	t_state	*new_state;

	i = -1;
	sort_remove(puzzle->sort, base_state);
	puzzle->opened = base_state->next;
	base_state->next = puzzle->closed;
	puzzle->closed = base_state;
	nb_moves = check_nextmoves(base_state, next_moves);
	while (++i < nb_moves)
	{
		if (!(new_state = state_newmove(base_state, next_moves[i])))
			return (error_exit("Error: Malloc error."));
		if (treat_new_state(puzzle, new_state) == KO)
			return (error_exit("Error: Malloc error."));
	}
	return (OK);
}

int			solve(t_puzzle *puzzle)
{
	ft_printf("==== START RESOLVING...\n");
	puzzle->heuristic(puzzle, puzzle->opened);
	puzzle->search(puzzle->opened);
	if (hash_process(puzzle->map, puzzle->opened) != OK)
		return (KO);
	puzzle->opened->id = puzzle->nb_state_create++;
	if (!sort_newstate(puzzle, puzzle->opened))
		return (KO);
	while (19)
	{
		if (!puzzle->opened)
			return (error_exit("Error: Puzzle unsolvable."));
		if (puzzle->opened->h == 0)
			return (OK);
		if (test_next_state(puzzle, puzzle->opened) == KO)
			return (KO);
	}
	return (KO);
}
