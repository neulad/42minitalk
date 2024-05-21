/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukireyeu < ukireyeu@student.42warsaw.pl    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 22:26:46 by ukireyeu          #+#    #+#             */
/*   Updated: 2024/05/04 16:38:41 by ukireyeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <signal.h>

typedef struct s_state
{
	int			counter;
	pid_t		pid_server;
	int			pid_client_sent;
	pid_t		pid_client;
	int			alpha_counter;
	int			n_symbols_sent;
	int			n_symbols;
	char		*body;
}	t_state;
