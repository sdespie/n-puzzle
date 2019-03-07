/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-spie <sde-spie@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 14:25:50 by sde-spie          #+#    #+#             */
/*   Updated: 2019/01/16 16:35:02 by sde-spie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"

int  *create_list(t_puzzle puzzle)
{
    int *list;
    int     i;
    int     j;
    int     pos;

    i = 0;
    pos = 0;
    list = malloc(sizeof(int) * (puzzle.board_size * puzzle.board_size - 1));
    while (i < puzzle.board_size)
    {
        j = 0;
        while (j < puzzle.board_size)
        {
            if (puzzle.board[i][j] != 0)
                list[pos++] = puzzle.board[i][j];
                printf("% d", list[pos - 1]);
            j++;
        }
        i++;
    }
    return (list);
}

void check_error(t_puzzle puzzle)
{
    int i;
    int j;
    int *list;
    int size;
    int inversion;

    inversion = 0;
    size = puzzle.board_size;
    list = create_list(puzzle);

    i = 0;
    while (i < size * size - 1)
    {
        j = i + 1;
        while (j < size * size - 1)
        {
            if (list[i] > list[j++])
                inversion++;
        }
        i++;
    }
    if (inversion % 2)
        printf("\nBoard not valid.\n");
    else
        printf("\nBoard valid.\n");

}
