/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adefonta <adefonta@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 19:23:20 by adefonta          #+#    #+#             */
/*   Updated: 2019/04/05 03:34:22 by adefonta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_state
{
	int				id;
	int 			*board;
	int 			eval;
	int 			g;
	int 			h;
	int 			x_zero;
	int 			y_zero;
	int				zero;
	int				board_size;
	int				board_count;
	int				moves_size;
	long long		hash;
	char			*moves;
	struct s_state	*next;
}				t_state;

typedef struct	s_puzzle
{
	int			*goal;
	char		*data;
	int			nb_state_create;
	int			board_size;
	int			board_count;
	int			nbr_check;
	int			nbr_move;
	int			input;
	int 		error_p;
	int 		error_sign;
	void		(*heuristic)(struct	s_puzzle *puzzle, t_state *state);
	t_state		*not_visited;
	t_state		*visited;
}				t_puzzle;

#endif
