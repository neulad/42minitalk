/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukireyeu < ukireyeu@student.42warsaw.pl    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 21:03:53 by ukireyeu          #+#    #+#             */
/*   Updated: 2024/05/04 19:06:33 by ukireyeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include "../lib/headers/ft_printf.h"
#include "./utils/headers/handle_metadata.h"
#include "./utils/headers/handle_body.h"
#include "./utils/headers/signals.h"

t_state	g_state;

void	sig_handler(int sig)
{
	if (!g_state.pid_done || !g_state.n_symbols_done)
	{
		fulfill_metadata(&g_state, sig);
		if (g_state.pid_done)
			kill(g_state.pid, SIGUSR1);
		return ;
	}
	handle_body(&g_state, sig);
}

int	main(void)
{
	init_state(&g_state);
	init_handler(SIGUSR1, &sig_handler, SIGUSR2);
	init_handler(SIGUSR2, &sig_handler, SIGUSR1);
	ft_printf("pid %d\n", getpid());
	while (1)
		pause();
	return (0);
}
