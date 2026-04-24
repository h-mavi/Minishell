/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 09:07:07 by mbiagi            #+#    #+#             */
/*   Updated: 2024/12/03 10:07:53 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

static void	ft_bzero(void *c, size_t num)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)c;
	while (i < num)
	{
		str[i] = 0;
		i++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	max;
	void	*ptr;

	max = nmemb * size;
	if ((nmemb == 0) || (size == 0) || (max / nmemb != size))
		return (malloc(0));
	ptr = malloc(max);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, max);
	return (ptr);
}
/* 
int	main(void)
{
	char	*prova;

	prova = (char *) ft_calloc(153, sizeof(char));  
	if (prova == NULL)
		printf("FAIL\n");
	else
	{
		printf("OK\n");
		printf("%s", prova);
	}
	free(prova);
	return (0);
} */