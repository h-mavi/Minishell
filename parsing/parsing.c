/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 14:52:21 by mbiagi            #+#    #+#             */
/*   Updated: 2025/05/13 10:28:41 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

/* Essenziale per riassemblare la stringa per un caso speciale
di espansione */
char	*reassemble(char *first, char *espan, char *after, int len_cmd)
{
	char	*end;
	int		i;
	int		x;

	end = (char *)ft_calloc((ft_strlen(first) - len_cmd + ft_strlen(espan)) \
	+ 1, sizeof(char));
	i = 0;
	x = -1;
	while (++x < find_dollar(first, ft_strlen(first) - len_cmd - \
	ft_strlen(after)))
		end[i++] = first[x];
	x = -1;
	while (espan[++x] != '\0')
		end[i++] = espan[x];
	x = -1;
	while (after[++x] != '\0')
		end[i++] = after[x];
	end[i] = '\0';
	free(first);
	return (end);
}

/* Controlla errori filtrando la lista. */
int	check_error_lst(t_token *head)
{
	t_token	*prima;
	t_token	*dopo;

	prima = head;
	dopo = prima->next;
	if (prima->type == PIPE || prima->str[0] == ';')
		return (error_exit(head, -1, \
		"Syntax Error, unexpected token at the start of input\n", NULL), \
		exit_code(2), 0);
	while (dopo != NULL)
	{
		if (dopo->type == PIPE && prima->type == PIPE)
			return (error_exit(head, prima->id, \
			"Syntax Error, unexpected token '|'\n", NULL), 0);
		prima = dopo;
		dopo = prima->next;
	}
	if (prima->type == PIPE)
		return (error_exit(head, -1, \
		"Syntax Error, unexpected token '|' at the end of input\n", NULL), \
		exit_code(2), 0);
	return (1);
}

/* Serve a liberare una lista. */
void	free_lst(t_token *head)
{
	t_token	*tmp;

	while (head->prev)
		head = head->prev;
	while (head->next != NULL)
	{
		free((char *)(*head).str);
		tmp = head;
		head = head->next;
		free(tmp);
	}
	free((char *)(*head).str);
	free(head);
}

/* Funzione che serve per limitare le linee, chiamata da refine, controlla
se ci sono doppi dollari da saltare. */
int	do_skip(char *s, int i)
{
	if (s[i] == '$' && s[i + 1] == '$' && werami(s, i + 2, 0, 0) != 0 && \
		s[i + 2] != '\0')
		return (i + 2);
	return (i);
}
