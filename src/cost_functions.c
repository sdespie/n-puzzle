/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-spie <sde-spie@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 15:44:49 by sde-spie          #+#    #+#             */
/*   Updated: 2019/05/09 18:11:06 by adefonta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_puzzle.h"

int astar(t_state *state)
{
    state->eval = state->g + state->h;
    return (state->eval);
}

int greedy(t_state *state)
{
    state->eval = state->g;
    return (state->eval);
}

int uniform(t_state *state)
{
    state->eval = state->h;
    return (state->eval);
}
