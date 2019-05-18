/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adefonta <adefonta@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 15:58:15 by adefonta          #+#    #+#             */
/*   Updated: 2019/05/18 14:28:22 by adefonta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"

static int	add(t_hashmap *map, t_state *state, uint64_t hash)
{
	int	i;
	int	hash_mod;

	(DEBUG_HASH) ? ft_printf("hash_add::start\n") : 0;
	if (map->count >= map->size)
		return (KO);
	i = -1;
	hash_mod = hash % map->size;
	while (++i < HASH_MAX_LEVEL)
	{
		(DEBUG_HASH) ? ft_printf("hash_add::hash_mod %d\n", hash_mod) : 0;
		if (!map->table[hash_mod])
		{
			state->hash_level = i;
			map->table[hash_mod] = state;
			return (OK);
		}
		map->colision += 1;
		hash_mod = (hash_mod + 1) % map->size;
	}
	return (KO);
}

static int	contains(t_hashmap *map, t_state *state, uint64_t hash)
{
	int		i;
	int		hash_mod;
	t_state	*cmp;

	(DEBUG_HASH) ? ft_printf("hash_contains::start\n") : 0;
	i = -1;
	hash_mod = hash % map->size;
	while (++i < HASH_MAX_LEVEL)
	{
		cmp = map->table[hash_mod];
		if (cmp && cmp->h == state->h && cmp->hash == state->hash)
		{
			(DEBUG_HASH) ? ft_printf("hash_contains::TRUE\n %d %d -- %llu %llu\n", cmp->h , state->h , cmp->hash, state->hash) : 0;
			return (OK);
		}
		hash_mod = (hash_mod + 1) % map->size;
	}
	return (KO);
}

static int	expand(t_hashmap *map)
{
	int		i;
	int		size_old;
	t_state	**table_old;

	i = -1;
	if (map)
	{
		size_old = map->size;
		map->size *= 2;
		(DISPLAY_HASH_INFO) ? ft_printf("hash_expand::size %10d::count %8d::colision %6d :: perf %.2d /100 \n", map->size, map->count, map->colision, (int)(((double)map->count / (double)map->size) * 100)) : 0;
		map->colision = 0;
		table_old = map->table;
		if (!(map->table = (t_state **)calloc(sizeof(t_state*), map->size)))
			return (ERROR);
		if (table_old)
		{
			while (++i < size_old)
			{
				if (table_old[i])
				{
					if (!add(map, table_old[i], table_old[i]->hash) &&
						!add(map, table_old[i], table_old[i]->hash2))
					{
						ft_printf("hash_expand, double size is not enough %d\n", map->size);
						return (KO);
					}
				}
			}
		}
	}
	return (OK);
}

int		hash_init(t_puzzle *puzzle)
{
	t_hashmap	*map;

	(DEBUG_HASH) ? ft_printf("hash_init::start\n") : 0;
	if (!(map = (t_hashmap*)malloc(sizeof(t_hashmap))))
		return (error_exit(puzzle, "Error: hashmap calloc"));
	map->count = 0;
	map->size = HASH_SIZE;
	map->table = NULL;
	map->colision = 0;
	if (expand(map) != OK)
		return (error_exit(puzzle, "Error: hash_expand calloc"));
	puzzle->map = map;
	return (OK);
}

int		hash_process(t_hashmap *map, t_state *state)
{
	(DEBUG_HASH) ? ft_printf("hash_process::count %d\n", map->count) : 0;
	state->hash = hashing(state);
	state->hash2 = hashing2(state);
	(DEBUG_HASH) ? ft_printf("hash = %llu %llu\n",state->hash, state->hash2) : 0;
	if (map->count != 0 && (contains(map, state, state->hash) == OK ||
							contains(map, state, state->hash2) == OK))
		return (KO);
	while (add(map, state, state->hash) != OK &&
			add(map, state, state->hash2) != OK)
	{
		if (expand(map) == ERROR)
			return (ERROR);
	}
	map->count += 1;
	return (OK);
}
