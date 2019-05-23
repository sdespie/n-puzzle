/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-spie <sde-spie@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 19:10:55 by sde-spie          #+#    #+#             */
/*   Updated: 2019/05/22 21:57:53 by adefonta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"

static void	free_puzzle(t_puzzle *puzzle)
{
	ft_memdel((void**)&puzzle->goal);
	ft_memdel((void**)&puzzle->base);
	ft_memdel((void**)&puzzle->data);
	if (puzzle->sort)
		ft_memdel((void**)&puzzle->sort->table);
	ft_memdel((void**)&puzzle->sort);
	if (puzzle->map)
		ft_memdel((void**)&puzzle->map->table);
	ft_memdel((void**)&puzzle->map);
}

static void	free_queue(t_state *queue)
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

void		free_all(t_puzzle *puzzle)
{
	free_queue(puzzle->closed);
	free_queue(puzzle->opened);
	free_puzzle(puzzle);
}
