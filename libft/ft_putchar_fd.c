/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:51:54 by mbiagi            #+#    #+#             */
/*   Updated: 2024/11/25 15:59:38 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
/* 
int	main(void)
{
	int	fd;

	fd = open("file.txt", O_WRONLY);
	ft_putchar_fd('c', fd);
	close(fd);
	return (0);
} */