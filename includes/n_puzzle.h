/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n-puzzle.h                                           :+:      :+:    :+:   */
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

/*
** room structure, n is the name given to the room in the map file, x and y
** are used for position,st is a boolean to know if this is the start,
** en is a boolean to know if it is the end.
** id is the id of this room (ranging 0 -> rn - 1)
*/

typedef struct	s_puzzle
{
	int			**board;
	int			**goal;
	int			board_size;
	int			nbr_check;
	int			nbr_move;
	void		(*heuristic)();
}				t_puzzle;


/*
** main structure being passed in every function.
** rl is a tab of pointer of room structures, startid is the id of starting room
** rn is the number of room, endid is the id of the ending room, antn is the
** number of ants to cross the map.
*/



/*
**		.c
*/


#endif
