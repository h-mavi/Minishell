/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 11:48:36 by mfanelli          #+#    #+#             */
/*   Updated: 2025/05/05 14:09:44 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_copy(char *bois)
{
	char	*str;
	int		y;
	int		x;

	y = -1;
	x = ft_strlen_gnl(bois) + 1;
	str = ft_calloc_gnl((x), sizeof(char));
	if (str == NULL)
		return (NULL);
	while (bois[++y] != '\0')
		str[y] = bois[y];
	str[y] = '\0';
	return (str);
}

char	*ft_backup(char *next, char *buff)
{
	char	*str;
	int		x;
	int		y;

	if (next == NULL)
		return (ft_copy(buff));
	str = ft_calloc_gnl((ft_strlen_gnl(next) + ft_strlen_gnl(buff) + 1), \
	sizeof(char));
	if (str == NULL)
		return (NULL);
	x = -1;
	y = 0;
	while (next[++x] != '\0')
		str[x] = next[x];
	while (buff[y] != '\0')
		str[x++] = buff[y++];
	str[x] = '\0';
	free (next);
	return (str);
}

char	*ft_prep(char *next)
{
	char	*str;
	int		x;
	int		y;

	if (next == NULL)
		return (NULL);
	x = 0;
	y = ft_strlen_gnl(next);
	while (next[x] != '\n' && (next[x]))
		x++;
	if (next[x] == '\0')
	{
		free (next);
		return (NULL);
	}
	str = ft_calloc_gnl((y - x + 2), sizeof(char));
	if (!str)
		return (NULL);
	y = 0;
	while (next[x + 1] != '\0')
		str[y++] = next[(x++) + 1];
	str[y + 1] = '\0';
	free (next);
	return (str);
}

char	*ft_read(char *next, char *buff, int fd)
{
	int	check;

	check = 1;
	while (check > 0)
	{
		check = read(fd, buff, BUFFER_SIZE);
		if (check == -1)
		{
			if (next != NULL)
				free (next);
			return (NULL);
		}
		if (check == 0)
			break ;
		buff[check] = '\0';
		next = ft_backup(next, buff);
		if (ft_strchr_gnl(buff, '\n'))
			break ;
	}
	return (next);
}

char	*get_next_line(int fd)
{
	char		*buff;
	char		*end;
	static char	*next = NULL;

	buff = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		if (next != NULL)
			free (next);
		return (NULL);
	}
	end = NULL;
	buff = ft_calloc_gnl((BUFFER_SIZE + 1), sizeof(char));
	next = ft_read(next, buff, fd);
	free (buff);
	buff = NULL;
	end = ft_substr_gnl(next, 0, '\n');
	next = ft_prep(next);
	return (end);
}

/* int main(void)
{
	int fd;
	int i;

	i = 0;
	fd = open("never_gona_give_u_up", O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		return (0);
	}
		char *s = get_next_line(fd);
	while (s != NULL)
	{
		printf("%s", s);
		i++;
		free(s);
		s = get_next_line(fd);
	}
	close(fd);
	return 0;
} */
