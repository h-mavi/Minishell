/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:53:51 by mbiagi            #+#    #+#             */
/*   Updated: 2024/12/02 10:43:46 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

static int	ft_number(const char *c, int x, int sign)
{
	int	num;

	num = 0;
	while ((c[x] >= 48) && (c[x] <= 57))
	{
		num = num * 10 + (c[x] - '0');
		x++;
	}
	if (sign == 1)
		return (num * -1);
	return (num);
}

int	ft_atoi(const char *nptr)
{
	int	x;
	int	sign;

	x = 0;
	sign = 0;
	while ((nptr[x] == 32) || ((nptr[x] >= 9) && (nptr[x] <= 13)))
		x++;
	if (nptr[x] == 43)
		x++;
	else if (nptr[x] == 45)
	{
		sign = 1;
		x++;
	}
	else if ((nptr[x] < 48) || (nptr[x] > 57))
		return (0);
	return (ft_number(nptr, x, sign));
}
/* 
int	main(void)
{
	char	*c;

	c = " \n     +2147483647   ";
	printf("%d\n", ft_atoi(c));
	printf("%d\n", atoi(c));
	return (0);
} */