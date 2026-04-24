/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:02:16 by mbiagi            #+#    #+#             */
/*   Updated: 2025/04/01 11:25:53 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static void	ft_freestr(char **str, int j)
{
	while (j >= 0)
	{
		free(str[j]);
		j--;
	}
}

static char	**ft_alloc(const char *s, char c, char **split_s, int nc)
{
	int	x;
	int	i;
	int	j;

	x = 0;
	i = 0;
	j = 0;
	while (s[i] && j <= nc)
	{
		if (s[i] != c)
			x++;
		if ((s[i] == c || s[i + 1] == '\0') && x > 0)
		{
			split_s[j] = malloc(sizeof(char) * (x + 1));
			if (!split_s[j])
			{
				ft_freestr(split_s, j - 1);
				return (NULL);
			}
			j++;
			x = 0;
		}
		i++;
	}
	return (split_s);
}

static char	**ft_splitcpy(char **split_s, const char *s, char c, int nc)
{
	int	x;
	int	i;
	int	j;

	x = 0;
	i = 0;
	j = 0;
	while (s[i] && j <= nc)
	{
		if (s[i] != c)
			split_s[j][x++] = s[i];
		if ((s[i + 1] == c || s[i + 1] == '\0') && x > 0)
		{
			split_s[j][x] = '\0';
			j++;
			x = 0;
		}
		i++;
	}
	return (split_s);
}

char	**ft_split(char const *s, char c)
{
	char	**split_s;
	int		nc;
	int		i;

	nc = 0;
	i = -1;
	while (s[++i])
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			nc++;
	split_s = (char **)malloc(sizeof(char *) * (nc + 1));
	if (!split_s)
		return (NULL);
	if (!ft_alloc(s, c, split_s, nc))
		return (NULL);
	split_s = ft_splitcpy(split_s, s, c, nc);
	split_s[nc] = NULL;
	return (split_s);
}
/* 
int	main(void)
{
	char	c[40] = "";
	char	**split_c;
	int i = 0;

	split_c = ft_split(c, ',');
	while (split_c[i])
	{
		printf("%s\n", split_c[i]);
		free(split_c[i]);
		i++;
	}
	free(split_c);
	return (0);
} */