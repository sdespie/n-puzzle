/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrouvroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 12:04:07 by nrouvroy          #+#    #+#             */
/*   Updated: 2018/09/17 18:42:09 by nrouvroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_type_d_len(va_list ap, t_conv *conv)
{
	intmax_t	nbr;

	nbr = 0;
	if (conv->f[6] == 0)
		nbr = (intmax_t)(va_arg(ap, int));
	else if (conv->f[6] == 'z')
		nbr = (intmax_t)(va_arg(ap, size_t));
	else if (conv->f[6] == 'j')
		nbr = (va_arg(ap, intmax_t));
	else if (conv->f[6] == 'L')
		nbr = (intmax_t)(va_arg(ap, long long));
	else if (conv->f[6] == 'l')
		nbr = (intmax_t)(va_arg(ap, long));
	else if (conv->f[6] == 'h')
		nbr = (intmax_t)(short)(va_arg(ap, int));
	else if (conv->f[6] == 'H')
		nbr = (intmax_t)(signed char)(va_arg(ap, int));
	if (!nbr && conv->f[9] && !conv->f[7])
		return (ft_strdup("\0"));
	return (ft_pf_itoa(nbr));
}

char	*ft_type_d_flags(char *str, t_conv *conv)
{
	char		*stb;
	intmax_t	l;

	if (conv->f[7] && (*str == '-'))
		conv->f[7]++;
	while ((size_t)conv->f[7] > ft_strlen(str) && *str != '-')
		if (!(str = ft_strjoinnf("0", str)))
			return (NULL);
	while ((size_t)conv->f[7] > ft_strlen(str) && *str == '-')
	{
		if (!(str = ft_strjoinnf("-", str)))
			return (NULL);
		*(str + 1) = '0';
	}
	if ((l = conv->f[5] - ft_strlen(str)) <= 0)
	{
		if (conv->f[3] && *str != '-')
			if (!(str = ft_strjoinnf("+", str)))
				return (NULL);
		return (conv->f[4] && !conv->f[3] && *str != '-' ?
				ft_strjoinnf(" ", str) : str);
	}
	if (!(stb = ft_strnew(l)))
		return (NULL);
	return (ft_type_d_util(str, conv, l, stb));
}

char	*ft_type_d_util(char *str, t_conv *conv, intmax_t l, char *stb)
{
	stb = conv->f[1] && !conv->f[0] && !conv->f[9] ? ft_memset(stb, '0', l) :
		ft_memset(stb, ' ', l);
	if (conv->f[4] && conv->f[0] && *str != '-')
	{
		stb[ft_strlen(stb) - 1] = '\0';
		if (!(str = ft_strjoinnf(" ", str)))
			return (NULL);
	}
	else if (conv->f[4] && !conv->f[0] && !conv->f[9] && *str != '-')
		*stb = ' ';
	if (conv->f[0] && conv->f[3] && *str != '-')
		stb[ft_strlen(stb) - 1] = '\0';
	if (conv->f[0])
		str = ft_strjoinfn(conv->f[3] && *str != '-' ? ft_strjoinnf("+", str)
				: str, stb);
	else
		str = ft_type_d_utils(str, stb, conv);
	if (!str)
		return (NULL);
	*str = conv->f[3] && *str == '0' && *str != '-' ? '+' : *str;
	str = ft_type_d_der_mdr(conv, str, l);
	free(stb);
	return (ft_type_d_der(conv, str));
}

char	*ft_type_d_utils(char *str, char *stb, t_conv *conv)
{
	char	*strb;

	if (*str != '-' || !conv->f[1])
		strb = ft_strjoinnf(stb, str);
	else if (conv->f[1])
	{
		str = ft_strcpy(str, str + 1);
		if (conv->f[9])
			strb = ft_mjoin(3, stb, "-", str);
		else
			strb = ft_mjoin(3, "-", stb, str);
		free(str);
	}
	else
		strb = str;
	if (!strb)
		return (NULL);
	return (strb);
}

int		ft_type_d(va_list ap, t_conv *conv, t_data *data)
{
	char	*str;

	if (!(str = ft_type_d_len(ap, conv)))
		return (ERROR);
	if (!ft_noflags(conv))
		if (!(str = ft_type_d_flags(str, conv)))
			return (ERROR);
	ft_printaddstr(str, data);
	free(str);
	return (0);
}
