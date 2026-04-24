/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_long.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:55:31 by mbiagi            #+#    #+#             */
/*   Updated: 2024/12/17 10:29:09 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_long(unsigned long long n, char *c)
{
	int		i;
	char	string[20];
	int		x;

	i = 0;
	if (!n)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write (1, "0x", 2);
	while (n > 0)
	{
		string[i] = c[n % 16];
		n = n / 16;
		i++;
	}
	x = i - 1;
	while (x >= 0)
	{
		write (1, &string[x], 1);
		x--;
	}
	return (i + 2);
}
