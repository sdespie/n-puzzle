/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-spie <sde-spie@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 14:25:50 by sde-spie          #+#    #+#             */
/*   Updated: 2019/01/16 16:35:02 by sde-spie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"

/*
** Moves are centered around the 0 pisition. So up is moving a tile up, to 0, ..
*/

void 		up(t_puzzle *puzzle)
{
    int    x;
    int    y;

    x = puzzle->x_zero;
    y = puzzle->y_zero;

    if (puzzle->y_zero != puzzle->board_size - 1)
    {
        puzzle->board[y][x] = puzzle->board[y + 1][x];
        puzzle->board[y + 1][x] = 0;
        puzzle->y_zero++;
    }
}

void 		down(t_puzzle *puzzle)
{
    int    x;
    int    y;

    x = puzzle->x_zero;
    y = puzzle->y_zero;

    if (puzzle->y_zero != 0)
    {
        puzzle->board[y][x] = puzzle->board[y - 1][x];
        puzzle->board[y - 1][x] = 0;
        puzzle->y_zero--;
    }

}

void 		right(t_puzzle *puzzle)
{
    int    x;
    int    y;

    x = puzzle->x_zero;
    y = puzzle->y_zero;

    if (puzzle->x_zero != 0)
    {
        puzzle->board[y][x] = puzzle->board[y][x - 1];
        puzzle->board[y][x - 1] = 0;
        puzzle->x_zero--;
    }
}

void 		left(t_puzzle *puzzle)
{
    int    x;
    int    y;

    x = puzzle->x_zero;
    y = puzzle->y_zero;

    if (puzzle->x_zero != puzzle->board_size - 1)
    {
        puzzle->board[y][x] = puzzle->board[y][x + 1];
        puzzle->board[y][x + 1] = 0;
        puzzle->x_zero++;
    }
}
