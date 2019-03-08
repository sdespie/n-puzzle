/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-spie <sde-spie@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 14:25:50 by sde-spie          #+#    #+#             */
/*   Updated: 2019/01/16 16:35:02 by sde-spie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"

void print_usage(t_puzzle *puzzle)
{
    ft_printf("Usage : n-puzzle [file / size] [-m -... -...]");
    free_all(puzzle);
    exit(0);
}

void error_exit(t_puzzle *puzzle, char *str)
{
    ft_printf("%s\n", str);
    free_all(puzzle);
    exit(0);
}
