/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukireyeu < ukireyeu@student.42warsaw.pl    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 21:28:23 by ukireyeu          #+#    #+#             */
/*   Updated: 2024/05/04 20:53:57 by ukireyeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <unistd.h>
#include <sys/types.h>

typedef struct s_state
{
	int			sig_counter;
	int			pid_done;
	pid_t		pid;
	int			n_symbols_done;
	int			n_symbols;
	char		temp_alpha;
	int			alpha_counter;
	char		*body;
}	t_state;
