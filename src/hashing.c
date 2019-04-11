/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-spie <sde-spie@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 14:25:50 by sde-spie          #+#    #+#             */
/*   Updated: 2019/04/11 20:03:14 by adefonta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"

void 	hashing2(t_state *state)
{
	int			i;
	long long 	hash;

	hash = 0;
	i = 0;
	while (i++ < state->board_count)
		hash += state->board[i - 1] * pow(i, PR_POW) * PR_MULT;
	state->hash = hash;
}

uint64_t hash_unit64(uint64_t x)
{
    x = (x ^ (x >> 30)) * UINT64_C(0xbf58476d1ce4e5b9);
    x = (x ^ (x >> 27)) * UINT64_C(0x94d049bb133111eb);
    x = x ^ (x >> 31);
    return (x);
}

void	hashing3(t_state *state)
{
	int			i;
	uint64_t	hash;

	i = -1;
	hash = 1381;
	while (++i < state->board_count)
		hash = (hash * 33) + state->board[i] - '0';
	(DEBUG_HASH) ? ft_printf("%llu\n", hash) : 0;
	state->hash = hash;
}

void	hashing(t_state *state)
{
	int			i;
	uint64_t	hash;
	uint64_t	hash_local;

	i = -1;
	hash = 0;
	while (++i < state->board_count) //33
	{
		hash_local = hash_unit64((uint64_t)state->board[i]);
		hash += hash_local * (i + 1) + (uint64_t)(state->board[i] + 1) * state->h;
	}
	(DEBUG_HASH) ? ft_printf("%llu\n", hash) : 0;
	state->hash = hash;
}
