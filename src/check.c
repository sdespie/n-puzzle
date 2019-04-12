/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-spie <sde-spie@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 14:25:50 by sde-spie          #+#    #+#             */
/*   Updated: 2019/04/12 13:47:45 by adefonta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"

static void set_normalized(t_state *state, int *line, t_puzzle *puzzle)
{
    int     x;
    int     y;
    int     ref;
    int     i;
    int     pos;
    int     size;

	ref = -1;
	i = 0;
    size = puzzle->board_size;
	while (++ref < state->board_size)
	{
		x = 0;
		y = 0;
		while (puzzle->goal[(ref + y) * state->board_size + ref + x] == 0)
		{
			pos = (ref + y) * puzzle->board_size + ref + x;
			line[i] = puzzle->goal[pos];
            ft_printf("line[%d] = %d\n", i, line[i]);
            i++;
			if (y == 0 && x != size - 1)
				x++;
			else if (y == size - 1 && x != 0)
				x--;
			else
				(x == 0 && y != 0) ? y--: y++;
		}
		size -= 2;
	}
}

static int calc_inversion(t_state *state, t_puzzle *puzzle)
{
    int inversion;
    int i;
    int j;
    int *line;

    line = (int*)malloc(sizeof(int) * state->board_count);
    inversion = 0;
    ft_printf("+=+=+=\n");
    set_normalized(state, line, puzzle);
    ft_printf("+=+=+=\n");
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
    return (inversion);
}

int	check_error(t_state *state, t_puzzle *puzzle)
{
    int i;
    int j;
    int size;
    int inversion;

    inversion = calc_inversion(state, puzzle);
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
        ft_printf("\nBoard not valid.\n");
    else
        ft_printf("\nBoard valid.\n");
	return (!(inversion % 2));
}

int	check_nextmoves(t_state *state, char next_moves[MAX_MOVES])
{
	int		nb_moves;
	int		pos;
	int		size;
	int		state_precheck;

	pos = state->zero;
	size = state->board_size;
	nb_moves = 0;
	state_precheck = (state->board_size <= 5 || !state->pre_move);
	// (state->pre_move) ? ft_printf("check_nextmoves %c\n", state->pre_move->move) : 0;
	if (pos < state->board_count - size && (state_precheck||
		state->pre_move->move != DOWN))
		next_moves[nb_moves++] = UP;
	if (pos >= size && (state_precheck || state->pre_move->move != UP))
		next_moves[nb_moves++] = DOWN;
	if ((pos) % size != 0 && (state_precheck ||
		state->pre_move->move != LEFT))
		next_moves[nb_moves++] = RIGHT;
	if ((pos + 1) % size != 0 && (state_precheck ||
		state->pre_move->move != RIGHT))
		next_moves[nb_moves++] = LEFT;
	return (nb_moves);
}

int	check_nextmoves3(t_state *state, char next_moves[MAX_MOVES])
{
	int		nb_moves;
	int		pos;
	int		size;

	pos = state->zero;
	size = state->board_size;
	(state->moves) ? ft_printf("check_nextmoves %c\n", state->moves[state->g - 1]) : 0;
	nb_moves = 0;
	if (pos < state->board_count - size && (!state->moves ||
		state->moves[state->g - 1] != DOWN))
		next_moves[nb_moves++] = UP;
	if (pos >= size && (!state->moves ||
		state->moves[state->g - 1] != UP))
		next_moves[nb_moves++] = DOWN;
	if ((pos) % size != 0 && (!state->moves ||
		state->moves[state->g - 1] != LEFT))
		next_moves[nb_moves++] = RIGHT;
	if ((pos + 1) % size != 0 && (!state->moves ||
		state->moves[state->g - 1] != RIGHT))
		next_moves[nb_moves++] = LEFT;
	return (nb_moves);
}

int	check_valid_start(t_puzzle *puzzle)
{
	if (puzzle->heuristic == NULL)
	{
		ft_printf("Base data not correct\n");
		return (KO);
	}
	if (check_error(puzzle->opened, puzzle) == KO)
	{
		ft_printf("Base Puzzle not correct\n");
		return (KO);
	}
	return (OK);
}
