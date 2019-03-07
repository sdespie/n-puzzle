/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrouvroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 11:17:45 by nrouvroy          #+#    #+#             */
/*   Updated: 2018/09/18 14:53:53 by nrouvroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_width_str(char *str, char c, t_conv *conv)
{
	long long int	l;
	char			*strb;

	l = conv->f[5] - ft_strlen(str);
	if (l <= 0)
		return (str);
	if (!(strb = ft_strnew(l)))
		return (NULL);
	strb = ft_memset(strb, c, l);
	str = conv->f[0] ? ft_strjoinff(str, strb) : ft_strjoinff(strb, str);
	return (str);
}

static char	*ft_type_s_prec(t_conv *conv, char *str)
{
	char *stb;

	stb = ft_strsub(str, 0, conv->f[7]);
	free(str);
	return (stb);
}

int			ft_type_s(va_list ap, t_conv *conv, t_data *data)
{
	char	*str1;
	char	*str;

	if (conv->f[6] == 'l')
	{
		conv->f[6] = 0;
		return (ft_type_gs(ap, conv, data));
	}
	str1 = va_arg(ap, char*);
	if (str1 == NULL)
		str = ft_strdup("(null)");
	else
		str = ft_strdup(str1);
	if (!str)
		return (ERROR);
	if (conv->f[9])
		if (!(str = ft_type_s_prec(conv, str)))
			return (ERROR);
	if (conv->f[5])
		if (!(str = ft_width_str(str, conv->f[1] && !conv->f[0] ?
						'0' : ' ', conv)))
			return (ERROR);
	ft_printaddstr(str, data);
	free(str);
	return (0);
}
