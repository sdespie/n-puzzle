/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-spie <sde-spie@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 19:10:55 by sde-spie          #+#    #+#             */
/*   Updated: 2019/04/05 03:25:01 by adefonta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"

static void	free_puzzle(t_puzzle *puzzle)
{
	if (puzzle->goal)
		ft_memdel((void**)&puzzle->goal);
	if (puzzle->data)
		ft_memdel((void**)&puzzle->data);

}

static void free_queue(t_state *queue)
{
	t_state	*state;
	t_state	*tmp;

	state = queue;
	while (state)
	{
		free_state(state);
		tmp = state->next;
		free(state);
		state = tmp;
	}
}

void		free_state(t_state *state)
{
	if (state->moves)
		ft_memdel((void**)&state->moves);
	if (state->board)
		ft_memdel((void**)&state->board);
}
void 		free_all(t_puzzle *puzzle)
{
	free_queue(puzzle->visited);
	free_queue(puzzle->not_visited);
	free_puzzle(puzzle);
}
