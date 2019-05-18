/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-spie <sde-spie@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 14:25:50 by sde-spie          #+#    #+#             */
/*   Updated: 2019/05/18 21:06:36 by adefonta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"
#include "macro.h"

static void	set_snail(t_puzzle *p, int *pos)
{
	int	i[2];
	int	ref[2];
	int	size;

	size = p->board_size;
	ref[0] = -1;
	ref[1] = 1;
	while (++ref[0] < p->board_size)
	{
		i[0] = 0;
		i[1] = 0;
		while (p->goal[(ref[0] + i[1]) * p->board_size + ref[0] + i[0]] == 0)
		{
			*pos = (ref[0] + i[1]) * p->board_size + ref[0] + i[0];
			p->goal[*pos] = ref[1]++;
			if (i[1] == 0 && i[0] != size - 1)
				i[0]++;
			else if (i[1] == size - 1 && i[0] != 0)
				i[0]--;
			else
				(i[0] == 0 && i[1] != 0) ? i[1]-- : i[1]++;
		}
		size -= 2;
	}
	p->goal[*pos] = 0;
}

void		board_copy(int *dst, int *src, int count)
{
	int	i;

	i = -1;
	while (++i < count)
		dst[i] = src[i];
}

int			*board_create(int count)
{
	int	*board;

	if (!(board = (int *)ft_memalloc(sizeof(int) * (count))))
		return (NULL);
	return (board);
}

int			board_init(t_puzzle *p)
{
	int	size;
	int	zero;

	size = p->board_size;
	p->board_count = size * size;
	if (!(p->goal = board_create(p->board_count)) ||
		!(p->base = board_create(p->board_count)))
		return (KO);
	set_snail(p, &zero);
	print_board(p->goal, p->board_count, p->board_size);
	if (!(p->opened = state_create(p->board_count, p->board_size)))
	{
		free_all(p);
		return (KO);
	}
	p->opened->zero = zero;
	if (p->input == 0)
	{
		board_copy(p->opened->board, p->goal, p->board_count);
		randomize(p->opened);
		board_copy(p->base, p->opened->board, p->board_count);
		p->zero_base = p->opened->zero;
	}
	return (OK);
}
