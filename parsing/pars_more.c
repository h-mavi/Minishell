/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_more.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 12:21:35 by mfanelli          #+#    #+#             */
/*   Updated: 2025/05/15 09:48:15 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	check_append(char *s, int i, char thing)
{
	int	x;
	int	f;

	x = i - 1;
	if (thing == 'a')
		f = '\'';
	else if (thing == 'v')
		f = '"';
	while (s[++x])
		if (s[x] == f)
			return (1);
	return (0);
}

/* Indica se il carattere nella posizione 'index' nella stringa s e'
dentro o fuori gi apici/ virgolette. Se returna 0 s[index] e'
uguale ad un'apice/virgoletta, se returna 1 s[index] e'
negli apici, se returna -1 e' fuori.
Se 's' o 's[index]' sono uguali a NULL returnano -2.*/
int	werami(char *s, int i, int a, int v)
{
	int	x;

	x = -1;
	if (s == NULL || s[i] == '\0')
		return (-2);
	while (s[++x] != '\0')
	{
		if (s[x] == '"' && a == 0 && v == 0)
			v = 1;
		else if (s[x] == '"' && a == 0 && v == 1)
			v = 0;
		if (s[x] == '\'' && a == 0 && v == 0)
			a = 1;
		else if (s[x] == '\'' && a == 1 && v == 0)
			a = 0;
		if (((s[x] == '\'' && v == 0) || (s[x] == '"' && a == 0)) && x == i)
			return (0);
		if (x == i)
			break ;
	}
	if ((a == 1 && v == 0 && check_append(s, i, 'a') != 0) || \
		(v == 1 && a == 0 && check_append(s, i, 'v') != 0))
		return (1);
	return (-1);
}

/* Funzione creata per colpa di norminette, contiene un if di rm_dollar */
int	rm_dollar_if(char *s, int i)
{
	if (s[i] == '$' && werami(s, i + 1, 0, 0) == 0 && werami(s, i, 0, 0) == -1)
		return (1);
	return (0);
}

/* Funzione che serve per espandere l'exit status. */
char	*set_exit_status(char *s)
{
	int		i;
	int		x;
	int		y;
	char	*end;
	char	*status;

	i = -1;
	x = -1;
	y = 0;
	status = ft_itoa(exit_code(12345));
	end = (char *)ft_calloc(ft_strlen(s) - 1 + ft_strlen(status), sizeof(char));
	while (s[++i])
	{
		if (s[i] == '$' && s[i + 1] == '?')
		{
			i += 2;
			while (status[++x])
				end[y++] = status[x];
		}
		end[y++] = s[i];
		if (s[i] == '\0')
			break ;
	}
	return (free(s), free(status), end);
}

/* Funzione creata per colpa di norminette, chiamata da simple_refine e da
refine.*/
char	*espand_core(char *s, int *i, int which)
{
	*i = do_skip(s, *i);
	if (which == 1)
	{
		if (s[*i] == '$' && ft_isdigit(s[*i + 1]) != 0 && \
			werami(s, *i, 0, 0) == -1)
			s = ft_mycpy(s, *i);
		if (s[*i] == '$' && s[*i + 1] == '?' && werami(s, *i, 0, 0) == -1)
			s = set_exit_status(s);
		if (*i > 1 && s[*i] == '$' && s[*i - 1] == '<' && s[*i - 2] == '<' && \
			s[*i + 1] != '\0')
			*i += 1;
		*i = for_normi(s, *i, 2);
	}
	else if (which == 0)
	{
		if (s[*i] == '$' && s[*i + 1] == '?')
			s = set_exit_status(s);
		if (s[*i] == '$' && ft_isdigit(s[*i + 1]) != 0)
			s = ft_mycpy(s, *i);
	}
	return (s);
}
