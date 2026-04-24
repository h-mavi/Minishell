/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 09:12:03 by mbiagi            #+#    #+#             */
/*   Updated: 2024/11/30 15:56:32 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strrchr(const char *s, int c)
{
	int				x;
	int				y;
	unsigned char	a;

	x = 0;
	y = 0;
	a = (unsigned char) c;
	while ((s[x] != '\0'))
	{
		if (s[x] == a)
			y = x;
		x++;
	}
	if ((s[x] == '\0') && (a == '\0'))
		return ((char *)&s[x]);
	if ((y == 0) && (s[0] != a))
		return (NULL);
	return ((char *)&s[y]);
}
/* 
int main(void)
{
	char	*s;

	s = "teste";
	printf("%s", ft_strrchr(s, 1125));
	return (0);
} */