/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adefonta <adefonta@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 19:28:37 by adefonta          #+#    #+#             */
/*   Updated: 2019/04/01 21:07:23 by adefonta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"

t_state	*state_create(int count, int size)
{
	t_state	*state;
	int		x_zero;
	int		y_zero;

	if (!(state = (t_state *)ft_memalloc(sizeof(t_state))))
		return (NULL);
	if (!(state->board = board_create(count)))
	{
		free(state);
		return (NULL);
	}
	state->board_count = count;
	state->board_size = size;
	x_zero = (size + 1) / 2 - 1;
	y_zero = size / 2;
	state->zero = x_zero + y_zero * size;
	return (state);
}
