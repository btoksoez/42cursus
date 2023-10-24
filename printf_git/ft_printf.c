/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:56:46 by btoksoez          #+#    #+#             */
/*   Updated: 2023/10/24 14:32:44 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(const char *format, va_list args)
{
	void	*temp;

	if (*(format + 1) == 's')
	{
		temp = va_arg(args, char *);
		if (!temp)
			temp = "(null)";
		ft_putstr_fd((char *)temp, 1);
		return(ft_strlen(temp));
	}
	if (*(format + 1) == 'c')
		ft_putchar_fd(va_arg(args, int), 1);
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
	return (1);
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
int main(void)
{
	int n = 3;
	int *p = &n;
	int count = printf("abcPrintf: %c ", 95);
	int count2 = ft_printf("Ft_printf: %c ", 95);
	// int count = printf("abcPrintf: %s %s\n", "", "");
	// int count2 = ft_printf("Ft_printf: %s %s\n", "", "");
	printf("Count printf: %d\n", count);
	printf("Count ft_printf: %d\n", count2);
}
