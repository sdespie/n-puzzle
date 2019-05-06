/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adefonta <adefonta@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 22:07:57 by adefonta          #+#    #+#             */
/*   Updated: 2019/05/06 16:26:42 by adefonta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"
#include "visu_macro.h"
#include "mlx.h"

void		color_window(t_mlx mlx, int coord[2], int len[2], int color)
{
	int	i;
	int	j;

	j = -1;
	while (++j < len[1])
	{
		i = -1;
		while (++i < len[0])
			mlx_pixel_put(mlx.ptr, mlx.win, coord[0] + i, coord[1] + j, color);
	}
}

int			color_at_pos(t_img img, int pos, int color)
{
	if (pos < 0 || pos >= img.size)
		return (KO);
	img.data[pos] = color;
	return (OK);
}

void		color_image(t_img img, int coord[2], int len[2], int c)
{
	int	i;
	int	j;

	j = -1;
	while (++j < len[1])
	{
		i = -1;
		while (++i < len[0])
			img.data[coord_to_pos(coord[0] + i, coord[1] + j, WIN_WIDTH)] = c;
	}
}

static int	ft_rapport(int first, int second, double p)
{
	if (first == second)
		return (first);
	return ((int)((double)first + (second - first) * p));
}

int			color_mix(int c1, int c2, double p)
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
