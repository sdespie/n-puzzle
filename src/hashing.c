/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-spie <sde-spie@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 14:25:50 by sde-spie          #+#    #+#             */
/*   Updated: 2019/04/01 21:24:23 by adefonta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"

void 	hashing(t_state *state)
{
	int			i;
	long long 	hash;

	hash = 0;
	i = 0;
	while (i++ < state->board_count)
		hash += state->board[i - 1] * pow(i, PR_POW) * PR_MULT;
	state->hash = hash;
}
