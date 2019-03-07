/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrouvroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 16:28:26 by nrouvroy          #+#    #+#             */
/*   Updated: 2018/09/06 13:38:41 by nrouvroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printadd(char c, t_data *data)
{
	data->count++;
	write(1, &c, 1);
}

void	ft_printaddstr(char *s, t_data *data)
{
	int sl;

	sl = ft_strlen(s);
	data->count += sl;
	write(1, s, sl);
}

int		ft_getdigitnbr(int n)
{
	if (n != 0)
		return (1 + ft_getdigitnbr(n / 10));
	return (0);
}

char	ft_getlength(char *convl, t_conv *conv)
{
	if ((*convl == 'h' && conv->f[6]) || (*convl == 'l' &&
				conv->f[6] && conv->f[6] != 'h' && conv->f[6] != 'H'))
		return (conv->f[6]);
	else if (*convl == 'j')
		return ('j');
	else if (*convl == 'z')
		return ('z');
	else if (*convl == 'l')
	{
		if (*(convl + 1) == 'l')
		{
			conv->to_conv++;
			return ('L');
		}
		return ('l');
	}
	else
	{
		if (*(convl + 1) == 'h')
		{
			conv->to_conv++;
			return ('H');
		}
		return ('h');
	}
}

int		ft_process(va_list ap, t_conv *conv, t_data *data)
{
	int	(*ft_all[17])(va_list ap, t_conv *conv, t_data *data);

	if (conv->f[8] == 16)
		return (ft_empty_proc(conv, data));
	ft_all[0] = ft_type_s;
	ft_all[1] = ft_type_gs;
	ft_all[2] = ft_type_p;
	ft_all[3] = ft_type_d;
	ft_all[4] = ft_type_gd;
	ft_all[5] = ft_type_i;
	ft_all[6] = ft_type_o;
	ft_all[7] = ft_type_go;
	ft_all[8] = ft_type_u;
	ft_all[9] = ft_type_gu;
	ft_all[10] = ft_type_x;
	ft_all[11] = ft_type_gx;
	ft_all[12] = ft_type_c;
	ft_all[13] = ft_type_gc;
	ft_all[14] = ft_type_b;
	ft_all[15] = ft_type_per;
	return (ft_all[conv->f[8]](ap, conv, data));
}
