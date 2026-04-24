/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:46:35 by mbiagi            #+#    #+#             */
/*   Updated: 2024/11/25 15:13:36 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*dst;
	char	*sor;
	size_t	x;

	dst = (char *)dest;
	sor = (char *)src;
	if (dest < src)
	{
		x = 0;
		while (x < n)
		{
			dst[x] = sor[x];
			x++;
		}
	}
	else if (src < dest)
	{
		x = n;
		while (x > 0)
		{
			dst[x - 1] = sor[x - 1];
			x--;
		}
	}
	return (dest);
}
/* 
int	main(void)
{
	char	dest[10] = "fratto";
	char	src[6] = "fratto";
	
	ft_memmove(dest, src, 4);
	printf("%s", dest);
	return (0);
}  */