/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adefonta <adefonta@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 19:20:38 by adefonta          #+#    #+#             */
/*   Updated: 2019/05/03 17:29:49 by adefonta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"
#include "keycode.h"
#include "visu_macro.h"
#include "n_puzzle.h"
#include "mlx.h"

// int		event_loop(t_param *p)
// {
// 	if (p->run)
// 	{
// 	}
// 	else
// 		usleep(150000);
// 	return (OK);
// }

static void operate_move(t_state *state, char move)
{
	if (move == UP)
		up(state);
	else if (move == DOWN)
		down(state);
	else if (move == RIGHT)
		right(state);
	else if (move == LEFT)
		left(state);
}

int		event_loop(t_param *p)
{
	if (p->current_step < p->state->g)
	{
		visu_print(p, p->state);
		ft_printf("MOVE: %c \n", p->moves[p->current_step]);
		operate_move(p->state, p->moves[p->current_step]);
		usleep(100000);
		p->current_step++;
	}
	return (OK);
}


int		event_keyboard(int key, t_param *p)
{
	if (key == SP_KEY && !p->end)
		p->run = !p->run;
	if (key == ESC_KEY)
		del_param(p);
	else
	{
		if (key == NKMN_KEY && p->speed > SPEED_MIN)
			p->speed--;
		if (key == NKPL_KEY && p->speed < SPEED_MAX)
			p->speed++;
		// if (p->run == 0 && !p->end)
		// 	visu_print(p);
	}
	return (OK);
}
