/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adefonta <adefonta@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 19:22:15 by adefonta          #+#    #+#             */
/*   Updated: 2019/04/05 03:23:21 by adefonta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"

void print_usage(t_puzzle *puzzle)
{
    ft_printf("Usage : n-puzzle [file / size] [-m -... -...]");
    free_all(puzzle);
}

void print_board(t_state *state)
{
    int i;
    int j;

    printf("++++++++ BOARD ++++++\n");
    i = 0;
    while (i < state->board_count)
    {
        printf("% .2d", state->board[i++]);
		if ((i % state->board_size) == 0)
        	printf("\n");
    }
}

void	print_state(t_state *state)
{
	ft_printf("########## STATE -- id: %d\n", state->id);
	ft_printf("eval : %-10d\n", state->eval);
	ft_printf("g    : %-10d\n", state->g);
	ft_printf("h    : %-10d\n", state->h);
	ft_printf("moves:\n%s\n", state->moves);
	print_board(state);
}
