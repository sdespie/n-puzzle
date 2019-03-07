/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_board.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-spie <sde-spie@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 14:25:50 by sde-spie          #+#    #+#             */
/*   Updated: 2019/01/16 16:35:02 by sde-spie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"

void set_snail(t_puzzle *puzzle)
{
    int     x;
    int     y;
    int     current;
    int     size;
    int     ref;

    size = puzzle->board_size;
    ref = -1;
    current = 1;
    while (++ref < puzzle->board_size)
    {
        x = 0;
        y = 0;
        while (puzzle->goal[ref + y][ref + x] == 0)
        {
            puzzle->goal[ref + y][ref + x] = current++;
            if (y == 0 && x != size - 1)
                x++;
            else if (y == size - 1 && x != 0)
                x--;
            else
                (x == 0 && y != 0) ? y--: y++;
        }
        size -= 2;
    }
    puzzle->goal[puzzle->board_size / 2 ][(puzzle->board_size + 1) / 2 - 1] = 0;
}

void randomize(t_puzzle *puzzle)
{
    int     nbr_move;
    int     move;
    time_t  t;

    srand((unsigned) time(&t));
    nbr_move = rand() % 2000000;
    printf("\nnbr move = %d\n", nbr_move);
    while (nbr_move--)
    {
        move = rand() % 4;
        move == 0 ? up(puzzle) : 0;
        move == 1 ? down(puzzle) : 0;
        move == 2 ? left(puzzle) : 0;
        move == 3 ? right(puzzle) : 0;
    }
}

void copy_board(t_puzzle *puzzle)
{
    int     i;
    int     j;

    i = 0;
    while (i < puzzle->board_size)
    {
        j = 0;
        while (j < puzzle->board_size)
        {
            puzzle->board[i][j] = puzzle->goal[i][j];
            j++;
        }
        i++;
    }

}

void init_board(t_puzzle *puzzle)
{
    int     i;
    int     size;

    size = puzzle->board_size;
    i = 0;
    puzzle->board = (int**)malloc(size * sizeof(int*));
    puzzle->goal = (int**)malloc(size * sizeof(int*));
    while (i < puzzle->board_size)
    {
        puzzle->board[i] = (int*)malloc(size * sizeof(int));
        puzzle->goal[i] = (int*)malloc(size * sizeof(int));
        ft_bzero(puzzle->goal[i], sizeof(int) * size);
        ft_bzero(puzzle->board[i], sizeof(int) * size);
        i++;
    }
    printf("\n=====\nboard size = %d\n====\n", size);

    set_snail(puzzle);
    if (puzzle->input == 0)
    {
        copy_board(puzzle);
        puzzle->x_zero = (puzzle->board_size + 1) / 2 - 1;
        puzzle->y_zero = puzzle->board_size / 2;
        randomize(puzzle);
    }
}
