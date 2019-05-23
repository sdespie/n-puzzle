/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adefonta <adefonta@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 19:20:38 by adefonta          #+#    #+#             */
/*   Updated: 2019/05/21 19:53:58 by adefonta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"
#include "keycode.h"
#include "visu_macro.h"
#include "n_puzzle.h"
#include "mlx.h"

static void	operate_move(t_state *state, char move)
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

int			event_loop(t_param *p)
{
	int turn;

	if (p->run && p->current_step <= p->state->g)
	{
		turn = (p->speed > 100) ? (p->speed - 100) / 10 : 1;
		if (p->current_step + turn > p->state->g)
			turn = p->state->g - p->current_step;
		while (turn-- > 0 && p->current_step <= p->state->g)
			operate_move(p->state, p->moves[p->current_step++]);
		visu_print(p, p->state);
		usleep(50000000 / (p->speed * p->speed));
	}
	else
		usleep(150000);
	return (OK);
}

int			event_keyboard(int key, t_param *p)
{
	if (key == SP_KEY && !p->end)
		p->run = !p->run;
	if (key == ESC_KEY)
		del_param(p);
	else
	{
		if (key == NKMN_KEY && p->speed > SPEED_MIN)
			p->speed -= 10;
		if (key == NKPL_KEY && p->speed < SPEED_MAX)
			p->speed += 10;
		if (key == N_KEY)
			p->display_num = !p->display_num;
	}
	return (OK);
}
