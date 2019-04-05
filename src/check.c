/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-spie <sde-spie@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 14:25:50 by sde-spie          #+#    #+#             */
/*   Updated: 2019/04/05 15:31:30 by adefonta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"

int	check_error(t_state *state)
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
	return (!(inversion % 2));
}

int	check_nextmoves(t_state *state, char next_moves[MAX_MOVES])
{
	int		nb_moves;
	int		pos;
	int		size;

	pos = state->zero;
	size = state->board_size;
	nb_moves = 0;
	if (pos < state->board_count - size)
		next_moves[nb_moves++] = UP;
	if (pos >= size)
		next_moves[nb_moves++] = DOWN;
	if ((pos) % size != 0)
		next_moves[nb_moves++] = RIGHT;
	if ((pos + 1) % size != 0)
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
	return (OK);
}
