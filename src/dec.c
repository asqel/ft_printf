/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dec.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axlleres <axlleres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 20:21:19 by axlleres          #+#    #+#             */
/*   Updated: 2024/11/14 20:25:24 by axlleres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private_ftprintf.h"

int ft_pr_putnbr(int n)
{
	if (n == (int)0x80000000)
		return (ft_pr_putstr("-2147483648"));
	if (n < 0)
		return (ft_pr_putc('-') + ft_pr_putnbr(-n));
	if (n < 10)
		return (ft_pr_putc('0' + n));
	return (ft_pr_putnbr(n / 10) + ft_pr_putnbr(n % 10));
}

int ft_pr_put_u(unsigned int n)
{
	if (n < 10)
		return (ft_pr_putc('0' + n));
	return (ft_pr_put_u(n / 10) + ft_pr_put_u(n % 10));
}
