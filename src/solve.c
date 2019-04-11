/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adefonta <adefonta@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 01:52:36 by adefonta          #+#    #+#             */
/*   Updated: 2019/04/11 23:16:47 by adefonta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"

static int	treat_new_state(t_puzzle *puzzle, t_state *new_state)
{
	int	hash_state;

	puzzle->heuristic(puzzle, new_state);
	new_state->eval = new_state->h + new_state->g;
	hash_state = hash_process(puzzle->map, new_state);
	if (hash_state == ERROR)
		return (KO);
	// if (state_is_new(puzzle->opened, new_state) && state_is_new(puzzle->closed, new_state))
	if (hash_state == OK)
	{
		// puzzle->opened = state_insort(puzzle->opened, new_state);
		if (!sort_newstate(puzzle, new_state))
			return (KO);
		// queue_is_sort(puzzle->opened);
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

	if ((DISPLAY_STATE_INFO) && ((puzzle->nb_state_create % 100) == 0 ||
						(puzzle->nb_state_del % 100) == 0))
		ft_printf("test_next_closed:: h: %10d::nb_state:-create: %10d :-del: %10d\n", base_state->h, puzzle->nb_state_create, puzzle->nb_state_del);
	i = -1;
	// ft_printf("\n\n\n###########STARTs\n");
	// print_sort(puzzle->sort);
	// print_queue(puzzle->opened);
	sort_remove(puzzle->sort, base_state);
	// print_sort(puzzle->sort);
	// print_queue(puzzle->opened);
	// ft_printf("############END\n");
	puzzle->opened = base_state->next;
	base_state->next = puzzle->closed;
	puzzle->closed = base_state;
	nb_moves = check_nextmoves(base_state, next_moves);
	while (++i < nb_moves)
	{
		if (!(new_state = state_newmove(base_state, next_moves[i])))
			return (error_exit(puzzle, "Un state a planté.. mechant malloc!"));
		if (treat_new_state(puzzle, new_state) == KO)
			return (KO);
	}
	return (OK);
}

int			solve(t_puzzle *puzzle)
{
	print_state(puzzle->opened);
	ft_printf("====\n");
	puzzle->heuristic(puzzle, puzzle->opened);
	puzzle->opened->eval = puzzle->opened->h + puzzle->opened->g;
	if (hash_process(puzzle->map, puzzle->opened) != OK)
		return (KO);
	puzzle->opened->id = puzzle->nb_state_create++;
	if (!sort_newstate(puzzle, puzzle->opened))
		return (KO);
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
