/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:02:05 by mfanelli          #+#    #+#             */
/*   Updated: 2025/05/15 12:39:58 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

/* Compila la lista con i nodi-token */
static void	compile_inator(char **str, char **env, t_token **head)
{
	int	i;
	int	check;

	i = -1;
	check = 0;
	while (str[++i] != NULL)
	{
		str[i] = refine(str[i], env);
		if (str[i][0] == '\0')
			continue ;
		if (check == 0 && find_char(str[i], 0) == 0)
		{
			set_data(head, &str[i], COMMAND);
			check = 1;
		}
		else if (find_char(str[i], 0) != 3 && find_char(str[i], 0) != 0)
			set_data(head, &str[i], find_char(str[i], 0));
		else if (find_char(str[i], 0) == PIPE)
		{
			set_data(head, &str[i], PIPE);
			check = 0;
		}
		else
			set_data(head, &str[i], FLAG);
	}
}

/* Chiama custom_split e il compile_inator e poi returno la lista
liberando anche l'array*/
static t_token	*token_inator(char *cmd, char **env, t_token *head)
{
	char	**str;

	str = custom_split(cmd);
	if (!str)
		return (NULL);
	compile_inator(str, env, &head);
	if (!head)
		return (free_arr(str), head);
	set_data(NULL, NULL, 0);
	if (check_error_lst(head) == 0)
		return (free_arr(str), NULL);
	set_prev(&head);
	return (free_arr(str), head);
}

/* Registra l'history, gestisce ^D e chiama token_inator ed execute.*/
int	parsing(char *pwd, char ***env_cpy)
{
	char	*cmd;
	t_token	*head;

	cmd = readline(pwd);
	head = NULL;
	free(pwd);
	if (!cmd)
	{
		printf("exit\n");
		free(cmd);
		return (close(0), close(1), 0);
	}
	else if (cmd[0] == '\0')
		return (free(cmd), routine(-1), 1);
	else if (is_all_whitespace(cmd) == 0)
		return (free(cmd), routine(-2), 1);
	add_history(cmd);
	head = token_inator(cmd, *env_cpy, head);
	if (head == NULL)
		return (1);
	execute(head, env_cpy);
	if (head != NULL)
		free_lst(head);
	return (1);
}

/* Funzione creata per colpa di norminette, usata da simple_espand_core e da
more_espand_core.*/
int	smol(char *s, int i)
{
	if (s[i] == '$' && ((ft_isalpha(s[i + 1]) != 0) || (s[i + 1] == '_')))
		return (1);
	return (0);
}

/* Controlla che l'input mandato non sia solo composto di whitespaces.*/
int	is_all_whitespace(char *cmd)
{
	int		i;
	size_t	x;

	i = 0;
	x = 0;
	while (cmd[i] != '\0' && cmd[i] != '\n')
	{
		if (cmd[i] > 0 && cmd[i] < 33)
			x++;
		i++;
	}
	if (x == ft_strlen(cmd))
		return (0);
	return (1);
}
