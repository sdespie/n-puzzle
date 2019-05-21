/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_puzzle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-spie <sde-spie@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 14:25:50 by sde-spie          #+#    #+#             */
/*   Updated: 2019/05/20 22:03:50 by sde-spie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"
#include "visu_struct.h"
#include "visu.h"

int	main(int argc, char **argv)
{
	t_puzzle	puzzle;
	t_param		*visu;

	visu = NULL;
	ft_memset((void *)&puzzle, 0, sizeof(t_puzzle));
	if (parse_cmd(&puzzle, argc, argv, 1) == KO || puzzle.board_size < 3)
	{
		free_all(&puzzle);
		return (0);
	}
	//ft_printf("++++++++++++++++\n");
	print_board(puzzle.base, puzzle.board_count, puzzle.board_size);
	if (check_valid_start(&puzzle) && hash_init(&puzzle) &&
		sorttable_init(&puzzle) && solve(&puzzle))
	{
		board_copy(puzzle.opened->board, puzzle.base, puzzle.board_count);
		puzzle.opened->zero = puzzle.zero_base;
		ft_printf("nb_state:-create: %10d :-del: %10d\n",
								puzzle.nb_state_create, puzzle.nb_state_del);
		visu_init(visu, puzzle.opened, puzzle);
	}
	free_all(&puzzle);
	return (1);
}
