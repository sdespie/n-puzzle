/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_macro.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adefonta <adefonta@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 16:14:02 by adefonta          #+#    #+#             */
/*   Updated: 2019/05/03 19:00:12 by adefonta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISU_MACRO_H
# define VISU_MACRO_H

# define OK 1
# define KO 0

# define COLOR 0x33CCFF
# define NB_IMAGES 2
# define WIN_WIDTH 1500
# define WIN_HEIGHT 1500

# define AXE_X 0
# define AXE_Y 1
# define START 0
# define END 1

# define STRING_X 10
# define STRING_Y 30
# define S_H 20
# define S_W 30

# define STRING_X_MAX 179
# define STRING_NB 10
# define BLOCK_WIDTH 20
# define STRING_CY 1000

# define INDEX_BAR 0
# define INDEX_CANVAS 1

# define HEADER_WIDTH 0.93
# define HEADER_HEIGHT 0.1
# define HEADER_X 0.07
# define HEADER_Y 0.0

# define BAR_WIDTH 0.07
# define BAR_HEIGHT 1
# define BAR_X 0
# define BAR_Y 0

# define CANVAS_W WIN_WIDTH
# define CANVAS_H WIN_HEIGHT

# define CANVAS_WIDTH 1
# define CANVAS_HEIGHT 1
# define CANVAS_X 0
# define CANVAS_Y 0

# define ARENA_WIDTH (64 * S_W)
# define ARENA_HEIGHT (64 * S_H)
# define ARENA_Y (WIN_HEIGHT - ARENA_HEIGHT) / 2
# define ARENA_X (WIN_WIDTH - ARENA_WIDTH) / 2

# define GRAPH_NB_COLUMN 100

# define GRAPH_X ARENA_X / 2
# define GRAPH_Y 50
# define GRAPH_WIDTH (WIN_WIDTH - (GRAPH_X * 2))
# define GRAPH_HEIGHT ((WIN_HEIGHT - GRAPH_Y) * 0.5)
# define GRAPH_COLUMN ((GRAPH_WIDTH * 0.49) / GRAPH_NB_COLUMN)
# define GRAPH_SPACE GRAPH_WIDTH * 0.01

# define GRAPH_LIVE_Y (GRAPH_Y + GRAPH_HEIGHT + 50)
# define GRAPH_LIVE_HEIGHT (WIN_HEIGHT - GRAPH_LIVE_Y - 100)
# define GRAPH_LIVE_WIDTH GRAPH_WIDTH * 0.97

# define GRAPH_LIVE_COLUMN (GRAPH_LIVE_WIDTH / GRAPH_NB_COLUMN)

# define STRING_X_RIGHT (GRAPH_X + GRAPH_WIDTH + STRING_X)
# define GRAPH_MINI_X STRING_X * 3
# define GRAPH_MINI_Y WIN_HEIGHT * 0.75
# define GRAPH_MINI_WIDTH (ARENA_X)
# define GRAPH_MINI_HEIGHT WIN_HEIGHT * 0.23
# define GRAPH_MINI_COLUMN (GRAPH_MINI_WIDTH / GRAPH_NB_COLUMN)

# define END_X WIN_WIDTH * 0.2
# define END_Y WIN_HEIGHT *  0.2
# define END_WIDTH WIN_WIDTH * 0.6
# define END_HEIGHT WIN_HEIGHT * 0.6
# define STRING_END_X  END_X + END_WIDTH * 0.2
# define STRING_END_Y  END_Y + END_HEIGHT * 0.2

# define LEFT_ARENA_WIDTH ARENA_X
# define LEFT_ARENA_HEIGHT WIN_HEIGHT

# define SPEED_MAX 100
# define SPEED_MIN 10

# define CM_CLASSIC 0
# define CM_GOOGLE 1
# define CM_GREEN 2
# define CM_BLUE 3
# define CM_PINK 4

# define C_DARK 0x120E0E
# define C_DARK1 0xFAFAFA
# define C_ANTH 0x181D21
# define C_WHITE 0xFFFFFF
# define C_GREY 0x646464

# define C_RED 0xf0356d
# define C_BLUE 0x356df0
# define C_GREEN 0x6df035
# define C_YELLOW 0xf0b835
# define C_CYAN 0x35cbf0
# define C_MAUVE 0x5a35f0

# define T_WIN "N-puzzle tout simplement..."

# define T_SPEED 			"Speed        : "
# define T_TURN 			"Turn         : "
# define T_TOT_TURN 		"Tot turn     : "
# define T_MOVE 			"Current move : "
# define T_SEARCH 			"Mode            : "
# define T_HEURI			"Heuristic       : "
# define T_SIZE 			"Size Complexity : "
# define T_TIME 			"Time Complexity : "

#endif
