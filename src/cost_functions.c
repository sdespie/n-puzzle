/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-spie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 15:44:49 by sde-spie          #+#    #+#             */
/*   Updated: 2019/05/04 15:44:51 by sde-spie         ###   ########.fr       */
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
