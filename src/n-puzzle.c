/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n-puzzle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-spie <sde-spie@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 14:25:50 by sde-spie          #+#    #+#             */
/*   Updated: 2019/04/05 03:41:16 by adefonta         ###   ########.fr       */
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
	puzzle.heuristic = manhanttan;
	if (check_valid_start(&puzzle) && solve(&puzzle))
	{
		print_state(puzzle.not_visited);
		check_error(puzzle.not_visited);
	}

//    solve();
//    print_sol();
   	free_all(&puzzle);
	return (1);
}
