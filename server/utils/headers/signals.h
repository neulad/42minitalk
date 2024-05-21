/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukireyeu < ukireyeu@student.42warsaw.pl    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 21:03:27 by ukireyeu          #+#    #+#             */
/*   Updated: 2024/05/03 17:51:26 by ukireyeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <signal.h>
#include <stddef.h>
#include "../../server.h"

void	init_state(t_state *empty_state);
int		init_handler(int sig, void (*handler)(int signum), int sig_mask);
