/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrouvroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 13:43:38 by nrouvroy          #+#    #+#             */
/*   Updated: 2018/06/20 17:40:39 by nrouvroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

static int	ft_isempty(const char *str)
{
	int empt;
	int i;

	i = 0;
	empt = 1;
	while (str[i])
		if (!ft_isspace(str[i++]))
			empt = 0;
	return (empt);
}

char		*ft_strtrim(char const *str)
{
	char	*s;
	int		i;
	int		len;

	if (str == NULL)
		return (NULL);
	i = 0;
	if (ft_isempty(str))
		return (ft_strnew(1));
	len = ft_strlen(str);
	i = -1;
	while (ft_isspace(str[len - 1]))
		len--;
	while (ft_isspace(str[++i]))
		len--;
	if ((s = ft_strnew(len)) == NULL)
		return (NULL);
	str += i;
	i = -1;
	while (++i < len)
		s[i] = *str++;
	s[i] = '\0';
	return (s);
}
