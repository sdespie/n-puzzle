/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adefonta <adefonta@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 15:58:15 by adefonta          #+#    #+#             */
/*   Updated: 2019/04/11 19:19:50 by adefonta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"

static int	hash_add(t_hashmap *map, t_state *state)
{
	int	i;
	int	hash_mod;

	(DEBUG_HASH) ? ft_printf("hash_add::start\n") : 0;
	if (map->count >= map->size)
		return (KO);
	i = -1;
	hash_mod = state->hash % map->size;
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

int	hash_contains(t_hashmap *map, t_state *state)
{
	int		i;
	int		hash_mod;
	t_state	*cmp;

	(DEBUG_HASH) ? ft_printf("hash_contains::start\n") : 0;
	i = -1;
	hash_mod = state->hash % map->size;
	while (++i < HASH_MAX_LEVEL)
	{
		cmp = map->table[hash_mod];
		if (cmp && cmp->h == state->h && cmp->hash == state->hash)
			return (OK);
		hash_mod = (hash_mod + 1) % map->size;
	}
	return (KO);
}

static int	hash_expand(t_hashmap *map)
{
	int		i;
	int		size_old;
	t_state	**table_old;

	i = -1;
	if (map)
	{
		size_old = map->size;
		map->size *= 2;
		(DISPLAY_HASH_INFO) ? ft_printf("hash_expand::size %d::count %d::colision %d\n", map->size, map->count, map->colision) : 0;
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
					if (!hash_add(map, table_old[i]))
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
	if (hash_expand(map) != OK)
		return (error_exit(puzzle, "Error: hash_expand"));
	puzzle->map = map;
	return (OK);
}

int		hash_process(t_hashmap *map, t_state *state)
{
	(DEBUG_HASH) ? ft_printf("hash_init::hash_process:: count %d\n", map->count) : 0;
	hashing(state);
	if (map->count != 0 && hash_contains(map, state) == OK)
		return (KO);
	while (hash_add(map, state) != OK)
	{
		if (hash_expand(map) == ERROR)
			return (ERROR);
	}
	map->count += 1;
	return (OK);
}