/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adefonta <adefonta@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 18:07:01 by adefonta          #+#    #+#             */
/*   Updated: 2019/05/03 19:01:29 by adefonta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"
#include "mlx.h"
#include "struct.h"
#include "visu_macro.h"
#include "libft.h"
// static void	display_champi(t_mlx mlx, t_vm vm, int coord[2])
// {
// 	int			i;
// 	char		*txt;
// 	t_champi	*champi;
//
// 	i = -1;
// 	txt = NULL;
// 	while (++i < vm.nb_champi)
// 	{
// 		champi = vm.champi[i];
// 		coord[1] += S_H;
// 		txt = ft_strjoin(T_PLAYER_NAME, champi->name);
// 		display_string(mlx, txt, coord, champi->color);
// 		txt = ft_strjoin_free(T_PLAYER_INDEX, ft_itoa(champi->index), 1);
// 		display_string(mlx, txt, coord, champi->color);
// 		txt = ft_strjoin_free(T_PLAYER_LIVE, ft_itoa(champi->nb_live), 1);
// 		display_string(mlx, txt, coord, champi->color);
// 		txt = ft_strjoin_free(T_PLAYER_PROCESS, ft_itoa(champi->nb_process), 1);
// 		display_string(mlx, txt, coord, champi->color);
// 	}
// }
//
// static void	info_bottom(t_mlx mlx, t_vm vm, int coord[2])
// {
// 	char	*txt;
// 	int		c;
//
// 	txt = NULL;
// 	c = C_WHITE;
// 	coord[1] += S_H;
// 	txt = ft_strjoin_free(T_CYCLE_TO_DIE, ft_itoa(vm.cycles_to_die), 1);
// 	display_string(mlx, txt, coord, c);
// 	txt = ft_strjoin_free(T_CYCLE_DELTA, ft_itoa(CYCLE_DELTA), 1);
// 	display_string(mlx, txt, coord, c);
// 	txt = ft_strjoin_free(T_NB_LIVE, ft_itoa(vm.live_calls), 1);
// 	display_string(mlx, txt, coord, c);
// 	txt = ft_strjoin_free(T_MAX_LIVE, ft_itoa(NBR_LIVE), 1);
// 	display_string(mlx, txt, coord, c);
// 	txt = ft_strjoin_free(T_NB_CHEKS, ft_itoa(vm.checkups), 1);
// 	display_string(mlx, txt, coord, c);
// 	txt = ft_strjoin_free(T_MAX_CHEKS, ft_itoa(MAX_CHECKS), 1);
// 	display_string(mlx, txt, coord, c);
// 	display_champi(mlx, vm, coord);
// }
//

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

}
//
// void		display_cadre(t_img *img)
// {
// 	int	x;
// 	int	y;
// 	int	arena_end[2];
//
// 	arena_end[0] = END_X + END_WIDTH;
// 	arena_end[1] = END_Y + END_HEIGHT;
// 	y = 0;
// 	while (y < WIN_HEIGHT)
// 	{
// 		x = END_X / 2;
// 		while (x < WIN_WIDTH - ARENA_X / 2)
// 		{
// 			if (y > END_Y && y < arena_end[1] && x > END_X && x < arena_end[0])
// 				x = arena_end[0];
// 			else
// 			{
// 				img->data[coord_to_pos(x, y, WIN_WIDTH)] = C_RED;
// 				x += ((x % 5) == 0) ? 5 : 1;
// 			}
// 		}
// 		y += 5;
// 	}
// }
static int	ft_rapport(int first, int second, double p)
{
	if (first == second)
		return (first);
	return ((int)((double)first + (second - first) * p));
}

static int	color_mix(int c1, int c2, double p)
{
	int r;
	int g;
	int b;

	if (c1 == c2)
		return (c1);
	r = ft_rapport((c1 >> 16) & 0xFF, (c2 >> 16) & 0xFF, p);
	g = ft_rapport((c1 >> 8) & 0xFF, (c2 >> 8) & 0xFF, p);
	b = ft_rapport(c1 & 0xFF, c2 & 0xFF, p);
	return (r << 16 | g << 8 | b);
}


static void		display_piece(t_img *img, int start[2], int size, int color)
{
	int	index[2];

	index[1] = -1;
	while (++index[1] < size)
	{
		index[0] = -1;
		while (++index[0] < size)
		{
			img->data[coord_to_pos(start[0] + index[0], start[1] + index[1], WIN_WIDTH)] = color;
		}
	}
}

void		display_board(t_state *state, t_img *img)
{
	int	i;
	int	start[2];
	int	size;
	int	space;
	int color;

	space = 10;
	size = (img->dim[0] - 400 < img->dim[1] - 400) ? img->dim[0] - 400 : img->dim[1] - 400;
	size = size / state->board_size - space;
	i = -1;
	start[0] = 200;
	start[1] = -size + 200;
	while (++i < state->board_count)
	{
		start[0] += size + space;
		if (i % state->board_size == 0)
		{
			start[0] = 200;
			start[1] += space + size;
		}
		if (state->board[i] != 0)
		{
			color = color_mix(C_RED, C_BLUE,
				(double)state->board[i] / (double) state->board_count);
			display_piece(img, start, size, color);
		}
	}
}
