/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adefonta <adefonta@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 01:52:36 by adefonta          #+#    #+#             */
/*   Updated: 2019/04/05 15:56:22 by adefonta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"

static int test_next_visited(t_puzzle *puzzle, t_state *base_state)
{
	int		i;
	int		nb_moves;
	char	next_moves[MAX_MOVES];
	t_state	*new_state;

	(DEBUG_HARD) ? ft_printf("test_next_visited::start::\n") : 0;
	i = -1;
	if (!base_state)
	 	return (KO);
	if (base_state->eval == 0)
		return (OK);
	puzzle->not_visited = base_state->next;
	base_state->next = puzzle->visited;
	puzzle->visited = base_state;
	nb_moves = check_nextmoves(base_state, next_moves);
	while (++i < nb_moves)
	{
		if (!(new_state = state_newmove(base_state, next_moves[i])))
			return (error_exit(puzzle, "Un state a planté.. mechant malloc!"));
		puzzle->heuristic(puzzle, new_state);
		new_state->eval = new_state->h + new_state->g;
		hashing(new_state);
		if (state_is_new(puzzle->not_visited, new_state) && state_is_new(puzzle->visited, new_state))
			puzzle->not_visited = state_insort(puzzle->not_visited, new_state);
		else
			free_state(new_state);
		new_state->id = puzzle->nb_state_create++;
	}
	return (test_next_visited(puzzle, puzzle->not_visited));
}

int			solve(t_puzzle *puzzle)
{
	(DISPLAY) ? ft_printf("solve::start\n") : 0;
	ft_printf("solve::board_init\n");
	print_state(puzzle->not_visited);

	puzzle->heuristic(puzzle, puzzle->not_visited);
	(DISPLAY) ? ft_printf("solve::after-call::heuristic\n") : 0;
	puzzle->not_visited->eval = puzzle->not_visited->h + puzzle->not_visited->g;
	hashing(puzzle->not_visited);
	(DISPLAY) ? ft_printf("solve::after-call::hashing\n") : 0;
	puzzle->not_visited->id = puzzle->nb_state_create++;
	return (test_next_visited(puzzle, puzzle->not_visited));
}
