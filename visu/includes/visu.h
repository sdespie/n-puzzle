/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adefonta <adefonta@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 15:54:20 by adefonta          #+#    #+#             */
/*   Updated: 2019/05/03 17:07:37 by adefonta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISU_H
# define VISU_H

# include "struct.h"
# include "visu_struct.h"
# include "stddef.h"
# include "libft.h"

int			visu_init(t_param *p, t_state *state);
void		visu_print(t_param *p, t_state *state);

void		del_param(t_param *param);
void		free_image(t_param *param, t_img *img);

int			img_color_bg(t_img *img, int start, int end, int color);
t_img		*img_create(t_mlx *mlx, int dim[2]);

int			event_loop(t_param *p);
int			event_keyboard(int key, t_param *p);

t_mlx		*mlx_init_window(int width, int height, char *title);

void		color_image(t_img img, int coord[2], int len[2], int color);
int			color_at_pos(t_img img, int pos, int color);

char		*strint(char *base, int data);
int			coord_to_pos(int x, int y, int width);
void		ft_bzero_double(double *s, size_t n);

void		display_string(t_mlx mlx, char *line, int coord[2], int color);
void		display_board(t_state *state, t_img *img);

#endif