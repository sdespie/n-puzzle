/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adefonta <adefonta@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 01:52:36 by adefonta          #+#    #+#             */
/*   Updated: 2019/04/11 17:49:41 by adefonta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"

static int	test_next_state(t_puzzle *puzzle, t_state *base_state)
{
	int		i;
	int		nb_moves;
	char	next_moves[MAX_MOVES];
	t_state	*new_state;

	(DEBUG_HARD) ? ft_printf("test_next_closed::start::\n") : 0;
	if ((DISPLAY_STATE_INFO) && ((puzzle->nb_state_create % 100) == 0 ||
						(puzzle->nb_state_del % 100) == 0))
		ft_printf("test_next_closed:: h: %10d::nb_state:-create: %10d :-del: %10d\n", base_state->h, puzzle->nb_state_create, puzzle->nb_state_del);
	i = -1;
	puzzle->opened = base_state->next;
	base_state->next = puzzle->closed;
	puzzle->closed = base_state;
	nb_moves = check_nextmoves(base_state, next_moves);
	while (++i < nb_moves)
	{
		if (!(new_state = state_newmove(base_state, next_moves[i])))
			return (error_exit(puzzle, "Un state a planté.. mechant malloc!"));
		puzzle->heuristic(puzzle, new_state);
		new_state->eval = new_state->h + new_state->g;
		if (hash_process(puzzle->map, new_state) == KO)
			return (KO);
		// if (state_is_new(puzzle->opened, new_state) && state_is_new(puzzle->closed, new_state))
		if (!hash_contains(puzzle->map, new_state))
		{
			puzzle->opened = state_insort(puzzle->opened, new_state);
			// queue_is_sort(puzzle->opened);
			new_state->id = puzzle->nb_state_create++;
		}
		else
		{
			free_state(new_state);
			puzzle->nb_state_del += 1;
		}
	}
	return (OK);
}

int			solve(t_puzzle *puzzle)
{
	(DISPLAY) ? ft_printf("solve::start\n") : 0;
	print_state(puzzle->opened);
	printf("====\n");
	puzzle->heuristic(puzzle, puzzle->opened);
	puzzle->opened->eval = puzzle->opened->h + puzzle->opened->g;
	if (hash_process(puzzle->map, puzzle->opened) == KO)
		return (KO);
	puzzle->opened->id = puzzle->nb_state_create++;
	while (19)
	{
		if (!puzzle->opened)
		 	return (KO);
		if (puzzle->opened->h == 0)
			return (OK);
		if (test_next_state(puzzle, puzzle->opened) == KO)
			return (KO);
	}
	return (KO);
}
