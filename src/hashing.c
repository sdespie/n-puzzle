/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-spie <sde-spie@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 14:25:50 by sde-spie          #+#    #+#             */
/*   Updated: 2019/05/18 18:32:21 by adefonta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"

static uint64_t	hash_unit64_1(uint64_t key)
{
	key = (~key) + (key << 21);
	key = key ^ (key >> 24);
	key = (key + (key << 3)) + (key << 8);
	key = key ^ (key >> 14);
	key = (key + (key << 2)) + (key << 4);
	key = key ^ (key >> 28);
	key = key + (key << 31);
	return (key);
}

static uint64_t	hash_unit64_3(uint64_t key)
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
	return (key);
}

uint64_t		hashing2(t_state *s)
{
	int			i;
	uint64_t	hash;
	uint64_t	hash_local;

	i = -1;
	hash = 0;
	while (++i < s->board_count)
	{
		hash_local = hash_unit64_3((uint64_t)s->board[i]);
		hash += hash_local * (i + 1) + (uint64_t)(s->board[i] + 1) * s->h;
	}
	(DEBUG_HASH) ? ft_printf("%llu\n", hash) : 0;
	return (hash);
}

uint64_t		hashing(t_state *s)
{
	int			i;
	uint64_t	hash;
	uint64_t	hash_local;

	i = -1;
	hash = 0;
	while (++i < s->board_count)
	{
		hash_local = hash_unit64_1((uint64_t)s->board[i]);
		hash += hash_local * (i + 1) + (uint64_t)(s->board[i] + 1) * s->h;
	}
	(DEBUG_HASH) ? ft_printf("%llu\n", hash) : 0;
	return (hash);
}
