/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:16:55 by mbiagi            #+#    #+#             */
/*   Updated: 2024/12/07 10:38:28 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int	ft_putnbr(int n, int fd)
{
	char	prin;
	long	nret;
	int		i;

	nret = (long)n;
	i = 0;
	if (nret < 0)
		nret = -nret * 10;
	if (n >= 10 || n <= -10)
		ft_putnbr(n / 10, fd);
	else
		if (n < 0)
			write(fd, "-", 1);
	if (n < 0)
		prin = ((n % 10) * -1) + '0';
	else
		prin = (n % 10) + '0';
	write(fd, &prin, 1);
	while ((nret / 10) > 0)
	{
		i++;
		nret = nret / 10;
	}
	return (i + 1);
}
/* 
int	main(void)
{
	int	fd;

	fd = open("file.txt", O_WRONLY);
	printf("\n%d", ft_putnbr(-2147483648, fd));
	close(fd);
	return (0);
} */