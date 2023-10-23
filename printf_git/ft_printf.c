/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:56:46 by btoksoez          #+#    #+#             */
/*   Updated: 2023/10/23 18:17:08 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(const char *format, va_list args)
{
	int	count;

	count = 0;
	if (*(format + 1) == 's')
		count += ft_print_s(format, args);
	if (*(format + 1) == 'c')
		count += ft_print_c(format, args);
	if (*(format + 1) == 'p')
		count += ft_print_p(format, args);
	if (*(format + 1) == 'd')
		count += ft_print_d(format, args);
	if (*(format + 1) == 'i')
		count += ft_print_d(format, args);
	if (*(format + 1) == 'u')
		count += ft_print_d(format, args);
	if (*(format + 1) == 'x')
		count += ft_print_x(format, args);
	if (*(format + 1) == 'X')
		count += ft_print_x_upper(format, args);
	if (*(format + 1) == '%')
		count += ft_putchar_fd('%', 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	if (!format || *format == 0)
		return (0);
	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			if (va_arg(args, void *) == NULL)
				return (0);
			count += ft_format(format, args);
			format += 2;
		}
		else
		{
			count += ft_putchar_fd(*format, 1);
			format++;
		}
	}
	va_end(args);
	return (count);
}
int main(void)
{
	int n = 3;
	int *p = &n;
	int count = printf("abcPrintf: %p ", -1);
	int count2 = ft_printf("Ft_printf: %p ", -1);
	// int count = printf("abcPrintf: %s %s\n", "", "");
	// int count2 = ft_printf("Ft_printf: %s %s\n", "", "");
	printf("Count printf: %d\n", count);
	printf("Count ft_printf: %d\n", count2);
}
