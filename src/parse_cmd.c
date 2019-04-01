/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-spie <sde-spie@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 14:25:50 by sde-spie          #+#    #+#             */
/*   Updated: 2019/04/01 21:24:23 by adefonta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"
#include "macro.h"
// modes && fonctions to be define


static	int	parse_mode(t_puzzle *puzzle, char *value)
{
    if(!ft_strcmp(value, "-m"))
        puzzle->heuristic = manhanttan;
    else if(!ft_strcmp(value, "-h"))
        puzzle->heuristic = h;
    else if(!ft_strcmp(value, "-p"))
        puzzle->heuristic = p;
    return (!puzzle->heuristic);
}

static	int	parse_size(t_puzzle *puzzle, char *size)
{
	int	state;

	state = OK;
	if (puzzle->queue)
		return (state);
	if (is_valid_number(puzzle, size))
    {
		puzzle->board_size = ft_atoi2(size, puzzle);
		state = board_init(puzzle);
	}
    return (state);
}

static	int	parse_file(t_puzzle *puzzle, char *file)
{
    int     fd;
    char    *line;
    int     ret;
	int		state;

	state = OK;
	if (puzzle->queue)
		return (state);
    if ((fd = open(file, O_RDONLY)) < 0)
        return (error_exit(puzzle, "Error: can't read source file."));
    while ((ret = get_next_line(fd, &line)) > 0)
    {
        if (line[0] != '#')
            break;
        ft_memdel((void **)&line);
    }
	ft_memdel((void **)&line);
    if ((ret = get_next_line(fd, &line)) > 0)
	{
	    if (is_valid_number(puzzle, line))
	        puzzle->board_size = ft_atoi2(line, puzzle);
	    else
		{
			ft_memdel((void **)&line);
			return (error_exit(puzzle, "Error: Not valid board size."));
		}
		ft_memdel((void **)&line);
	    puzzle->input = 1;
	    if (board_init(puzzle) == KO)
			return (KO);
	    // while ((ret = get_next_line(fd, &line)) > 0)
	    // {
	    //     if (puzzle->data == NULL && (!(puzzle->data = ft_strnew(0)))
		// 		ft_memdel((void **)&line);
	    //     if (line[0] != '#')
	    //         puzzle->data = ft_strjoin_free(puzzle->data, line, 2);
	    // }
    	//put_data_in_board(puzzle);
	}
    return(OK);
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
	if (!parse_size(puzzle, argv[index]))
        return (KO);
    else if (!parse_file(puzzle, argv[index]))
		return (KO);
	else if (!parse_mode(puzzle, argv[index]))
        return (KO);
	else if (argv[index][0] == '-')
        return (error_exit(puzzle, "Error: Invalid command."));
    else
        return (OK);
    return (parse_cmd(puzzle, argc, argv, ++index));
}
