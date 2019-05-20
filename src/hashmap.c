/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adefonta <adefonta@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 15:58:15 by adefonta          #+#    #+#             */
/*   Updated: 2019/05/20 21:54:44 by sde-spie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"

static int	add(t_hashmap *map, t_state *state, uint64_t hash)
{
	int	i;
	int	hash_mod;

	if (map->count >= map->size)
		return (KO);
	i = -1;
	hash_mod = hash % map->size;
	while (++i < HASH_MAX_LEVEL)
	{
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

	i = -1;
	hash_mod = hash % map->size;
	while (++i < HASH_MAX_LEVEL)
	{
		cmp = map->table[hash_mod];
		if (cmp && state->h == cmp->h && state->hash == cmp->hash)
			return (OK);
		hash_mod = (hash_mod + 1) % map->size;
	}
	return (KO);
}

static int	expand(t_hashmap *map)
{
	int		size_old;
	t_state	**old_tab;

	if (map)
	{
		size_old = map->size;
		map->size *= 2;
		map->colision = 0;
		old_tab = map->table;
		if (!(map->table = (t_state **)calloc(sizeof(t_state*), map->size)))
			return (ERROR);
		if (old_tab)
			while (--size_old >= 0)
			{
				if (old_tab[size_old])
				{
					if (!add(map, old_tab[size_old], old_tab[size_old]->hash) &&
						!add(map, old_tab[size_old], old_tab[size_old]->hash2))
						return (KO);
				}
			}
		free(old_tab);
	}
	return (OK);
}

int			hash_init(t_puzzle *puzzle)
{
	t_hashmap	*map;

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

int			hash_process(t_hashmap *map, t_state *state)
{
	state->hash = hashing(state);
	state->hash2 = hashing2(state);
	if (map->count != 0 && (contains(map, state, state->hash) == OK ||
							contains(map, state, state->hash2) == OK))
		return (KO);
	while (add(map, state, state->hash) != OK &&
			add(map, state, state->hash2) != OK)
	{
		(DISPLAY_HASH_INFO) ? ft_printf(PRINT_HASH, map->size, map->count,
			map->colision) : 0;
		if (expand(map) == ERROR)
			return (ERROR);
	}
	map->count += 1;
	return (OK);
}
