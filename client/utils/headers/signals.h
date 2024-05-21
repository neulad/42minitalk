/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukireyeu < ukireyeu@student.42warsaw.pl    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 22:40:36 by ukireyeu          #+#    #+#             */
/*   Updated: 2024/05/03 18:58:07 by ukireyeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <signal.h>
#include "../../client.h"

int		init_handler(int sig, void (*handler)(int signum), int sig_mask);
void	init_state(t_state *empty_state, char *body, pid_t pid);
