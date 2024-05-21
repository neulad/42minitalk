/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukireyeu < ukireyeu@student.42warsaw.pl    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 22:44:42 by ukireyeu          #+#    #+#             */
/*   Updated: 2024/05/04 20:52:28 by ukireyeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../client.h"
#include "../../utils/headers/strings.h"
#include <signal.h>
#include <unistd.h>

void	init_state(t_state *empty_state, char *body, pid_t pid_server)
{
	empty_state->counter = 0;
	empty_state->pid_client = getpid();
	empty_state->pid_client_sent = 0;
	empty_state->pid_server = pid_server;
	empty_state->alpha_counter = 0;
	empty_state->n_symbols_sent = 0;
	empty_state->n_symbols = ft_strlen(body);
	empty_state->body = body;
}

int	init_handler(int sig, void (*handler)(int signum), int sig_mask)
{
	struct sigaction	sa;

	sa.sa_handler = handler;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, sig_mask);
	sa.sa_flags = 0;
	return (sigaction(sig, &sa, NULL));
}
