/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adefonta <adefonta@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 18:14:03 by adefonta          #+#    #+#             */
/*   Updated: 2019/05/23 20:42:56 by adefonta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"
#include "mlx.h"
#include "visu_macro.h"
#include <math.h>

t_mlx		*mlx_init_window(int width, int height, char *title)
{
	t_mlx	*mlx;

	if (!(mlx = (t_mlx *)malloc(sizeof(t_mlx))))
		return (NULL);
	if (!(mlx->ptr = mlx_init()))
	{
		free(mlx);
		return (NULL);
	}
	if (!(mlx->win = mlx_new_window(mlx->ptr, width, height, title)))
	{
		free(mlx);
		return (NULL);
	}
	mlx->dim[0] = width;
	mlx->dim[1] = height;
	mlx->color = COLOR;
	return (mlx);
}
