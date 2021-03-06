/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adefonta <adefonta@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 19:22:15 by adefonta          #+#    #+#             */
/*   Updated: 2019/05/22 18:45:54 by adefonta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"

void	print_usage(t_puzzle *puzzle)
{
	ft_printf("Usage : n-puzzle [file / size] [-m -h -e] ");
	ft_printf("[-astar -greedy -uniform]\n");
	free_all(puzzle);
}

void	print_board(int *board, int count, int size)
{
	int i;

	ft_printf("++++++++ BOARD ++++++\n");
	i = 0;
	while (i < count)
	{
		ft_printf("% .2d", board[i++]);
		if ((i % size) == 0)
			ft_printf("\n");
	}
}

void	print_queue(t_state *queue)
{
	t_state	*tmp;
	t_state	*pre;

	tmp = queue;
	pre = NULL;
	ft_printf("print_queue\n");
	while (tmp)
	{
		ft_printf("[%10d - %10llu]\n", tmp->eval, tmp->hash);
		pre = tmp;
		tmp = tmp->next;
	}
	ft_printf("print_revertqueue\n");
	while (pre)
	{
		ft_printf("[%10d - %10llu]\n", pre->eval, pre->hash);
		pre = pre->pre;
	}
}

void	print_step(t_state *state)
{
	int		i;
	char	*moves;

	if (!(moves = get_moves(state)))
	{
		error_print("Error print_step moves");
		return ;
	}
	i = -1;
	while (++i < state->g)
	{
		print_board(state->board, state->board_count, state->board_size);
		ft_printf("MOVE: %c \n", moves[i]);
		if (moves[i] == UP)
			up(state);
		else if (moves[i] == DOWN)
			down(state);
		else if (moves[i] == RIGHT)
			right(state);
		else if (moves[i] == LEFT)
			left(state);
	}
}
