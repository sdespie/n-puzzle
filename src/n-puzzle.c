/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n-puzzle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-spie <sde-spie@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 14:25:50 by sde-spie          #+#    #+#             */
/*   Updated: 2019/01/16 16:35:02 by sde-spie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"


//TODO:
//CONTINUE PARSE_FILE
// CHECK_ERROR NON FONCTIONNEL
// VERIFIER ERREOR FILE
// PROTEGER ERROR MALLOC


void print_board(t_puzzle puzzle)
{
    int i;
    int j;

    printf("\n++++++++ BOARD ++++++\n");
    i = 0;
    while (i < puzzle.board_size)
    {
        j = 0;
        while (j < puzzle.board_size)
            printf("% .2d", puzzle.board[i][j++]);
        i++;
        printf("\n");
    }
    printf("\n");

    printf("\n+++++++++ GOAL ++++++\n");
    i = 0;
    j = 0;
    while (i < puzzle.board_size)
    {
        j = 0;
        while (j < puzzle.board_size)
            printf("% .2d", puzzle.goal[i][j++]);
        i++;
        printf("\n");
    }
    printf("\n");
}

int main(int argc, char **argv)
{
    t_puzzle    puzzle;

    ft_memset((void *)&puzzle, 0, sizeof(t_puzzle));
    parse_cmd(&puzzle, argc, argv, 1);
    print_board(puzzle);
//    int i = puzzle->board[0][1];
//    puzzle->board[0][1] = puzzle->board[0][0];
//    puzzle->board[0][0] = i;
    check_error(puzzle);
//    solve();
//    print_sol();
//    free_all();
}
