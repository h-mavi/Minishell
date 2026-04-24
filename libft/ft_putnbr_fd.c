/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:16:55 by mbiagi            #+#    #+#             */
/*   Updated: 2024/11/25 16:25:23 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	ft_putnbr_fd(int n, int fd)
{
	char	prin;

	if (n >= 10 || n <= -10)
		ft_putnbr_fd(n / 10, fd);
	else
		if (n < 0)
			write(fd, "-", 1);
	if (n < 0)
		prin = ((n % 10) * -1) + '0';
	else
		prin = (n % 10) + '0';
	write(fd, &prin, 1);
}
/* 
int	main(void)
{
	int	fd;

	fd = open("file.txt", O_WRONLY);
	ft_putnbr_fd(-153, fd);
	close(fd);
	return (0);
} */