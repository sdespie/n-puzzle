/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-spie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 19:11:54 by sde-spie          #+#    #+#             */
/*   Updated: 2019/05/20 22:13:15 by sde-spie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"
#include "macro.h"

void		del_split(char **split)
{
	int	nb_words;

	nb_words = ft_strlen(*split);
	while (nb_words-- > 0)
		if (split[nb_words] != NULL)
			free(split[nb_words]);
	if (split != NULL)
		ft_memdel((void**)&split);
}

int			put_data_in_board(t_puzzle *puzzle)
{
	int		i;
	size_t	data_len;
	char	**split;

	i = -1;
	split = ft_strsplit(puzzle->data, ' ');
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
			return (KO);
	}
	board_copy(puzzle->opened->board, puzzle->base, puzzle->board_count);
	puzzle->opened->zero = puzzle->zero_base;
	del_split(split);
	return (OK);
}

int			parse_size(t_puzzle *puzzle, char *size)
{
	if (puzzle->opened)
		return (KO);
	if (is_valid_number(puzzle, size))
	{
		puzzle->board_size = ft_atoi2(size, puzzle);
		return (board_init(puzzle));
	}
	return (KO);
}
