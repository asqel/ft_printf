/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axlleres <axlleres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:22:08 by axlleres          #+#    #+#             */
/*   Updated: 2024/11/14 20:24:08 by axlleres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdint.h>
#include "src/private_ftprintf.h"

int ft_do_format(char c, va_list args) {
	uintptr_t ptr;

	if (c ==  's')
		return (ft_pr_putstr(va_arg(args, char *)));
	else if (c == 'c')
		return (ft_pr_putc((char)va_arg(args, int)));
	else if (c == 'd' || c == 'i')
		return ft_pr_putnbr(va_arg(args, int));
	else if (c == 'u')
		return (ft_pr_put_u(va_arg(args, unsigned int)));
	else if (c == 'x')
		return (ft_pr_put_x(va_arg(args, unsigned int), 0));
	else if (c == 'X')
		return (ft_pr_put_x(va_arg(args, unsigned int), 1));
	else if (c == 'p') {
		ptr = (uintptr_t)va_arg(args, void *);
		if (ptr == 0)
			return (ft_pr_putstr("(nil)"));
		else
			return (ft_pr_putstr("0x") + ft_pr_putptr(ptr));
	}
	ft_pr_putc('%');
	ft_pr_putc(c);
	return (2);
}

int	ft_printf(const char *fmt, ...)
{
	va_list args;
	int	count;

	count = 0;
	va_start(args, fmt);
	while (*fmt != '\0')
	{
		if (*fmt == '%')
		{
			if (*(fmt + 1) == '%')
				count += ft_pr_putc('%');
			else
				count += ft_do_format(*(fmt + 1), args);
			fmt++;
			fmt++;
		}
		else {
			count++;
			write(1, fmt, 1);
			fmt++;
		}
	}
	va_end(args);
	return (count);
}
