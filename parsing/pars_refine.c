/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_refine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 09:02:23 by mfanelli          #+#    #+#             */
/*   Updated: 2025/05/13 15:50:42 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

/* Funzione chiamata da rm_spaces che serve per riscrivere la stringa
senza gli spazi in mezzo ai redir e il loro limiter. */
char	*rewrite(char *orig, int i, int x)
{
	int		y;
	char	*dest;

	y = -1;
	dest = (char *)ft_calloc(sizeof(char), (ft_strlen(orig) - x) + 1);
	while (orig[++y])
	{
		dest[y] = orig[y];
		if (i == y)
		{
			while (orig[++y + x])
				dest[y] = orig[y + x];
			dest[y] = '\0';
			break ;
		}
	}
	free(orig);
	return (dest);
}

/* Controlla se ci sono casi di redirection, heredoc o pipe attaccati.
Nel caso ci siano li divide con uno spazio tramite la funzione divide,
in modo che poi il custom_split possa dividerli in nodi seprarati.*/
char	*here_glued(char *s)
{
	int	x;

	x = -1;
	while (s[++x])
		if ((((x != 0 && s[x] != ' ' && find_char(s, x) == 0 && \
		werami(s, x, 0, 0) == -1) || \
		(s[x] == 39 || s[x] == 34)) && find_char(s, x + 1) != 0 && \
		find_char(s, x + 1) != 3) || \
		(x != 0 && find_char(s, x) == 3 && werami(s, x, 0, 0) == -1 && \
		((s[x - 1] != ' ') || \
		(s[x + 1] != ' ' && s[x + 1] != '\0')) && x != 0))
			s = divide(s, x);
	return (s);
}

/* Funzione richiamata in refine che espande le variabili di sistema */
char	*espand(char *s, char **env)
{
	int		i;
	char	*tmp;
	char	*path;
	char	*end;

	tmp = set_str(s);
	path = set_path(tmp, env);
	if (!path)
	{
		path = (char *)ft_calloc(1, sizeof(char));
		return (free(s), path);
	}
	i = 0;
	if (find_dollar(s, 0) != -1)
		while (s[i] != '$')
			i++;
	tmp = (char *)ft_calloc(i + 1, sizeof(char));
	ft_strlcpy(tmp, s, i + 1);
	end = ft_strjoin(tmp, path);
	if (!end)
		return (free(s), free(tmp), free(path), NULL);
	return (free(s), free(tmp), free(path), end);
}

/* Funzione chiamata in refine per gestire casi particolari
di espansioni di variabili. */
char	*esp_special_case(char *s, char **env, int i)
{
	char	*tmp;
	int		start;
	int		end;

	start = find_dollar(s, i);
	end = start + 1;
	while (s[end] == '_' || ft_isalpha(s[end]) != 0 || ft_isdigit(s[end]) != 0)
		end++;
	tmp = (char *)ft_calloc(end - start, sizeof(char));
	ft_strlcpy(tmp, s + start + 1, end - start);
	tmp = espand(tmp, env);
	s = reassemble(s, tmp, s + end, end - start);
	free(tmp);
	return (s);
}

/* Controlla se ci sono variabili da espandere e, nel caso sia necessario,
toglie apici e virgolette. */
char	*refine(char *s, char **env)
{
	int	i;

	i = -1;
	while (s[++i] != '\0')
	{
		if (i > 0 && s[i - 1] == '$' && ((ft_isalpha(s[i + 1]) != 0) || \
		(s[i + 1] == '_')))
			i--;
		s = espand_core(s, &i, 1);
		s = more_espand_core(s, env, &i, 1);
		if (s[i] == '\0' || s[0] == '\0')
			return (s);
		if (s[i] == '"' && werami(s, i + 1, 0, 0) == 1)
		{
			while (s[++i] != '"' && s[i] != '\0')
			{
				s = espand_core(s, &i, 0);
				s = more_espand_core(s, env, &i, 0);
			}
		}
		if (s[i] == '\0' || s[0] == '\0')
			return (s);
		i = do_skip(s, i);
	}
	return (s);
}
