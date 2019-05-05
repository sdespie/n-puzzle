/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adefonta <adefonta@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 15:52:31 by adefonta          #+#    #+#             */
/*   Updated: 2019/05/03 18:59:35 by adefonta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"
#include "visu_macro.h"
#include "macro.h"
#include "mlx.h"
#include "keycode.h"
#include "n_puzzle.h"

static int		init_modes(t_param *param, t_puzzle puzzle)
{
	int 	i;
	t_state *state;

	if (puzzle.heuristic == h)
		param->heuri = "Hamming";
	else if (puzzle.heuristic == e)
		param->heuri = "Euclidian";
	else
		param->heuri = "Manhattan Distance";
	if (puzzle.search == astar)
		param->search = "A*";
	else if (puzzle.search == greedy)
		param->search = "Greedy";
	else
		param->search = "Uniform";
	param->complex_size = puzzle.nb_state_create - puzzle.nb_state_del;
	i = 0;
	state = puzzle.closed;
	while (state->next)
	{
		i++;
		state = state->next;
	}
	param->complex_time = i;
	return (OK);
}

static int		init_param(t_param **param, char *title, t_puzzle puzzle)
{
	if (!((*param) = (t_param *)ft_memalloc(sizeof(t_param))))
		return (KO);
	if (!((*param)->mlx = mlx_init_window(WIN_WIDTH, WIN_HEIGHT, title)))
	{
		free(*param);
		return (KO);
	}
	init_modes(*param, puzzle);
	(*param)->speed = 40;
	return (OK);
}

int				visu_init(t_param *p, t_state *state, t_puzzle puzzle)
{
	if (init_param(&p, T_WIN, puzzle) == KO)
		return (KO);
	p->state = state;
	if (!(p->moves = get_moves(state)))
	{
		error_print("Error print_step moves");
		return (KO);
	}
	p->current_step = 0;
	visu_print(p, state);
	mlx_hook(p->mlx->win, KEYPRESS, KPMASK, event_keyboard, p);
	mlx_loop_hook(p->mlx->ptr, event_loop, p);
	mlx_loop(p->mlx->ptr);
	del_param(p);
	return (OK);
}

static t_img	*new_map(t_mlx *mlx, int width, int height)
{
	t_img	*img;
	int		len[2];

	len[0] = width;
	len[1] = height;
	if (!(img = img_create(mlx, len)))
		return (NULL);
	return (img);
}

void			visu_print(t_param *p, t_state *state)
{
	t_img	*img;

	if ((img = new_map(p->mlx, WIN_WIDTH, WIN_HEIGHT)))
	{
		display_board(p->state, img);
		mlx_put_image_to_window(p->mlx->ptr, p->mlx->win, img->ptr, 0, 0);
		free_image(p, img);
	}
}
