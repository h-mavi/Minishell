/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:55:46 by mbiagi            #+#    #+#             */
/*   Updated: 2024/12/17 09:41:31 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	sub_len;

	sub_len = 0;
	while (s[sub_len])
		sub_len++;
	if (!s)
		return (NULL);
	if (start >= sub_len)
		return (NULL);
	if (len > sub_len - start)
		len = sub_len - start;
	sub = malloc(sizeof(char) * len + 1);
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, &s[start], len + 1);
	return (sub);
}
/* 
int	main(void)
{
	//char	*str;
	char	*sub_str;

	//str = "hola";
	sub_str = ft_substr("hola", 0, 4);
	printf("%s", sub_str);
	free(sub_str);
	return (0);
} */