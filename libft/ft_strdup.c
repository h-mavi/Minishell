/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 10:42:27 by mbiagi            #+#    #+#             */
/*   Updated: 2024/11/29 10:37:10 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <bsd/string.h>
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char	*dup_str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i])
		i++;
	dup_str = malloc(sizeof(char) * (i + 1));
	if (dup_str == NULL)
		return (NULL);
	dup_str[i] = '\0';
	while (j < i)
	{
		dup_str[j] = s[j];
		j++;
	}
	return (dup_str);
}
/* 
int	main(void)
{
	char	real_str[] = "lorem ipsum dolor sit amet";
	char	*dup_str;

	dup_str = ft_strdup(real_str);
	printf("%s\n", dup_str);
	free(dup_str);
	return (0);
} */