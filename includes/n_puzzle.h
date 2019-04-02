/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_puzzle.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-spie <sde-spie@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 14:25:50 by sde-spie          #+#    #+#             */
/*   Updated: 2019/04/01 21:05:53 by adefonta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef N_PUZZLE_H
# define N_PUZZLE_H

# include "libft.h"
# include "struct.h"
# include "macro.h"

# include <stdio.h>
# include <fcntl.h>

int 		board_init(t_puzzle *puzzle);
int			*board_create(int count);
void 		board_copy(t_state *state, int *board);

int 		parse_cmd(t_puzzle *puzzle, int argc, char **argv, int index);

void 		print_board(t_state *state);
void 		print_usage(t_puzzle *puzzle);

void 		up(t_state *state);
void 		down(t_state *state);
void 		left(t_state *state);
void 		right(t_state *state);

void		check_error(t_state *state);
int 		is_valid_number(t_puzzle *puzzle, char* number);

long		ft_atol2(char *s, t_puzzle *puzzle);
int			ft_atoi2(char *s, t_puzzle *puzzle);

long		ft_atol2(char *s, t_puzzle *puzzle);
int			ft_atoi2(char *s, t_puzzle *puzzle);
char 		*ft_strjoin_free(char *s1, char *s2, int nb);

int   		error_exit(t_puzzle *puzzle, char *str);

t_state		*state_create(int count, int size);

void 		free_all(t_puzzle *puzzle);

void 		manhanttan();
void 		h();
void 		e();

#endif
