/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukireyeu < ukireyeu@student.42warsaw.pl    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 22:26:40 by ukireyeu          #+#    #+#             */
/*   Updated: 2024/05/04 19:25:52 by ukireyeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/headers/ft_printf.h"
#include "./utils/headers/signals.h"
#include "./utils/headers/send_pid.h"
#include "./utils/headers/send_n_symbols.h"
#include "./utils/headers/send_body.h"
#include "client.h"
#include <signal.h>
#include <stdlib.h>

t_state	g_state;

void	sig_handler(int signum)
{
	pid_t	bit;

	if (!g_state.pid_client_sent)
		return ;
	if (!g_state.n_symbols_sent)
	{
		send_n_symbols_signal(&g_state);
		return ;
	}
	send_body(&g_state);
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_printf("error: arguments don't equal 3");
		return (1);
	}
	init_state(&g_state, argv[2], atoi(argv[1]));
	init_handler(SIGUSR1, &sig_handler, SIGUSR2);
	send_pid(&g_state);
	while (1)
		pause();
	return (0);
}
