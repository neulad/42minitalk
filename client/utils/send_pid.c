/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_pid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukireyeu < ukireyeu@student.42warsaw.pl    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:12:47 by ukireyeu          #+#    #+#             */
/*   Updated: 2024/05/04 20:51:59 by ukireyeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../client.h"
#include "./headers/send_pid.h"
#include "../../lib/headers/ft_printf.h"
#include <signal.h>
#include <unistd.h>

static int	signal_mapper(int bit)
{
	if (bit)
		return (SIGUSR1);
	return (SIGUSR2);
}

static void	send_pid_signal(t_state *state)
{
	int	bit;

	bit = !!((state->pid_client) & (1 << state->counter));
	if (state->counter == sizeof(int) * 8 - 1)
	{
		state->pid_client_sent = 1;
		state->counter = 0;
		kill(state->pid_server, signal_mapper(bit));
		return ;
	}
	++(state->counter);
	kill(state->pid_server, signal_mapper(bit));
}

void	send_pid(t_state *state)
{
	while (!(state->pid_client_sent))
	{
		send_pid_signal(state);
		usleep(1000);
	}
}
