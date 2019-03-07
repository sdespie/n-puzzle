/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_u_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrouvroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 13:00:09 by nrouvroy          #+#    #+#             */
/*   Updated: 2018/09/19 11:42:29 by nrouvroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_type_u_len(va_list ap, t_conv *conv, int base)
{
	uintmax_t	nbr;

	nbr = 0;
	if (conv->f[6] == 0)
		nbr = (uintmax_t)(va_arg(ap, unsigned int));
	else if (conv->f[6] == 'z')
		nbr = (uintmax_t)(va_arg(ap, size_t));
	else if (conv->f[6] == 'j')
		nbr = (va_arg(ap, uintmax_t));
	else if (conv->f[6] == 'L')
		nbr = (uintmax_t)(va_arg(ap, unsigned long long int));
	else if (conv->f[6] == 'l')
		nbr = (uintmax_t)(va_arg(ap, unsigned long int));
	else if (conv->f[6] == 'h')
		nbr = (uintmax_t)(unsigned short)(va_arg(ap, unsigned int));
	else if (conv->f[6] == 'H')
		nbr = (uintmax_t)(unsigned char)(va_arg(ap, unsigned int));
	if (!nbr && conv->f[9] && !conv->f[7])
		return (ft_strdup("\0"));
	return (ft_pf_uitoa_base(nbr, base));
}

char	*ft_type_u_flags(char *str, t_conv *conv)
{
	long long int	l;
	char			*stb;

	while ((size_t)conv->f[7] > ft_strlen(str))
		if (!(str = ft_strjoinnf("0", str)))
			return (NULL);
	if (conv->f[8] == 2 && conv->f[9] && !conv->f[7])
		if (!(str = ft_strdup("0x")))
			return (NULL);
	if ((l = conv->f[5] - ft_strlen(str)) < 0)
	{
		if (conv->f[2] && (conv->f[8] == 10 || conv->f[8] == 2) &&
			ft_strcmp(str, "0"))
			return (*str ? ft_strjoinnf("0x", str) : str);
		else if (conv->f[2] && conv->f[8] == 11 && ft_strcmp(str, "0"))
			return (*str ? ft_strjoinnf("0X", str) : str);
		return (str);
	}
	if (!(stb = ft_strnew(l)))
		return (NULL);
	stb = conv->f[1] && !conv->f[0] && !conv->f[9] ? ft_memset(stb, '0', l) :
		ft_memset(stb, ' ', l);
	return (ft_type_u_util(conv, str, stb));
}

char	*ft_type_u_util(t_conv *conv, char *str, char *stb)
{
	char	*sb;

	if (conv->f[2] && (conv->f[8] == 10 || conv->f[8] == 11 || conv->f[8] == 2)
			&& ft_strcmp(str, "") && ft_strcmp(str, "0x"))
		stb = ft_type_u_utils_utils(stb);
	if (conv->f[0])
		sb = ft_type_u_m(conv, str, stb);
	else if (conv->f[9] && conv->f[2] && !conv->f[7] && (conv->f[8] == 10 ||
				conv->f[8] == 2) && !ft_strcmp("0", str))
	{
		sb = ft_mjoin(3, stb, "0x", str);
		free(str);
	}
	else if (conv->f[9] && conv->f[2] && !conv->f[7] && conv->f[8] == 11
			&& !ft_strcmp("0", str))
	{
		sb = ft_mjoin(3, stb, "0X", str);
		free(str);
	}
	else if (conv->f[9] && conv->f[2] && !conv->f[7])
		sb = ft_strjoinnf(stb, str);
	else
		sb = ft_type_u_e(conv, str, stb);
	free(stb);
	return (sb);
}

char	*ft_type_u_m(t_conv *conv, char *str, char *stb)
{
	char	*sb;

	sb = NULL;
	if (!(conv->f[2] && (conv->f[8] == 10 || conv->f[8] == 11 ||
				conv->f[8] == 2)) || (conv->f[2] && (conv->f[8] == 10 ||
				conv->f[8] == 11 || conv->f[8] == 2) && !ft_strcmp(str, "")))
		str = ft_strjoinfn(str, stb);
	if (conv->f[2] && (conv->f[8] == 10 || conv->f[8] == 2) && !(conv->f[9]
				&& !conv->f[7]))
		sb = ft_mjoin(3, "0x", str, stb);
	else if (conv->f[2] && conv->f[8] == 11 && !(conv->f[9] && !conv->f[7]))
		sb = ft_mjoin(3, "0X", str, stb);
	else if (conv->f[8] == 2 && !ft_strcmp("0x", str))
		sb = ft_strjoin(str, stb);
	else
		sb = ft_strdup(str);
	free(str);
	return (sb);
}

char	*ft_type_u_e(t_conv *conv, char *str, char *stb)
{
	char	*sb;

	sb = NULL;
	if ((!(conv->f[2] && (conv->f[8] == 10 || conv->f[8] == 11 ||
			conv->f[8] == 2))) || !*str)
		str = ft_strjoinnf(stb, str);
	if (conv->f[2] && (conv->f[8] == 10 || conv->f[8] == 2) && (!conv->f[1]
			|| (conv->f[1] && conv->f[9])))
		sb = ft_mjoin(3, stb, "0x", str);
	else if (conv->f[2] && conv->f[8] == 11 && (!conv->f[1] || (conv->f[1] &&
				conv->f[9])))
		sb = ft_mjoin(3, stb, "0X", str);
	else if (conv->f[2] && (conv->f[8] == 10 || conv->f[8] == 2) &&
			conv->f[1])
		sb = ft_mjoin(3, "0x", stb, str);
	else if (conv->f[2] && conv->f[8] == 11 && conv->f[1])
		sb = ft_mjoin(3, "0X", stb, str);
	else
		sb = ft_strdup(str);
	free(str);
	return (sb);
}
