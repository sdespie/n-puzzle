/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-spie <sde-spie@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 19:10:55 by sde-spie          #+#    #+#             */
/*   Updated: 2019/04/12 14:46:14 by adefonta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"

static void	free_puzzle(t_puzzle *puzzle)
{
	if (puzzle->goal)
		ft_memdel((void**)&puzzle->goal);
	if (puzzle->data)
		ft_memdel((void**)&puzzle->data);
	if (puzzle->sort->table)
		ft_memdel((void**)&puzzle->sort->table);
	if (puzzle->sort)
		ft_memdel((void**)&puzzle->sort);
}

static void free_queue(t_state *queue)
{
	t_state	*state;
	t_state	*tmp;

	state = queue;
	while (state)
	{
		tmp = state->next;
		free_state(state);
		state = tmp;
	}
}

void		free_state(t_state *state)
{
	if (state->board)
		ft_memdel((void**)&state->board);
	free(state);
}

void 		free_all(t_puzzle *puzzle)
{
	free_queue(puzzle->closed);
	free_queue(puzzle->opened);
	free_puzzle(puzzle);
}
