/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_puzzle.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-spie <sde-spie@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 14:25:50 by sde-spie          #+#    #+#             */
/*   Updated: 2019/01/16 16:35:02 by sde-spie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "libft.h"
# include <stdio.h>

typedef struct	s_puzzle
{
	int			**board;
	int			**goal;
	int			board_size;
	int			nbr_check;
	int			nbr_move;
	int 		x_zero;
	int 		y_zero;
	int			input;
	void		(*heuristic)();
}				t_puzzle;



void 		init_board(t_puzzle *puzzle);
void   		parse_cmd(t_puzzle *puzzle, int argc, char **argv);
void 		print_board(t_puzzle puzzle);
void 		up(t_puzzle *puzzle);
void 		down(t_puzzle *puzzle);
void 		left(t_puzzle *puzzle);
void 		right(t_puzzle *puzzle);
void 		check_error(t_puzzle puzzle);


#endif
