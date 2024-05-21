/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_n_symbols.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukireyeu < ukireyeu@student.42warsaw.pl    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 20:09:38 by ukireyeu          #+#    #+#             */
/*   Updated: 2024/05/04 20:52:58 by ukireyeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "../client.h"

static int	signal_mapper(int bit)
{
	if (bit)
		return (SIGUSR1);
	return (SIGUSR2);
}

void	send_n_symbols_signal(t_state *state)
{
	int	bit;

	bit = !!((state->n_symbols) & (1 << state->counter));
	if (state->counter == sizeof(int) * 8 - 1)
	{
		state->n_symbols_sent = 1;
		state->counter = 0;
		kill(state->pid_server, signal_mapper(bit));
		return ;
	}
	++(state->counter);
	kill(state->pid_server, signal_mapper(bit));
}
