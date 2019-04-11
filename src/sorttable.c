/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorttable.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adefonta <adefonta@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 20:42:13 by adefonta          #+#    #+#             */
/*   Updated: 2019/04/12 00:45:47 by adefonta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "n_puzzle.h"

static int	expand(t_sorttable *sort)
{
	int		i;
	int		size_old;
	t_state	**table_old;

	i = -1;
	if (sort)
	{
		size_old = sort->size;
		sort->size *= 2;
		(DISPLAY_SORT_INFO) ? ft_printf("sorttable_expand::size %10d::count %8d\n", sort->size, sort->count) : 0;
		table_old = sort->table;
		if (!sort->table)
		{
		 	if (!(sort->table = (t_state **)calloc(sizeof(t_state*), sort->size)))
				return (error_print("Error: sorttable table calloc"));
		}
		else if (!(sort->table = (t_state **)realloc(sort->table, sizeof(t_state*) * sort->size)))
			return (error_print("Error: sorttable table realloc"));
	}
	return (OK);
}

int			sorttable_init(t_puzzle *puzzle)
{
	t_sorttable	*sort;

	(DEBUG_SORT) ? ft_printf("sort_init::start\n") : 0;
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
	(DEBUG_SORT_2) ? ft_printf("sorttable::find_prestate_index:: index_base %d\n", index_base) : 0;
	while (index > 0 && !puzzle->sort->table[index])
		index--;
	if (index == 0)
		return ((puzzle->opened) ? puzzle->opened->h : index_base);
	return (index);
}

int			sort_newstate(t_puzzle *puzzle, t_state *new_state)
{
	int		head_index;
	t_state	*new_head;

	(DEBUG_SORT) ? ft_printf("sort_newstate::start\n") : 0;
	(DEBUG_SORT) ? ft_printf("new [%10d - %10llu]\n", new_state->h, new_state->hash) : 0;

	if (new_state->h >= puzzle->sort->size && expand(puzzle->sort) != OK)
		return (KO);
	head_index = find_prestate_index(puzzle, new_state->h);
	(DEBUG_SORT_2) ? ft_printf("sort_newstate::head_index %d\n", head_index) : 0;

	new_head = state_insort(puzzle->sort->table[head_index], new_state);
	// ft_printf("New_head: ");
	// print_queue(new_head);
	// if (puzzle->sort->table[new_state->h])
	// 	puzzle->sort->table[new_state->h] = new_head;
	// else
		puzzle->sort->table[new_state->h] = new_state;
	if (!puzzle->opened || puzzle->opened->h >= new_state->h)
		puzzle->opened = new_state;
	puzzle->opened->pre = NULL;
	(DEBUG_SORT) ? print_sort(puzzle->sort) : 0;
	(DEBUG_SORT) ? print_queue(puzzle->opened) : 0;
	return (OK);
}

void sort_remove(t_sorttable *sort, t_state *state_close)
{

	(DEBUG_SORT_2) ? ft_printf("#########sort_remove::start\n") : 0;
	if (state_close->next)
		state_close->next->pre = state_close->pre;
	state_close->pre = NULL;
	if (sort->table[state_close->h] && sort->table[state_close->h]->hash == state_close->hash)
	{
		if (state_close->next && state_close->next->h == state_close->h)
			sort->table[state_close->h] = state_close->next;
		else
			sort->table[state_close->h] = NULL;
	}
	(DEBUG_SORT_2) ? ft_printf("#########sort_remove::end\n") : 0;

}
