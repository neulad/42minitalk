/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_body.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukireyeu < ukireyeu@student.42warsaw.pl    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 20:45:11 by ukireyeu          #+#    #+#             */
/*   Updated: 2024/05/04 20:52:11 by ukireyeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../client.h"
#include "../../lib/headers/ft_printf.h"
#include <stdlib.h>

static int	signal_mapper(int bit)
{
	if (bit)
		return (SIGUSR1);
	return (SIGUSR2);
}

void	send_body(t_state *state)
{
	int	bit;

	bit = !!((state->body)[state->alpha_counter] & (1 << state->counter));
	if (state->counter == 7)
	{
		state->counter = 0;
		++(state->alpha_counter);
		kill(state->pid_server, signal_mapper(bit));
		if (state->alpha_counter >= state->n_symbols)
			exit(EXIT_SUCCESS);
		return ;
	}
	++(state->counter);
	kill(state->pid_server, signal_mapper(bit));
}
