/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 09:06:20 by mbiagi            #+#    #+#             */
/*   Updated: 2024/12/02 16:10:33 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "libft.h"

static int	ft_strlcp(char *dest, const char *src, size_t size)
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
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (j);
}

static int	ft_setfor(const char *str, const char *set)
{
	int	i;
	int	j;
	int	nset;
	int	nset_temp;

	i = -1;
	nset = 0;
	while (str[++i])
	{
		j = 0;
		while (set[j])
		{
			nset_temp = 0;
			if (str[i] == set[j])
			{
				nset_temp = 1;
				nset++;
				break ;
			}
			j++;
		}
		if (nset_temp == 0)
			return (nset);
	}
	return (nset);
}

static int	ft_setback(const char *str, const char *set, const int str_len)
{
	int	i;
	int	j;
	int	nset;
	int	nset_temp;

	i = str_len;
	nset = 0;
	while (--i >= 0)
	{
		j = 0;
		while (set[j])
		{
			nset_temp = 0;
			if (str[i] == set[j])
			{
				nset_temp = 1;
				nset++;
				break ;
			}
			j++;
		}
		if (nset_temp == 0)
			return (nset);
	}
	return (nset);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		str_len;
	int		nsetfor;
	int		nsetback;
	char	*trimmed_str;

	str_len = 0;
	while (s1[str_len])
		str_len++;
	nsetfor = ft_setfor(s1, set);
	if (nsetfor == str_len)
		return (ft_strdup("\0"));
	nsetback = ft_setback(s1, set, str_len);
	trimmed_str = malloc(sizeof(char) *(str_len - nsetfor - nsetback + 1));
	if (trimmed_str == NULL)
		return (NULL);
	ft_strlcp(trimmed_str, (s1 + nsetfor), \
	(str_len - (nsetfor + nsetback) + 1));
	return (trimmed_str);
}
/* 
int	main(void)
{
	// char	*c;
	// char	*t;

	// c = " lorem ipsum dolor sit amet",
	// t = ft_strtrim(c, "l ");
	printf("%s", ft_strtrim("   xxx   xxx", " x"));
	//free(t);
	return (0);
} */