/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:51:54 by mbiagi            #+#    #+#             */
/*   Updated: 2024/12/07 10:38:32 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

int	ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}
/* 
int	main(void)
{
	int	fd;

	fd = open("file.txt", O_WRONLY);
	ft_putchar('c', fd);
	close(fd);
	return (0);
} */