/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:14:58 by mbiagi            #+#    #+#             */
/*   Updated: 2024/12/12 11:13:43 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stddef.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	j = 0;
	while (src[j])
		j++;
	i = 0;
	if (size < 1)
		return (j);
	while (src[i] != '\0' && i < size -1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (j);
}

/* int main(void)
{
	char	dest[10] = "";
	char	*src;
	int 	x;

	src = "niente";
	x = ft_strlcpy( dest, src, 4);
	printf("%d, %s", x, dest);
	return (0);
} */