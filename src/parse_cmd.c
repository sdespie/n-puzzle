/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-spie <sde-spie@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 14:25:50 by sde-spie          #+#    #+#             */
/*   Updated: 2019/01/16 16:35:02 by sde-spie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"

// modes && fonctions to be define


int     parse_mode(t_puzzle *puzzle, char *value)
{
    if(!ft_strcmp(value, "-m"))
        puzzle->heuristic = manhanttan;
    else if(!ft_strcmp(value, "-h"))
        puzzle->heuristic = h;
    else if(!ft_strcmp(value, "-p"))
        puzzle->heuristic = p;
    else
        return (0);
    return (1);
}

int     parse_size(t_puzzle *puzzle, char *size)
{
    if (is_valid_number(puzzle, size))
        puzzle->board_size = ft_atoi2(size, puzzle);
    else
        return (0);
    init_board(puzzle);
    return (1);
}

int     parse_file(t_puzzle *puzzle, char *file)
{
    int     fd;
    char    *line;
    int     ret;

    if ((fd = open(file, O_RDONLY)) < 0)
        error_exit(puzzle, "Error: can't read source file.");
    while (19)
    {
        ret = get_next_line(fd, &line);
        if (line[0] != '#')
            break;
        free(&line);
    }
    ret = get_next_line(fd, &line);
    if (is_valid_number(puzzle, line))
        puzzle->board_size = ft_atoi2(line, puzzle);
    else
        error_exit(puzzle, "Error: Not valid board size.");
    puzzle->input = 1;
    init_board(puzzle);
    while (ret = get_next_line(fd, &line))
    {
        if (puzzle->data == NULL)
            puzzle->data = ft_strnew(0);
        if (line[0] != '#')
            puzzle->data = ft_strjoin_free(puzzle->data, line, 2);
    }
    //put_data_in_board(puzzle);
    return(1);
}

void   parse_cmd(t_puzzle *puzzle, int argc, char **argv, int index)
{
    if (argc != CMD_SIZE + 1)
    {
        print_usage(puzzle);
        return ;
    }
    else if (index > CMD_SIZE)
        return ;
    else if (parse_mode(puzzle, argv[index]))
        index++;
    else if (argv[index][0] == '-')
        error_exit(puzzle, "Error: Invalid command.");
    else if (parse_size(puzzle, argv[index]))
        index++;
    else if (parse_file(puzzle, argv[index]))
        index++;
    else
        return ;
    parse_cmd(puzzle, argc, argv, index);
}
