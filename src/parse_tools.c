/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-spie <sde-spie@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 19:11:54 by sde-spie          #+#    #+#             */
/*   Updated: 2019/05/23 00:19:20 by adefonta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"
#include "macro.h"

int			del_split(char **split)
{
	int	i;

	i = -1;
	while (split[++i])
		free(split[i]);
	free(split);
	return (OK);
}

static int	ft_strrlen(char const *s, char c)
{
	int i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

static char	**ft_strnsplit(char const *s, int count, char c)
{
	char	**tab;
	int		i;
	int		len;

	i = 0;
	if (!s || count < 0)
		return (NULL);
	if ((tab = (char **)malloc(sizeof(*tab) * (count + 1))) == NULL)
		return (NULL);
	while (count--)
	{
		while (*s == c && *s)
			s++;
		len = ft_strrlen(s, c);
		if ((tab[i++] = ft_strsub(s, 0, len)) == NULL)
			return (NULL);
		s += len;
	}
	tab[i] = NULL;
	return (tab);
}

int			put_data_in_board(t_puzzle *puzzle)
{
	int		i;
	size_t	data_len;
	char	**split;

	i = -1;
	if (!(split = ft_strnsplit(puzzle->data, puzzle->board_count, ' ')))
		return (error_exit(EMALLOC));
	data_len = 0;
	while (split[++i] != '\0')
		data_len++;
	i = -1;
	while (++i < puzzle->board_count)
	{
		if (is_valid_number(puzzle, split[i]))
		{
			puzzle->base[i] = ft_atoi2(split[i], puzzle);
			if (puzzle->base[i] == 0)
				puzzle->zero_base = i;
		}
		else
			return (del_split(split) && error_exit("Error: Not valid board."));
	}
	board_copy(puzzle->opened->board, puzzle->base, puzzle->board_count);
	puzzle->opened->zero = puzzle->zero_base;
	return (del_split(split));
}

int			parse_size(t_puzzle *puzzle, char *size)
{
	if (puzzle->opened)
		return (KO);
	if (is_valid_number(puzzle, size))
	{
		puzzle->board_size = ft_atoi2(size, puzzle);
		if (puzzle->board_size >= 3)
			return (board_init(puzzle));
		else
			return (ERROR);
	}
	return (KO);
}
