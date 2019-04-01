/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adefonta <adefonta@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 19:22:15 by adefonta          #+#    #+#             */
/*   Updated: 2019/04/01 21:07:58 by adefonta         ###   ########.fr       */
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

    printf("\n++++++++ BOARD ++++++\n");
    i = 0;
    while (i < state->board_count)
    {
        printf("% .2d", state->board[i++]);
		if ((i % state->board_size) == 0)
        	printf("\n");
    }
}
