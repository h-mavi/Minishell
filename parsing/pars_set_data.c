/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_set_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 08:42:14 by mfanelli          #+#    #+#             */
/*   Updated: 2025/05/15 10:24:00 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

/* Funzione che aggiunge il nodo new infondo alla lista di tipo t_token lst */
static void	lstadd_back(t_token **lst, t_token *new)
{
	t_token	*ex;

	ex = NULL;
	if (!new || !lst)
		return ;
	if (*lst && lst[0])
	{
		ex = *lst;
		while (ex->next != NULL)
			ex = ex->next;
		ex->next = new;
	}
	else
		*lst = new;
	return ;
}

/* Setta i dati della lista di tipo t_token */
void	set_data(t_token **head, char **str, int flag)
{
	t_token		*node;
	static int	id = 0;

	if (head == NULL)
	{
		id = 0;
		return ;
	}
	node = (t_token *)ft_calloc(1, sizeof(t_token));
	if (!node)
		return ;
	*str = rm_app(*str);
	*str = rm_square(*str);
	(*node).type = flag;
	if (flag == REDIR_1 || flag == REDIR_2)
		(*node).str = ft_strdup(*str + 1);
	else if (flag == REDIR_3 || flag == HEREDOC || \
		flag == HEREDOC_2)
		(*node).str = ft_strdup(*str + 2);
	else
		(*node).str = ft_strdup(*str);
	(*node).id = id++;
	lstadd_back(head, node);
}

/* Setta gli indirizzi dei nodi precedenti per ogni nodo della lista */
void	set_prev(t_token **head)
{
	t_token	*prima;
	t_token	*corr;

	prima = *head;
	corr = prima->next;
	prima->prev = NULL;
	while (corr != NULL)
	{
		corr->prev = prima;
		prima = corr;
		corr = corr->next;
	}
	return ;
}

/* Funzione per copiare l'env */
char	**ft_env_cpy(char **env)
{
	char	**new_env;
	int		i;

	i = 0;
	new_env = (char **)ft_calloc(ft_matrixlen(env) + 1, sizeof(char *));
	while (env[i])
	{
		new_env[i] = ft_strdup(env[i]);
		i++;
	}
	return (new_env);
}

/* Funzione creata per colpa di norminette, chiamata da simple_refine e da
refine. */
char	*more_espand_core(char *s, char **env, int *i, int which)
{
	if (which == 1)
	{
		if (werami(s, *i, 0, 0) == -1 && werami(s, *i + 1, 0, 0) == -1 && \
			smol(s, *i) != 0)
		{
			s = esp_special_case(s, env, *i);
			*i = for_normi(s, *i, 2);
		}
		else if (s[*i] == '$' && werami(s, *i + 1, 0, 0) == 0 && \
			werami(s, *i, 0, 0) == -1)
		{
			s = rm_dollar(s);
			*i = for_normi(s, *i, 1);
		}
	}
	else if (which == 0)
	{
		if (werami(s, *i, 0, 0) == 1 && smol(s, *i) != 0)
		{
			s = esp_special_case(s, env, *i);
			*i = for_normi(NULL, *i, 0);
		}
	}
	return (s);
}
