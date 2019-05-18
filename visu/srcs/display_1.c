/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adefonta <adefonta@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 18:07:01 by adefonta          #+#    #+#             */
/*   Updated: 2019/05/18 15:03:01 by adefonta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"
#include "mlx.h"
#include "struct.h"
#include "visu_macro.h"
#include "libft.h"

void 		display_data(t_param p, t_mlx mlx, int *coord, int c)
{
	char	*txt;

	txt = NULL;
	coord[1] = STRING_Y;
	coord[0] += 36 * S_W;
	txt = ft_strjoin(T_HEURI, p.heuri);
	display_string(mlx, txt, coord, c);
	txt = ft_strjoin(T_SEARCH, p.search);
	display_string(mlx, txt, coord, c);
	txt = ft_strjoin(T_SIZE, ft_itoa(p.complex_size));
	display_string(mlx, txt, coord, c);
	txt = ft_strjoin(T_TIME, ft_itoa(p.complex_time));
	display_string(mlx, txt, coord, c);
	coord[1] += S_H;
	txt = ft_strjoin("by ", "adefonta && sde-spie");
	display_string(mlx, txt, coord, c);
}

void		display_info(t_param p, t_mlx mlx, char move)
{
	int		coord[2];
	int		c;
	char	*txt;

	txt = NULL;
	c = C_WHITE;
	coord[1] = STRING_Y;
	coord[0] = STRING_X;
	txt = ft_strjoin_f(T_SPEED, ft_itoa(p.speed), 1);
	display_string(mlx, txt, coord, c);
	coord[1] += S_H;
	txt = ft_strjoin_f(T_TOT_TURN, ft_itoa(p.state->g), 1);
	display_string(mlx, txt, coord, c);
	txt = ft_strjoin_f(T_TURN, ft_itoa(p.current_step), 1);
	display_string(mlx, txt, coord, c);
	txt = ft_strjoin(T_MOVE, &move);
	display_string(mlx, txt, coord, c);
	display_data(p, mlx, coord, c);
}

static void		display_piece(t_img *img, int start[2], int color)
{
	int	index[2];

	index[1] = -1;
	while (++index[1] < img->piece_size)
	{
		index[0] = -1;
		while (++index[0] < img->piece_size)
		{
			img->data[coord_to_pos(start[0] + index[0], start[1] + index[1], WIN_WIDTH)] = color;
		}
	}
}

void		display_board(t_mlx *mlx, t_state *state, t_img *img)
{
	int		i;
	int		start[2];
	int 	color;

	i = -1;
	start[0] = BOARD_START;
	start[1] = -img->piece_size + BOARD_START;
	while (++i < state->board_count)
	{
		start[0] += img->piece_size + BOARD_SPACE;
		if (i % state->board_size == 0)
		{
			start[0] = BOARD_START;
			start[1] += BOARD_SPACE + img->piece_size;
		}
		if (state->board[i] != 0)
		{
			color = color_mix(C_RED, C_BLUE,
				(double)state->board[i] / (double) state->board_count);
			display_piece(img, start, color);
		}
	}
}

void		display_numb(t_mlx *mlx, t_state *state, int size)
{
	int		i;
	int		start[2];
	int 	color;
	char	*line;

	i = -1;
	start[0] = BOARD_START;
	start[1] = -size + BOARD_START;
	while (++i < state->board_count)
	{
		start[0] += size + BOARD_SPACE;
		if (i % state->board_size == 0)
		{
			start[0] = BOARD_START;
			start[1] += BOARD_SPACE + size;
		}
		line = ft_itoa(state->board[i]);
		mlx_string_put(mlx->ptr, mlx->win, start[0] + 50, start[1] + 50, C_BLACK, line);
		free(line);
	}
}
