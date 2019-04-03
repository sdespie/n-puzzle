/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adefonta <adefonta@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 19:23:20 by adefonta          #+#    #+#             */
/*   Updated: 2019/04/01 20:32:21 by adefonta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_state
{
	int 			*board;
	int 			eval;
	int 			g;
	int 			h;
	int 			x_zero;
	int 			y_zero;
	int				zero;
	int				board_size;
	int				board_count;
	char			*moves;
	long long		hash;
	struct s_state	*next;
}				t_state;

typedef struct	s_puzzle
{
	int			*goal;
	char		*data;
	int			board_size;
	int			board_count;
	int			nbr_check;
	int			nbr_move;
	int			input;
	int 		error_p;
	int 		error_sign;
	void		(*heuristic)();
	t_state		*queue;
}				t_puzzle;

#endif
