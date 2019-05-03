/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adefonta <adefonta@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 22:14:10 by adefonta          #+#    #+#             */
/*   Updated: 2019/05/03 17:24:02 by adefonta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mlx.h"
#include "visu_struct.h"


void		free_image(t_param *param, t_img *img)
{
	if (img)
	{
		mlx_destroy_image(param->mlx->ptr, img->ptr);
		free(img);
	}
}

void		del_param(t_param *param)
{
	t_mlx	*mlx;

	if (param)
	{
		param->run = 0;
		free(param->moves);
		if ((mlx = param->mlx))
		{
			free_image(param, param->img);
			if (mlx->ptr && mlx->win)
			{
				mlx_clear_window(mlx->ptr, mlx->win);
				mlx_destroy_window(mlx->ptr, mlx->win);
				free(mlx->ptr);
			}
			free(mlx);
		}
		free(param);
	}
	exit(0);
}
