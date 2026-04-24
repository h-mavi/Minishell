/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 08:39:00 by mbiagi            #+#    #+#             */
/*   Updated: 2024/11/30 10:31:37 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	int				x;
	unsigned char	a;

	x = 0;
	a = (unsigned char) c;
	while ((s[x] != '\0') && (s[x] != a))
		x++;
	if ((s[x] == '\0') && (a != '\0'))
		return (NULL);
	return ((char *)&s[x]);
}
/* 
int main(void)
{
	char	*c;

	c = "tripoulle";
	printf("%s", ft_strchr(c, 't' + 256));
	return (0);
} */