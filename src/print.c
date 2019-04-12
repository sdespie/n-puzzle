/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adefonta <adefonta@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 19:22:15 by adefonta          #+#    #+#             */
/*   Updated: 2019/04/12 03:59:58 by adefonta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"

void	print_usage(t_puzzle *puzzle)
{
    ft_printf("Usage : n-puzzle [file / size] [-m -... -...]");
    free_all(puzzle);
}

void	print_board(int *board, int count, int size)
{
    int i;
    int j;

    ft_printf("++++++++ BOARD ++++++\n");
    i = 0;
    while (i < count)
    {
        ft_printf("% .2d", board[i++]);
		if ((i % size) == 0)
        	ft_printf("\n");
    }
}

void	print_state(t_state *state)
{
	ft_printf("########## STATE -- id: %d\n", state->id);
	ft_printf("eval : %10d\n", state->eval);
	ft_printf("g    : %10d\n", state->g);
	ft_printf("h    : %10d\n", state->h);
	ft_printf("zero : %10d\n", state->zero);
	ft_printf("move : %c\n", state->move);
	print_board(state->board, state->board_count, state->board_size);
}

void	print_queue(t_state	*queue)
{
	t_state	*tmp;
	t_state	*pre;

	tmp = queue;
	pre = NULL;
	ft_printf("print_queue\n");
	while (tmp)
	{
		ft_printf("[%10d - %10llu]\n", tmp->h, tmp->hash);
		pre = tmp;
		tmp = tmp->next;
	}
	ft_printf("print_revertqueue\n");
	while (pre)
	{
		ft_printf("[%10d - %10llu]\n", pre->h, pre->hash);
		pre = pre->pre;
	}
}

void	print_sort(t_sorttable *sort)
{
	ft_printf("print_sort\n");

	for (int i = 0; i < sort->size; i++)
	{
		if (sort->table[i])
			ft_printf("[%10d - %10llu]\n", sort->table[i]->h, sort->table[i]->hash);
	}
}

char	*get_moves(t_state *state)
{
	int		i;
	char	*moves;
	t_state	*pre_move;

	if (!(moves = (char *)calloc(sizeof(char) , (state->g + 2))))
		return (NULL);
	pre_move = state;
	i = state->g + 2;
	while (--i > 0)
	{
		ft_printf("[%c-%d] ", pre_move->move, i);
		moves[i] = pre_move->move;
		pre_move = pre_move->pre_move;
	}
	ft_printf("get_moves:: %s\n", moves);
	return (moves);
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
	i = 0;
	while (++i < state->g)
	{
		ft_printf("MOVE: %c \n", moves[i]);
		if (moves[i] == UP)
			up(state);
		else if (moves[i] == DOWN)
			down(state);
		else if (moves[i] == RIGHT)
			right(state);
		else if (moves[i] == LEFT)
			left(state);
		print_board(state->board, state->board_count, state->board_size);
	}
}
