/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axlleres <axlleres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 20:21:39 by axlleres          #+#    #+#             */
/*   Updated: 2024/12/12 17:15:37 by axlleres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private_ftprintf.h"

int	ft_pr_put_x(unsigned int n, int up)
{
	if (up)
	{
		if (n < 16)
			return (ft_pr_putc("0123456789ABCDEF"[n]));
		return (ft_pr_put_x(n / 16, up) + ft_pr_put_x(n % 16, up));
	}
	else
	{
		if (n < 16)
			return (ft_pr_putc("0123456789abcdef"[n]));
		return (ft_pr_put_x(n / 16, up) + ft_pr_put_x(n % 16, up));
	}
}

int	ft_pr_putptr(uintptr_t n)
{
	if (n < 16)
		return (ft_pr_putc("0123456789abcdef"[n]));
	return (ft_pr_putptr(n / 16) + ft_pr_putptr(n % 16));
}
