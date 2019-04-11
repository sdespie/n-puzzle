/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_puzzle.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-spie <sde-spie@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 14:25:50 by sde-spie          #+#    #+#             */
/*   Updated: 2019/04/12 01:07:24 by adefonta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef N_PUZZLE_H
# define N_PUZZLE_H

# include "libft.h"
# include "struct.h"
# include "macro.h"

# include <stdio.h>
# include <fcntl.h>
# include <math.h>

int 		board_init(t_puzzle *puzzle);
int			*board_create(int count);
void		board_copy(int *dst, int *src, int count);

int 		parse_cmd(t_puzzle *puzzle, int argc, char **argv, int index);

void		print_board(int *board, int count, int size);
void 		print_usage(t_puzzle *puzzle);
void		print_state(t_state *state);
void		print_step(t_state *state);
void		print_queue(t_state	*queue);
void		print_sort(t_sorttable *sort);

void 		up(t_state *state);
void 		down(t_state *state);
void 		left(t_state *state);
void 		right(t_state *state);

int			check_error(t_state *state, t_puzzle *puzzle);
int			check_nextmoves(t_state *state, char next_moves[MAX_MOVES]);
int			check_valid_start(t_puzzle *puzzle);

int 		is_valid_number(t_puzzle *puzzle, char* number);
int			ft_abs(int x);
void		queue_is_sort(t_state *queue);

long		ft_atol2(char *s, t_puzzle *puzzle);
int			ft_atoi2(char *s, t_puzzle *puzzle);

long		ft_atol2(char *s, t_puzzle *puzzle);
int			ft_atoi2(char *s, t_puzzle *puzzle);
char 		*ft_strjoin_free(char *s1, char *s2, int nb);

int   		error_exit(t_puzzle *puzzle, char *str);
int			error_print(char *str);

t_state		*state_create(int count, int size);

void 		free_all(t_puzzle *puzzle);
void		free_state(t_state *state);

void 		manhanttan(t_puzzle *puzzle, t_state *state);
void 		h(t_puzzle *puzzle, t_state *state);
void		e(t_puzzle *puzzle, t_state *state);

void 		hashing(t_state *state);
int			hash_init(t_puzzle *puzzle);
int			hash_process(t_hashmap *map, t_state *state);

char		*move_newcopy(char *src, int old_size, int new_size);
int			move_add(t_state *state, char move);

int			state_is_new(t_state *queue, t_state *new_state);
t_state		*state_insort(t_state *queue, t_state *new_state);
t_state		*state_newmove(t_state *base, char move);

int			solve(t_puzzle *puzzle);

int			sorttable_init(t_puzzle *puzzle);
int			sort_newstate(t_puzzle *puzzle, t_state *new_state);
void 		sort_remove(t_sorttable *sort, t_state *state_close);

#endif
