/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n-puzzle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-spie <sde-spie@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 14:25:50 by sde-spie          #+#    #+#             */
/*   Updated: 2019/04/12 13:40:40 by adefonta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"

//TODO:
//CONTINUE PARSE_FILE
// CHECK_ERROR NON FONCTIONNEL
// VERIFIER ERREOR FILE
// PROTEGER ERROR MALLOC

int main(int argc, char **argv)
{
    t_puzzle    puzzle;

    ft_memset((void *)&puzzle, 0, sizeof(t_puzzle));
    if (parse_cmd(&puzzle, argc, argv, 1) == KO)
		return (0);
    ft_printf("++++++++++++++++\n");
    print_board(puzzle.base, puzzle.board_count, puzzle.board_size);
    check_error(puzzle.opened);
	if (check_valid_start(&puzzle) && hash_init(&puzzle) &&
		sorttable_init(&puzzle) && solve(&puzzle))
	{
		board_copy(puzzle.opened->board, puzzle.base, puzzle.board_count);
		puzzle.opened->zero = puzzle.zero_base;
		print_step(puzzle.opened);
		ft_printf("nb_state:-create: %10d :-del: %10d\n", puzzle.nb_state_create, puzzle.nb_state_del);
	}
   	free_all(&puzzle);
	return (1);
}
