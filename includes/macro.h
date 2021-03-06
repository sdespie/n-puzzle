/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adefonta <adefonta@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 20:11:25 by adefonta          #+#    #+#             */
/*   Updated: 2019/05/23 00:10:21 by adefonta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACRO_H
# define MACRO_H

# define DEBUG_HASH 0
# define DEBUG_SORT 0
# define DEBUG_SORT_2 0
# define DEBUG_HARD 0
# define DEBUG_HARD_INIT 0
# define IS_SORT 0

# define DISPLAY_STATE_INFO 0
# define DISPLAY_HASH_INFO 0
# define DISPLAY_SORT_INFO 0
# define DISPLAY 1

# define CMD_SIZE	3
# define OK 1
# define KO 0
# define ERROR -1

# define PR_POW  13
# define PR_MULT 31

# define UP		'W'
# define DOWN	'S'
# define LEFT	'A'
# define RIGHT	'D'

# define NBR_MOVES_ADD 255
# define MAX_MOVES 4

# define HASH_SIZE 500
# define HASH_MAX_LEVEL 5

# define EMALLOC "Error: Malloc failed."
# define PRINT_HASH "hash: size %10d::count %8d::colision %6d\n"
#endif
