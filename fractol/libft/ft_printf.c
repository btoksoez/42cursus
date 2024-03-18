/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:56:46 by btoksoez          #+#    #+#             */
/*   Updated: 2024/03/18 11:56:21 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_in(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (1);
		s++;
	}
	return (0);
}

int	ft_format(const char *format, va_list args)
{
	void	*temp;

	if (*(format + 1) == 's')
	{
		temp = va_arg(args, char *);
		if (!temp)
			temp = "(null)";
		ft_putstr_fd((char *)temp, 1);
		return (ft_strlen(temp));
	}
	if (*(format + 1) == 'c')
		ft_putchar_fd(va_arg(args, int), 1);
	if (*(format + 1) == 'p')
		return (ft_print_hex(va_arg(args, void *)));
	if (*(format + 1) == 'd' || *(format + 1) == 'i')
		return (ft_putnbr_base(va_arg(args, int), "0123456789"));
	if (*(format + 1) == 'u')
		return (ft_putnbr_base(va_arg(args, unsigned int), "0123456789"));
	if (*(format + 1) == 'x')
		return (ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef"));
	if (*(format + 1) == 'X')
		return (ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF"));
	if (*(format + 1) == '%')
		ft_putchar_fd('%', 1);
	return (1);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	char	*options;

	if (!format)
		return (-1);
	count = 0;
	options = "csxXdipu%";
	va_start(args, format);
	while (*format)
	{
		if (*format == '%' && ft_is_in(options, (*(format + 1))))
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
// 	int n = 0;
// 	int count = ft_printf('0');
// 	int count2 = ft_printf('0');
// 	// int count = ft_printf("abcft_printf: %s %s\n", "", "");
// 	// int count2 = ft_printf("ft_printf: %s %s\n", "", "");
// 	ft_printf("Count ft_printf: %d\n", count);
// 	ft_printf("Count ft_printf: %d\n", count2);
// }
