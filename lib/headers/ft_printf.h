/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukireyeu < ukireyeu@student.42warsaw.pl    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 14:43:47 by ukireyeu          #+#    #+#             */
/*   Updated: 2024/03/31 15:34:39 by ukireyeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *fmt, ...);
int	ft_print_flag(char const *fmt, va_list args);
int	ft_printc(va_list args);
int	ft_prints(va_list args);
int	ft_printp(va_list args);
int	ft_printd(va_list args);
int	ft_printu(va_list args);
int	ft_print_upper_x(va_list args);
int	ft_print_x(va_list args);
int	ft_print_percent(void);

#endif
