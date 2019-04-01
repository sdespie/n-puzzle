/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-spie <sde-spie@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 14:25:50 by sde-spie          #+#    #+#             */
/*   Updated: 2019/04/01 20:58:55 by adefonta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"

void check_error(t_state *state)
{
    int i;
    int j;
    int size;
    int inversion;

    inversion = 0;
    i = -1;
    while (++i < state->board_count)
    {
        j = i + 1;
        while (j < state->board_count)
        {
            if (state->board[i] > state->board[j++])
                inversion++;
        }
    }
    if (inversion % 2)
        printf("\nBoard not valid.\n");
    else
        printf("\nBoard valid.\n");

}
