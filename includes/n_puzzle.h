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
# include <fcntl.h>

# define CMD_SIZE	2

typedef struct s_state
{
	int 		**board;
	int 		eval;
	int 		g;
	int 		h;
	int 		x_zero;
	int 		y_zero;
	t_state     *next;
}				t_state;

typedef struct	s_puzzle
{
	int			**board;
	int			**goal;
	char		*data;
	int			board_size;
	int			nbr_check;
	int			nbr_move;
	int			input;
	int 		error_p;
	int 		error_sign;
	void		(*heuristic)();
	t_state		*queue;
}				t_puzzle;

void 		init_board(t_puzzle *puzzle);
void 		parse_cmd(t_puzzle *puzzle, int argc, char **argv, int index);
void 		print_board(t_puzzle puzzle);
void 		up(t_puzzle *puzzle);
void 		down(t_puzzle *puzzle);
void 		left(t_puzzle *puzzle);
void 		right(t_puzzle *puzzle);
void 		check_error(t_puzzle puzzle);
void   		error_exit(t_puzzle *puzzle, char *str);
void 		print_usage(t_puzzle *puzzle);
long		ft_atol2(char *s, t_puzzle *puzzle);
int			ft_atoi2(char *s, t_puzzle *puzzle);
int 		is_valid_number(t_puzzle *puzzle, char* number);
void 		free_all(t_puzzle *puzzle);
char 		*ft_strjoin_free(char *s1, char *s2, int nb);

void 		manhanttan();
void 		h();
void 		p();

#endif
