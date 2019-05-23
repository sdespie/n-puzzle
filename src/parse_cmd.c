/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-spie <sde-spie@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 14:25:50 by sde-spie          #+#    #+#             */
/*   Updated: 2019/05/23 20:04:23 by adefonta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"
#include "macro.h"

int			parse_mode(t_puzzle *puzzle, char *value)
{
	if (!ft_strcmp(value, "-m"))
		puzzle->heuristic = manhanttan;
	else if (!ft_strcmp(value, "-h"))
		puzzle->heuristic = h;
	else if (!ft_strcmp(value, "-e"))
		puzzle->heuristic = e;
	else if (!ft_strcmp(value, "-greedy"))
		puzzle->search = greedy;
	else if (!ft_strcmp(value, "-astar"))
		puzzle->search = astar;
	else if (!ft_strcmp(value, "-uniform"))
		puzzle->search = uniform;
	else
		return (KO);
	return (OK);
}

int			parse_file2(t_puzzle *puzzle, int fd)
{
	int		ret;
	char	*line;
	char	**tmp;
	int		i;
	int		state;

	state = OK;
	i = 0;
	if (board_init(puzzle) == KO)
		return (KO);
	while (state == OK && (ret = get_next_line(fd, &line)) > 0)
	{
		if (puzzle->data == NULL && (!(puzzle->data = ft_strnew(0))))
			state = KO;
		if (state == OK && line[0] != '#')
		{
			tmp = ft_strsplit(line, '#');
			if (!tmp || !(puzzle->data = ft_strjoin_free(puzzle->data, " ", 0))
			|| !(puzzle->data = ft_strjoin_free(puzzle->data, tmp[0], 0)))
				state = KO;
			del_split(tmp);
		}
		ft_memdel((void **)&line);
	}
	return ((state == KO) ? error_exit(EMALLOC) : put_data_in_board(puzzle));
}

int			parse_file(t_puzzle *puzzle, char *file)
{
	int		fd;
	char	*line;
	int		ret;

	line = NULL;
	if (puzzle->opened)
		return (KO);
	if ((fd = open(file, O_RDONLY)) < 0)
		return (error_exit("Error: can't read source file."));
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (line[0] != '#')
			break ;
		ft_memdel((void **)&line);
	}
	if (ret > 0 && is_valid_number(puzzle, line))
		puzzle->board_size = ft_atoi2(line, puzzle);
	if (puzzle->board_size < 3)
	{
		ft_memdel((void **)&line);
		return (error_exit("Error: Not valid board."));
	}
	ft_memdel((void **)&line);
	puzzle->input = 1;
	return (parse_file2(puzzle, fd));
}

int			parse_cmd(t_puzzle *puzzle, int argc, char **argv, int index)
{
	int size;

	if (argc != CMD_SIZE + 1)
	{
		print_usage(puzzle);
		return (KO);
	}
	if (index > CMD_SIZE)
		return (OK);
	if ((size = parse_size(puzzle, argv[index])) == OK)
		index++;
	else if (size == ERROR)
		return (error_exit("Error: Invalid board size."));
	else if (parse_mode(puzzle, argv[index]))
		index++;
	else if (puzzle->input == 0)
	{
		if (parse_file(puzzle, argv[index]))
			index++;
		else
			return (KO);
	}
	else
		return (error_exit("Error: Invalid command."));
	return (parse_cmd(puzzle, argc, argv, index));
}
