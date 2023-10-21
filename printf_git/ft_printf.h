/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 11:14:39 by btoksoez          #+#    #+#             */
/*   Updated: 2023/10/21 18:00:32 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdint.h>
# include "libft/libft.h"

void	ft_print_hex(void *p);
int		ft_putnbr_hex(int n, int s);
int		ft_print_s(const char *format, va_list args);
int		ft_print_p(const char *format, va_list args);
int		ft_print_c(const char *format, va_list args);
int		ft_print_d(const char *format, va_list args);
int		ft_print_x_upper(const char *format, va_list args);
int		ft_print_x(const char *format, va_list args);
int		ft_printf(const char *format, ...);

#endif
