/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   private_ftprintf.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axlleres <axlleres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 20:22:44 by axlleres          #+#    #+#             */
/*   Updated: 2024/11/14 20:26:00 by axlleres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRIVATE_FTPRINTF_H
# define PRIVATE_FTPRINTF_H

#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>

int ft_pr_putstr(char *s);
int ft_pr_putc(char c);
int ft_pr_put_x(unsigned int n, int up);
int ft_pr_putptr(uintptr_t n);
int ft_pr_putnbr(int n);
int ft_pr_put_u(unsigned int n);

#endif