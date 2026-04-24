/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_rm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 12:51:08 by mfanelli          #+#    #+#             */
/*   Updated: 2025/05/15 15:59:15 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

/* Funzione che filtra la stringa per vedere se ci sono spazi extra tra le
redir e i loro limiter. */
char	*rm_spaces(char *s)
{
	int	i;
	int	x;

	i = -1;
	while (s[++i])
	{
		if (find_char(s, i) > 3 && s[i + 1] == ' ' && werami(s, i, 0, 0) == -1)
		{
			x = 1;
			while (s[i + x] == ' ')
				x++;
			if (find_char(s, (i + x)) != 0 || s[i + x] == '\0')
				return (error_exit(NULL, i - 2, \
				"Syntax Error, unexpected token\n", s));
			s = rewrite(s, i, x - 1);
		}
		if (find_char(s, i) > 3 && s[i + 1] == '\0' && \
		i > 0 && ((find_char(s, i - 1) == 0) || (find_char(s, i - 1) > 3)))
			return (error_exit(NULL, i - 2, \
			"Syntax Error, unexpected token\n", s));
	}
	return (s);
}

static int	rm_app_count(char *s, int i)
{
	int	len;

	len = 0;
	while (s[++i])
	{
		if (s[i] == 6)
			while (s[++i] != 6)
				len++;
		if ((werami(s, i, 0, 0) != 0 && s[i] != 92 && s[i] != 6) || \
		(((werami(s, i, 0, 0) == 0) || (s[i] == 92)) && i != 0 && \
		werami(s, i - 1, 0, 0) == 1 && werami(s, i + 1, 0, 0) == 1))
			len++;
	}
	return (len);
}

/* Serve a togliere gli apici, le virgolette e i back-slash inutili */
char	*rm_app(char *s)
{
	int		i;
	int		x;
	int		len;
	char	*new;

	i = -1;
	x = 0;
	len = rm_app_count(s, i);
	new = (char *)ft_calloc(sizeof(char), len + 1);
	while (s[++i])
	{
		if (s[i] == 6)
			while (s[++i] != 6)
				new[x++] = s[i];
		if ((werami(s, i, 0, 0) != 0 && s[i] != 92 && s[i] != 6) || \
		(((werami(s, i, 0, 0) == 0) || (s[i] == 92)) && i != 0 && \
		werami(s, i - 1, 0, 0) == 1 && werami(s, i + 1, 0, 0) == 1))
			new[x++] = s[i];
	}
	new[x] = '\0';
	return (free(s), new);
}

/* Serve a togliere i $ nel caso i cui non vadano stampati, es. $"USER" */
char	*rm_dollar(char *s)
{
	int		i;
	int		x;
	char	*tmp;

	i = -1;
	x = 0;
	while (s[++i])
	{
		x++;
		if (rm_dollar_if(s, i) != 0)
			x--;
	}
	tmp = (char *)ft_calloc(x + 1, sizeof(char));
	if (!tmp)
		return (NULL);
	i = -1;
	x = 0;
	while (s[++i])
	{
		if (rm_dollar_if(s, i) != 0)
			i++;
		tmp[x++] = s[i];
	}
	tmp[x] = '\0';
	return (free(s), tmp);
}

char	*rm_square(char *str)
{
	char	*end;
	int		i;
	int		x;

	i = -1;
	x = 0;
	while (str[++i])
		if (str[i] == 6)
			x++;
	end = (char *)ft_calloc(ft_strlen(str) - x + 1, sizeof(char));
	i = -1;
	x = 0;
	while (str[++i] != '\0')
	{
		if (str[i] == 6)
			i++;
		if (str[i] == 6)
			break ;
		end[x] = str[i];
		x++;
	}
	return (free(str), end);
}
