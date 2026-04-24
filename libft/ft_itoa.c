/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 13:09:25 by mbiagi            #+#    #+#             */
/*   Updated: 2024/12/02 15:14:08 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

static char	*ft_numchar(long n, char *c, int i)
{
	if (n == 0)
	{
		c[0] = '0';
		c[1] = '\0';
		return (c);
	}
	if (n < 0)
	{
		c[0] = '-';
		n = -n;
		i++;
	}
	c[i] = '\0';
	while (n > 0)
	{
		c[i - 1] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
	return (c);
}

char	*ft_itoa(int n)
{
	long	x;
	int		i;
	char	*c;

	x = (long)n;
	i = 0;
	if (n == 0)
		c = malloc(sizeof(char) * 2);
	if (x < 0)
		x = -x;
	while (x > 0)
	{
		if ((x % 10) >= 0)
			i++;
		x = x / 10;
	}
	if (n < 0)
		c = malloc(sizeof(char) * i + 2);
	if (n > 0)
		c = malloc(sizeof(char) * i + 1);
	if (c == NULL)
		return (NULL);
	c = ft_numchar(n, c, i);
	return (c);
}

/* int	main(void)
{
	//int		n;
	char	*s;

	//n = 0;
	s = ft_itoa(-2147483648);
	printf("%s", s);
	free(s);
	return (0);
} */