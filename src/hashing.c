/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-spie <sde-spie@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 14:25:50 by sde-spie          #+#    #+#             */
/*   Updated: 2019/05/09 16:56:15 by adefonta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"

void 	hashing0(t_state *state)
{
	int			i;
	long long 	hash;

	hash = 0;
	i = 0;
	while (i++ < state->board_count)
		hash += state->board[i - 1] * pow(i, PR_POW) * PR_MULT;
	state->hash = hash;
}

uint64_t hash_unit64_2(uint64_t x)
{
    x = (x ^ (x >> 30)) * UINT64_C(0xbf58476d1ce4e5b9);
    x = (x ^ (x >> 27)) * UINT64_C(0x94d049bb133111eb);
    x = x ^ (x >> 31);
    return (x);
}

uint64_t hash_unit64_1(uint64_t key)
{
  key = (~key) + (key << 21); // key = (key << 21) - key - 1;
  key = key ^ (key >> 24);
  key = (key + (key << 3)) + (key << 8); // key * 265
  key = key ^ (key >> 14);
  key = (key + (key << 2)) + (key << 4); // key * 21
  key = key ^ (key >> 28);
  key = key + (key << 31);
  return key;
}

uint64_t hash_unit64_3(uint64_t key)
{
	key += (key << 12);
	key ^= (key >> 22);
	key += (key << 4);
	key ^= (key >> 9);
	key += (key << 10);
	key ^= (key >> 2);
	key += (key << 7);
	key ^= (key >> 12);
	key = (key >> 3) * 2654435761;
	return key;
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

void	hashing4(t_state *state)
{
	int			i;
	uint64_t	hash;

	i = -1;
	hash = 7;
	while (++i < state->board_count)
		hash = ((hash << 5) + hash) + (char)(state->board[i]);
		// hash = hash * 31 + (char)(state->board[i]);
	(DEBUG_HASH) ? ft_printf("%llu\n", hash) : 0;
	state->hash = hash;
}

uint64_t	hashing2(t_state *state)
{
	int			i;
	uint64_t	hash;
	uint64_t	hash_local;

	i = -1;
	hash = 0;
	while (++i < state->board_count)
	{
		hash_local = hash_unit64_3((uint64_t)state->board[i]);
		hash += hash_local * (i + 1) + (uint64_t)(state->board[i] + 1) * state->eval;
	}
	(DEBUG_HASH) ? ft_printf("%llu\n", hash) : 0;
	return (hash);
}

uint64_t	hashing(t_state *state)
{
	int			i;
	uint64_t	hash;
	uint64_t	hash_local;

	i = -1;
	hash = 0;
	while (++i < state->board_count)
	{
		hash_local = hash_unit64_1((uint64_t)state->board[i]);
		hash += hash_local * (i + 1) + (uint64_t)(state->board[i] + 1) * state->eval;
	}
	(DEBUG_HASH) ? ft_printf("%llu\n", hash) : 0;
	return  (hash);
}
