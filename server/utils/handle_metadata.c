/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_metadata.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukireyeu < ukireyeu@student.42warsaw.pl    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 21:50:57 by ukireyeu          #+#    #+#             */
/*   Updated: 2024/05/03 17:51:17 by ukireyeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/handle_metadata.h"
#include "./headers/signals.h"
#include <sys/types.h>

static void	fill_pid(t_state *state, int sig)
{
	if (!(state->pid_done) && sig == SIGUSR1)
		state->pid |= 1 << (state->sig_counter);
}

static void	fill_n_symbols(t_state *state, int sig)
{
	if (!(state->n_symbols_done) && (state->pid_done) && sig == SIGUSR1)
	{
		state->n_symbols |= 1 << (state->sig_counter);
	}
}

static int	check_metadata_done(t_state *state)
{
	if (!(state->pid_done) && state->sig_counter == sizeof(int) * 8 - 1)
	{
		state->pid_done = 1;
		state->sig_counter = 0;
		return (1);
	}
	if (!(state->n_symbols_done)
		&& (state->pid_done)
		&& state->sig_counter == sizeof(int) * 8 - 1)
	{
		state->n_symbols_done = 1;
		state->sig_counter = 0;
		return (1);
	}
	return (0);
}

void	fulfill_metadata(t_state *state, int sig)
{
	fill_pid(state, sig);
	fill_n_symbols(state, sig);
	if (!check_metadata_done(state))
		++(state->sig_counter);
}
