/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:56:46 by btoksoez          #+#    #+#             */
/*   Updated: 2023/10/21 18:10:28 by btoksoez         ###   ########.fr       */
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
// int main(void)
// {
// 	int n = 3;
// 	int *p = &n;
// 	int count = printf("%p\n",p);
// 	int count2 = ft_printf("%p\n", p);
// 	printf("%d\n", count);
// 	printf("%d", count2);
// }
