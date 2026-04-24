/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:13:01 by mbiagi            #+#    #+#             */
/*   Updated: 2024/12/10 12:11:45 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hex(unsigned int n, char *c)
{
	int		i;
	char	string[20];
	int		x;

	i = 0;
	if (n == 0)
	{
		write(1, &c[0], 1);
		return (1);
	}
	while (n > 0)
	{
		string[i] = c[n % 16];
		n = n / 16;
		i++;
	}
	x = i - 1;
	while (x >= 0)
		write (1, &string[x--], 1);
	return (i);
}
/* 
int main (void)
{
	printf("\n%d", ft_putnbr_hex(10, "0123456789abcdef"));
	return (0);
} */