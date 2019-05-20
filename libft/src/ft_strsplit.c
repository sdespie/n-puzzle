/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrouvroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 14:28:21 by nrouvroy          #+#    #+#             */
/*   Updated: 2019/05/20 22:09:37 by sde-spie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_word_len(char const *str, char c)
{
	int len;

	len = 0;
	while (*str == c)
		str++;
	while (*str != c && *str++ != '\0')
		len++;
	return (len);
}

char		**ft_strsplit(const char *str, char c)
{
	char	**ret;
	int		nb_words;
	int		index;

	index = 0;
	if (!str)
		return (NULL);
	nb_words = ft_countwords(str, c);
	if (!(ret = (char**)malloc(sizeof(ret) * (nb_words + 1))))
		return (NULL);
	while (nb_words--)
	{
		while (*str == c && *str != '\0')
			str++;
		ret[index] = ft_strsub(str, 0, ft_get_word_len(str, c));
		if (ret[index] == NULL)
			return (NULL);
		str = str + ft_get_word_len(str, c);
		index++;
	}
	ret[index] = NULL;
	return (ret);
}
