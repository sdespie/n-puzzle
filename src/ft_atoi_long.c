/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-spie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 19:10:55 by sde-spie          #+#    #+#             */
/*   Updated: 2019/05/20 19:06:59 by sde-spie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"

static	int	is_char(char c, t_puzzle *puzzle)
{
	if (c == '-' || c == '+')
		return (++puzzle->error_sign);
	else if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	else if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int			ft_atoi2(char *s, t_puzzle *puzzle)
{
	int		sign;
	long	r;
	int		i;

	puzzle->error_sign = 0;
	puzzle->error_p = 0;
	i = 0;
	while (is_char(s[i], puzzle))
		i++;
	(s[i] == 0 && puzzle->error_sign <= 1) ? 0 : puzzle->error_p++;
	r = 0;
	while (*s == 32 || (*s >= 9 && *s <= 13))
		s++;
	sign = *s == '-' ? -1 : 1;
	(*s == '+' || *s == '-') ? s++ : 0;
	(*s < '0' || *s > '9') ? puzzle->error_p++ : 0;
	while (*s >= '0' && *s <= '9')
	{
		r = r * 10 + *s - '0';
		s++;
		if (sign * r > 2147483647 || sign * r < -2147483648)
			return (sign > 0 ? -1 : 0);
	}
	(*s != 0) ? puzzle->error_p++ : 0;
	return ((int)(sign * r));
}

long		ft_atol2(char *s, t_puzzle *puzzle)
{
	int		sign;
	long	r;
	int		i;

	puzzle->error_sign = 0;
	i = 0;
	while (is_char(s[i], puzzle))
		i++;
	(s[i] == 0 && puzzle->error_sign <= 1) ? 0 : puzzle->error_p++;
	r = 0;
	while (*s == 32 || (*s >= 9 && *s <= 13))
		s++;
	sign = *s == '-' ? -1 : 1;
	if (*s == '+' || *s == '-')
		s++;
	while (*s >= '0' && *s <= '9')
	{
		r = r * 10 + *s - '0';
		s++;
		if (r > 9223372036854775807)
			return (sign > 0 ? -1 : 0);
	}
	*s != 0 ? puzzle->error_p++ : 0;
	return ((int)(sign * r));
}
