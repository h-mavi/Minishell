/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 08:14:44 by mbiagi            #+#    #+#             */
/*   Updated: 2025/02/18 09:41:34 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

static int	ft_strlen(const char *c)
{
	int	x;

	x = 0;
	while (c[x] != 0)
		x++;
	return (x);
}

static int	ft_strtcpy(const char *s, char *cpy, int j)
{
	int	i;

	i = 0;
	while (s[i])
	{
		cpy[j] = s[i];
		i++;
		j++;
	}
	return (j);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	i = ft_strlen(s1);
	i = i + (ft_strlen(s2));
	j = 0;
	str = (char *) malloc(i + 1);
	if (str == NULL)
		return (NULL);
	j = ft_strtcpy(s1, str, j);
	j = ft_strtcpy(s2, str, j);
	str[i] = '\0';
	return (str);
}
/* 
int	main(void)
{
	char	*s1;
	char	*s2;
	char	*s3;

	s1 = "il programma";
	s2 = " funziona";
	s3 = ft_strjoin(s1, s2);
	printf("%s", s3);
	free(s3);
	return (0);
} */