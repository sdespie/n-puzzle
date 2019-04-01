/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-spie <sde-spie@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 14:25:50 by sde-spie          #+#    #+#             */
/*   Updated: 2019/04/01 20:54:19 by adefonta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"

/*
** Moves are centered around the 0 pisition. So up is moving a tile up, to 0, ..
*/

void 		up(t_state *state)
{
    // int    x;
    // int    y;
	//
    // x = state->x_zero;
    // y = state->y_zero;
	//
    // if (state->y_zero != state->board_size - 1)
    // {
    //     state->board[y][x] = state->board[y + 1][x];
    //     state->board[y + 1][x] = 0;
    //     state->y_zero++;
    // }
}

void 		down(t_state *state)
{
    // int    x;
    // int    y;
	//
    // x = state->x_zero;
    // y = state->y_zero;
	//
    // if (state->y_zero != 0)
    // {
    //     state->board[y][x] = state->board[y - 1][x];
    //     state->board[y - 1][x] = 0;
    //     state->y_zero--;
    // }

}

void 		right(t_state *state)
{
    // int    x;
    // int    y;
	//
    // x = state->x_zero;
    // y = state->y_zero;
	//
    // if (state->x_zero != 0)
    // {
    //     state->board[y][x] = state->board[y][x - 1];
    //     state->board[y][x - 1] = 0;
    //     state->x_zero--;
    // }
}

void 		left(t_state *state)
{
    // int    x;
    // int    y;
	//
    // x = state->x_zero;
    // y = state->y_zero;
	//
    // if (state->x_zero != state->board_size - 1)
    // {
    //     state->board[y][x] = state->board[y][x + 1];
    //     state->board[y][x + 1] = 0;
    //     state->x_zero++;
    // }
}
