/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:52:49 by mbiagi            #+#    #+#             */
/*   Updated: 2025/01/13 14:12:01 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
// # include "libft/libft.h"

# include <stdio.h>
# include <unistd.h>
# include <ctype.h>
# include <stdlib.h>
# include <strings.h>
# include <string.h>
# include <bsd/string.h>
# include <fcntl.h>
# include <unistd.h>
# include <linux/stat.h>
# include <sys/stat.h>
# include <stddef.h>
# include <stdarg.h>

int	ft_putnbr_un(unsigned int n);
int	ft_putnbr_hex(unsigned int n, char *c);
int	ft_putnbr_long(unsigned long long n, char *c);
int	ft_putchar(char c, int fd);
int	ft_putstr(char *s, int fd);
int	ft_putnbr(int n, int fd);
int	ft_printf(const char *input, ...);

#endif