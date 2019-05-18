/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adefonta <adefonta@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 15:58:15 by adefonta          #+#    #+#             */
/*   Updated: 2019/05/18 20:14:10 by adefonta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"
#include "macro.h"

static int	is_ok(t_state *state)
{
	int i;

	i = -1;
	while (++i < state->board_count)
	{
		if (state->board[i] == 0 && i != state->zero)
			return (KO);
	}
	return (OK);
}

void		randomize(t_state *state)
{
	int		nbr_move;
	int		move;
	time_t	t;

	srand((unsigned)time(&t));
	nbr_move = rand() % 200000;
	ft_printf("\nnbr move = %d\n", nbr_move);
	while (nbr_move--)
	{
		move = rand() % 4;
		move == 0 ? up(state) : 0;
		move == 1 ? down(state) : 0;
		move == 2 ? left(state) : 0;
		move == 3 ? right(state) : 0;
		if (is_ok(state) != OK)
			break ;
	}
}
