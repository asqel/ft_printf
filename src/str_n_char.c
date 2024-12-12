/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_n_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axlleres <axlleres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 20:20:47 by axlleres          #+#    #+#             */
/*   Updated: 2024/12/12 17:16:31 by axlleres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private_ftprintf.h"

int	ft_pr_putstr(char *s)
{
	int	len;

	if (s == NULL)
		return (ft_pr_putstr("(null)"));
	len = 0;
	while (s[len] != '\0')
		len++;
	write(1, s, len);
	return (len);
}

int	ft_pr_putc(char c)
{
	write(1, &c, 1);
	return (1);
}
