/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:43:06 by mbiagi            #+#    #+#             */
/*   Updated: 2024/12/02 15:54:32 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*sor;
	char	*dst;
	size_t	x;

	sor = (char *)src;
	dst = (char *)dest;
	x = 0;
	if (!dest && !src)
		return (NULL);
	while (x < n)
	{
		dst[x] = sor[x];
		x++;
	}
	return ((void *)dst);
}
/* 
int main(void)
{
	char	dest[22];
	char	src[22] = "zy\0xw\0vu\0\0tsr";
	
	ft_memcpy(dest, src, 11);
	printf("%s", dest);
	return (0);
} */