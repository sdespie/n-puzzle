/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-spie <sde-spie@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 14:25:50 by sde-spie          #+#    #+#             */
/*   Updated: 2019/04/08 21:38:36 by adefonta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"
#include "macro.h"

static void set_snail(t_puzzle *puzzle, int *pos)
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
		while (puzzle->goal[(ref + y) * puzzle->board_size + ref + x] == 0)
		{
			*pos = (ref + y) * puzzle->board_size + ref + x;
			puzzle->goal[*pos] = current++;
			if (y == 0 && x != size - 1)
				x++;
			else if (y == size - 1 && x != 0)
				x--;
			else
				(x == 0 && y != 0) ? y--: y++;
		}
		size -= 2;
	}
	puzzle->goal[*pos] = 0;
}

static int	is_ok(t_state *state)
{
	for (int i = 0; i < state->board_count; i++)
	{
		if (state->board[i] == 0 && i != state->zero)
		{
			(DEBUG_HARD_INIT) ? ft_printf("board::is_ok::fail\n") : 0;
			return (KO);
		}
	}
	(DEBUG_HARD_INIT) ? ft_printf("board::is_ok::succeed\n") : 0;
	return (OK);
}

static void randomize(t_state *state)
{
    int     nbr_move;
    int     move;
    time_t  t;

	(DEBUG_HARD_INIT) ? ft_printf("\n=== randomize === \n") : 0;
    srand((unsigned) time(&t));
    nbr_move = rand() % 2000;
	(DEBUG_HARD_INIT) ? print_state(state) : 0;
    ft_printf("\nnbr move = %d\n", nbr_move);
    while (nbr_move--)
    {
        move = rand() % 4;
        move == 0 ? up(state) : 0;
        move == 1 ? down(state) : 0;
        move == 2 ? left(state) : 0;
        move == 3 ? right(state) : 0;
		(DEBUG_HARD_INIT) ? ft_printf("Move is : %d\n", move) : 0;
		(DEBUG_HARD_INIT) ? print_state(state) : 0;
		if (is_ok(state) != OK)
			break ;
    }
}

void board_copy(int *dst, int *src, int count)
{
    int     i;

    i = -1;
    while (++i < count)
		dst[i] = src[i];
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
	int		zero;

    size = puzzle->board_size;
	puzzle->board_count = size * size;
	if (!(puzzle->goal = board_create(puzzle->board_count)))
		return (KO);
	if (!(puzzle->base = board_create(puzzle->board_count)))
		return (KO);
    printf("\n===== board size = %d =====\n", size);
    set_snail(puzzle, &zero);
	print_board(puzzle->goal, puzzle->board_count, puzzle->board_size);
    if (puzzle->input == 0)
    {
		if (!(puzzle->not_visited = state_create(puzzle->board_count, puzzle->board_size)))
		{
			free_all(puzzle);
			return (KO);
		}
		puzzle->not_visited->zero = zero;
		board_copy(puzzle->not_visited->board, puzzle->goal, puzzle->board_count);
        randomize(puzzle->not_visited);
		board_copy(puzzle->base, puzzle->not_visited->board, puzzle->board_count);
		puzzle->zero_base = puzzle->not_visited->zero;

    }
	return (OK);
}
