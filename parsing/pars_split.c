/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 16:53:52 by mfanelli          #+#    #+#             */
/*   Updated: 2025/04/29 12:25:41 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

/* Chiamata da fill nel custom_split, porta ad allinearsi con y.*/
static int	realigning_i(char *s, int i, int y)
{
	if (s[i] == 34 || s[i] == 39)
	{
		while (s[y] != '\0' && ((werami(s, i, 0, 0) != -1) || \
		(werami(s, i, 0, 0) == -1 && s[i] != ' ')))
			i++;
	}
	else
	{
		while (s[y] != '\0' && s[i++] != ' ')
			if (s[i] == 34 || s[i] == 39)
				while (werami(s, i, 0, 0) != -1 && werami(s, y, 0, 0) != -2)
					i++;
	}
	return (i);
}

/* returna il numero di elementi presenti nell'input */
static int	len_arr_split(char *arr)
{
	int	i;
	int	x;

	i = 0;
	x = -1;
	while (arr[++x] != '\0')
	{
		if (arr[x] == 34)
		{
			if (len_arr_utils(arr, &i, &x, 34) == -1)
				return (-1);
		}
		else if (arr[x] == 39)
		{
			if (len_arr_utils(arr, &i, &x, 39) == -1)
				return (-1);
		}
		if ((arr[x] == ' ' && arr[x + 1] != ' ' && arr[x + 1] != '\0') || \
		(x == 0 && arr[x] != ' '))
			i++;
	}
	return (i);
}

static void	frite(char *dest, int start, int len, char *s)
{
	int	i;

	i = 0;
	if (s[start + len - 1])
		len--;
	while (i + start < start + len)
	{
		dest[i] = s[start + i];
		i++;
	}
	dest[i] = '\0';
}

static char	**fill(char **dest, char *s, int len_arr, int i)
{
	int	x;
	int	y;
	int	conta;

	x = 0;
	y = 0;
	while (x < len_arr)
	{
		conta = 1;
		while (s[i] == 32)
			i++;
		y = i;
		conta = count_len_wrd(s, &y, conta);
		dest[x] = (char *) malloc(sizeof(char) * (conta + 1));
		if (dest[x] == NULL)
			return (NULL);
		frite(dest[x++], i, conta, s);
		i = realigning_i(s, i, y);
	}
	dest[x] = NULL;
	return (dest);
}

/* Split customizzato per addattarsi alle esigenze di minishell.
Chiama le funzioni rm_spaces e here_glued. */
char	**custom_split(char *s)
{
	int		len_arr;
	char	**dest;

	s = rm_spaces(s);
	if (!s)
		return (NULL);
	s = here_glued(s);
	if (!s || check_error(s) == 0)
		return (NULL);
	len_arr = len_arr_split(s);
	if (len_arr == -1)
		return (exit_code(2), error_exit(NULL, -1, \
		"Syntax Error, odd number of ' or \"\n", NULL), NULL);
	dest = (char **) malloc(sizeof(char *) * (len_arr + 1));
	if (!dest)
		return (error_exit(NULL, -1, "Failed Allocation\n", NULL), NULL);
	if (!fill(dest, s, len_arr, 0))
		return (free(s), free_arr(dest), error_exit(NULL, -1, \
		"Failed Allocation\n", NULL), NULL);
	return (free(s), dest);
}
