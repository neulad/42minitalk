/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_body.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukireyeu < ukireyeu@student.42warsaw.pl    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 17:52:54 by ukireyeu          #+#    #+#             */
/*   Updated: 2024/05/04 19:26:10 by ukireyeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/handle_body.h"
#include "../server.h"
#include "./headers/signals.h"
#include "../../utils/headers/strings.h"
#include "../../lib/headers/ft_printf.h"
#include <stdlib.h>
#include "signal.h"

static void	check_body(t_state *state)
{
	if (!(state->body))
	{
		state->body = malloc(sizeof(char) * (state->n_symbols + 1));
		*(state->body) = '\0';
	}
}

static void	fill_alpha(t_state *state, int sig)
{
	if (sig == SIGUSR1)
		state->temp_alpha |= 1 << state->sig_counter;
}

static void	add_alpha(t_state *state)
{
	char	*cpbody;

	cpbody = state->body;
	while (*cpbody)
		++cpbody;
	*cpbody = state->temp_alpha;
	cpbody[1] = '\0';
	++(state->alpha_counter);
}

static int	alpha_ready(t_state *state)
{
	if (state->sig_counter == 7)
	{
		add_alpha(state);
		state->temp_alpha = 0;
		state->sig_counter = 0;
		if (state->alpha_counter == state->n_symbols)
		{
			ft_printf("%s\n", state->body);
			free(state->body);
			init_state(state);
			return (1);
		}
		kill(state->pid, SIGUSR1);
		return (1);
	}
	kill(state->pid, SIGUSR1);
	return (0);
}

void	handle_body(t_state *state, int sig)
{
	check_body(state);
	fill_alpha(state, sig);
	if (!alpha_ready(state))
		++(state->sig_counter);
}
