/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukireyeu < ukireyeu@student.42warsaw.pl    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 21:03:25 by ukireyeu          #+#    #+#             */
/*   Updated: 2024/05/03 17:51:13 by ukireyeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/signals.h"
#include "../server.h"

void	init_state(t_state *empty_state)
{
	empty_state->pid_done = 0;
	empty_state->pid = 0;
	empty_state->n_symbols_done = 0;
	empty_state->n_symbols = 0;
	empty_state->alpha_counter = 0;
	empty_state->temp_alpha = 0;
	empty_state->body = NULL;
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
