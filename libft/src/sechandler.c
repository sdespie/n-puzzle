/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sechandler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrouvroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 17:10:34 by nrouvroy          #+#    #+#             */
/*   Updated: 2018/09/23 18:10:10 by nrouvroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_percent_hand(t_data *data)
{
	int	num;
	int imp;

	num = 1;
	imp = 0;
	while (*data->str && *data->str == '%')
	{
		num++;
		data->str++;
	}
	if (num % 2 == 1)
		imp = 1;
	num /= 2;
	while (num--)
		ft_printadd('%', data);
	return (imp);
}

char	*ft_strjoinfn(char *s1, const char *s2)
{
	char	*s;

	if (!s1 || !s2)
		return (NULL);
	if ((s = ft_strnew(ft_strlen(s1) + ft_strlen(s2))) != NULL)
	{
		s = ft_strcpy(s, s1);
		s = ft_strcat(s, s2);
	}
	free(s1);
	return (s);
}

char	*ft_strjoinnf(const char *s1, char *s2)
{
	char	*s;

	if (!s1 || !s2)
		return (NULL);
	if ((s = ft_strnew(ft_strlen(s1) + ft_strlen(s2))) != NULL)
	{
		s = ft_strcpy(s, s1);
		s = ft_strcat(s, s2);
	}
	free(s2);
	return (s);
}

char	*ft_strjoinff(char *s1, char *s2)
{
	char	*s;

	if (!s1 || !s2)
		return (NULL);
	if ((s = ft_strnew(ft_strlen(s1) + ft_strlen(s2))) != NULL)
	{
		s = ft_strcat(s, s1);
		s = ft_strcat(s, s2);
	}
	free(s1);
	free(s2);
	return (s);
}
