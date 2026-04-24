/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 09:27:52 by mbiagi            #+#    #+#             */
/*   Updated: 2024/11/29 10:17:56 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stddef.h>
#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	x;

	x = 0;
	if (n == 0)
		return (0);
	while ((s1[x] == s2[x]) && (x != n - 1) && s1[x] && s2[x])
		x++;
	return ((unsigned char)s1[x] - (unsigned char)s2[x]);
}

/*
int main(void)
{
	char	*s1;
	char	*s2;

	s1 = "aesta";
	s2 = "gyfgyu";
	printf("%d", ft_strncmp(s1, s2, 6));
	return (0);
} */