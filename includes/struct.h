/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adefonta <adefonta@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 19:23:20 by adefonta          #+#    #+#             */
/*   Updated: 2019/04/12 16:20:57 by adefonta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_state
{
	int					id;
	int 				*board;
	int 				eval;
	int 				g;
	int 				h;
	int					zero;
	int					board_size;
	int					board_count;
	int					moves_size;
	int					hash_level;
	uint64_t			hash;
	uint64_t			hash2;
	char				move;
	struct s_state		*pre_move;
	struct s_state		*next;
	struct s_state		*pre;
}				t_state;

typedef struct s_hashmap
{
	int					count;
	int					size;
	int					colision;
	t_state				**table;
}				t_hashmap;

typedef struct s_sorttable
{
	int					count;
	int					size;
	t_state				**table;
}				t_sorttable;

typedef struct	s_puzzle
{
	int			*goal;
	int			*base;
	char		*data;
	int			zero_base;
	int			nb_state_create;
	int			nb_state_del; // info
	int			board_size;
	int			board_count;
	int			nbr_check;
	int			nbr_move;
	int			input;
	int 		error_p;
	int 		error_sign;
	void		(*heuristic)(struct	s_puzzle *puzzle, t_state *state);
	t_state		*opened;
	t_state		*closed;
	t_sorttable *sort;
	t_hashmap	*map;
}				t_puzzle;

#endif
