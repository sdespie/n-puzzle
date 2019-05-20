/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-spie <sde-spie@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 14:25:50 by sde-spie          #+#    #+#             */
/*   Updated: 2019/05/20 21:28:43 by sde-spie         ###   ########.fr       */
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

	if (board_init(puzzle) == KO)
		return (KO);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (puzzle->data == NULL && (!(puzzle->data = ft_strnew(0))))
			ft_memdel((void **)&line);
		if (line[0] != '#')
		{
			tmp = ft_strsplit(line, '#');
			puzzle->data = ft_strjoin_free(puzzle->data, " ", 0);
			puzzle->data = ft_strjoin_free(puzzle->data, tmp[0], 2);
			free(tmp);
		}
		ft_memdel((void **)&line);
	}
	return (put_data_in_board(puzzle));
}

int			parse_file(t_puzzle *puzzle, char *file)
{
	int		fd;
	char	*line;
	int		ret;

	if (puzzle->opened)
		return (KO);
	if ((fd = open(file, O_RDONLY)) < 0)
		return (error_exit(puzzle, "Error: can't read source file."));
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (line[0] != '#')
			break ;
		ft_memdel((void **)&line);
	}
	if (is_valid_number(puzzle, line))
		puzzle->board_size = ft_atoi2(line, puzzle);
	else
	{
		ft_memdel((void **)&line);
		return (error_exit(puzzle, "Error: Not valid board size."));
	}
	ft_memdel((void **)&line);
	puzzle->input = 1;
	return (parse_file2(puzzle, fd));
}

int			parse_cmd(t_puzzle *puzzle, int argc, char **argv, int index)
{
	if (argc != CMD_SIZE + 1)
	{
		print_usage(puzzle);
		return (KO);
	}
	if (index > CMD_SIZE)
		return (OK);
	if (parse_size(puzzle, argv[index]))
		index++;
	else if (puzzle->input == 0 && parse_file(puzzle, argv[index]))
		index++;
	else if (parse_mode(puzzle, argv[index]))
		index++;
	else if (argv[index][0] == '-')
		return (error_exit(puzzle, "Error: Invalid command."));
	else
		return (KO);
	return (parse_cmd(puzzle, argc, argv, index));
}
