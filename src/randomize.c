/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adefonta <adefonta@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 15:58:15 by adefonta          #+#    #+#             */
/*   Updated: 2019/05/23 20:04:49 by adefonta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"
#include "macro.h"

static int	create_random(int *nbr, t_state *state)
{
	int		i;
	int		j;
	time_t	t;

	srand((unsigned)time(&t));
	i = -1;
	while (++i < state->board_count)
		nbr[i] = 0;
	i = -1;
	while (++i < state->board_count)
		while (19)
		{
			j = rand() % (state->board_count);
			if (nbr[j] == 0)
			{
				state->board[j] = i;
				if (i == 0)
					state->zero = j;
				nbr[j] = 1;
				break ;
			}
		}
	return (OK);
}

int			randomize(t_state *state, int *goal)
{
	int		*nbr;

	if (!(nbr = (int *)malloc(state->board_count * sizeof(int))))
		return (error_exit("Error malloc failed"));
	while (19)
	{
		if (create_random(nbr, state) == KO)
			return (KO);
		if (check_error(state, goal) == OK)
			break ;
	}
	free(nbr);
	return (OK);
}
