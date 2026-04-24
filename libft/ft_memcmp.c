/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:09:01 by mbiagi            #+#    #+#             */
/*   Updated: 2024/11/30 10:36:44 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*str1;
	char	*str2;
	size_t	x;

	x = 0;
	str1 = (char *)s1;
	str2 = (char *)s2;
	if (n == 0)
		return (0);
	while ((str1[x] == str2[x]) && (x != n - 1))
		x++;
	return ((unsigned char)str1[x] - (unsigned char)str2[x]);
}
/* 
int	main(void)
{
	char	s1[] = {0, 0, 42, 0, 0, 0, 0, 0, 0};
	char	s2[] = {0, 0, 42, 0};

	printf("%d", ft_memcmp(s1, s2, 7800));
	return (0);
} */