/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorttable.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adefonta <adefonta@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 20:42:13 by adefonta          #+#    #+#             */
/*   Updated: 2019/05/22 22:21:13 by adefonta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"

static int	expand(t_sorttable *s)
{
	int		i;
	int		size_old;
	t_state	**table_old;

	i = -1;
	if (s)
	{
		size_old = s->size;
		s->size *= 2;
		table_old = s->table;
		if (!s->table)
		{
			if (!(s->table = (t_state **)calloc(sizeof(t_state*), s->size)))
				return (error_print("Error: sorttable table calloc"));
		}
		else if (!(s->table = (t_state **)realloc(s->table,
												sizeof(t_state*) * s->size)))
			return (error_print("Error: sorttable table realloc"));
	}
	return (OK);
}

int			sorttable_init(t_puzzle *puzzle)
{
	t_sorttable	*sort;

	if (!(sort = (t_sorttable*)malloc(sizeof(t_sorttable))))
		return (error_print("Error: sorttable malloc"));
	sort->count = 0;
	sort->size = HASH_SIZE;
	sort->table = NULL;
	if (expand(sort) != OK)
		return (KO);
	puzzle->sort = sort;
	return (OK);
}

static int	find_prestate_index(t_puzzle *puzzle, int index_base)
{
	int	index;

	index = index_base;
	while (index > 0 && !puzzle->sort->table[index])
		index--;
	if (index == 0)
		return ((puzzle->opened) ? puzzle->opened->eval : index_base);
	return (index);
}

int			sort_newstate(t_puzzle *puzzle, t_state *new_state)
{
	int		head_index;
	t_state	*new_head;

	if (new_state->eval >= puzzle->sort->size && expand(puzzle->sort) != OK)
		return (KO);
	head_index = find_prestate_index(puzzle, new_state->eval);
	new_head = state_insort(puzzle->sort->table[head_index], new_state);
	puzzle->sort->table[new_state->eval] = new_state;
	if (!puzzle->opened || puzzle->opened->eval >= new_state->eval)
		puzzle->opened = new_state;
	puzzle->opened->pre = NULL;
	return (OK);
}

void		sort_remove(t_sorttable *sort, t_state *state_close)
{
	if (state_close->next)
		state_close->next->pre = state_close->pre;
	state_close->pre = NULL;
	if (sort->table[state_close->eval] &&
		sort->table[state_close->eval]->hash == state_close->hash)
	{
		if (state_close->next && state_close->next->eval == state_close->eval)
			sort->table[state_close->eval] = state_close->next;
		else
			sort->table[state_close->eval] = NULL;
	}
}
