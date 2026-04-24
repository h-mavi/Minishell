/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:22:50 by mbiagi            #+#    #+#             */
/*   Updated: 2024/12/02 15:01:33 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stddef.h>
#include <bsd/string.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	x;
	size_t	y;
	size_t	lit_len;

	x = 0;
	y = 0;
	lit_len = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (little[lit_len])
		lit_len++;
	while ((x < len) && (big[x]))
	{
		while ((big[x + y] == little[y]) && (little[y]))
			y++;
		if ((little[y] == '\0') && (x + y <= len))
			return ((char *)&big[x]);
		y = 0;
		x++;
	}
	return (NULL);
}
/* 
int	main(void)
{
	// char	*s1;
	// char	*s2;

	// s1 = "";
	// s2 = "";
	printf("%s", ft_strnstr("", "", -1));
	return (0);
} */