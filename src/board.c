/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-spie <sde-spie@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 14:25:50 by sde-spie          #+#    #+#             */
/*   Updated: 2019/04/05 03:49:33 by adefonta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"
#include "macro.h"

static void set_snail(t_puzzle *puzzle)
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
         while (puzzle->goal[(ref + y) *puzzle->board_size + ref + x] == 0)
         {
             puzzle->goal[(ref + y) *puzzle->board_size + ref + x] = current++;
             if (y == 0 && x != size - 1)
                 x++;
             else if (y == size - 1 && x != 0)
                 x--;
             else
                 (x == 0 && y != 0) ? y--: y++;
         }
         size -= 2;
     }
     puzzle->goal[(int)pow(puzzle->board_size, 2) / 2 + (puzzle->board_size + 1) / 2 - 1] = 0;
}

static void randomize(t_state *state)
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
        move == 0 ? up(state) : 0;
        move == 1 ? down(state) : 0;
        move == 2 ? left(state) : 0;
        move == 3 ? right(state) : 0;
    }
}

void board_copy(t_state *state, int *board)
{
    int     i;

    i = -1;
    while (++i < state->board_count)
		state->board[i] = board[i];
}

int		*board_create(int count)
{
	int	*board;

	(DEBUG_HARD) ? ft_printf("board_create::count %d\n", count) : 0;

	if (!(board = (int *)ft_memalloc(sizeof(int) * (count))))
		return (NULL);
	return (board);
}

int		board_init(t_puzzle *puzzle)
{
    int     i;
    int     size;

    size = puzzle->board_size;
	puzzle->board_count = size * size;
	if (!(puzzle->goal = board_create(puzzle->board_count)))
		return (KO);
    printf("\n===== board size = %d =====\n", size);
    set_snail(puzzle);
    if (puzzle->input == 0)
    {
		if (!(puzzle->not_visited = state_create(puzzle->board_count, puzzle->board_size)))
		{
			free_all(puzzle);
			return (KO);
		}
		board_copy(puzzle->not_visited, puzzle->goal);
        randomize(puzzle->not_visited);
    }
	return (OK);
}
