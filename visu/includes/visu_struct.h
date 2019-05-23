/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_struct.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adefonta <adefonta@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 16:13:00 by adefonta          #+#    #+#             */
/*   Updated: 2019/05/23 20:28:03 by adefonta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISU_STRUCT_H
# define VISU_STRUCT_H

# include "struct.h"

typedef struct	s_img
{
	int		index;
	int		win_pos[2];
	int		dim[2];
	int		sizeline;
	int		size;
	int		endian;
	int		opp;
	int		start;
	int		org[2];
	int		piece_size;
	void	*ptr;
	int		*data;
}				t_img;

typedef struct	s_mlx
{

	int		dim[2];
	int		color;
	void	*ptr;
	void	*win;
}				t_mlx;

typedef struct	s_param
{
	int				press;
	int				ready;
	int				m_color;
	int				i_color;
	int				b_mode;
	int				run;
	int				end;
	int				colors[3];
	int				speed;
	int				display_num;
	int				current_step;
	int				complex_time;
	int				complex_size;
	char			*moves;
	char			*heuri;
	char			*search;
	t_mlx			*mlx;
	t_img			*img;
	t_puzzle		*puzzle;
	t_state			*state;
}				t_param;

typedef struct	s_tdata
{
	t_param	*p;
	t_img	*img;
}				t_tdata;

#endif
