/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_redir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 12:15:05 by mbiagi            #+#    #+#             */
/*   Updated: 2025/05/13 16:55:39 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

static char	*simple_espand_core(char *s, int *i, char **env)
{
	*i = do_skip(s, *i);
	if (s[*i] == '$' && ft_isdigit(s[*i + 1]) != 0 && \
		werami(s, *i, 0, 0) == -1)
		s = ft_mycpy(s, *i);
	if (s[*i] == '$' && s[*i + 1] == '?' && werami(s, *i, 0, 0) == -1)
		s = set_exit_status(s);
	if (werami(s, *i, 0, 0) == -1 && werami(s, *i + 1, 0, 0) == -1 && \
	smol(s, *i) != 0)
	{
		s = esp_special_case(s, env, *i);
		*i = for_normi(s, *i, 2);
	}
	return (s);
}

char	*simple_refine(char *s, char **env)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (i > 0 && s[i - 1] == '$' && \
		((ft_isalpha(s[i + 1]) != 0) || (s[i + 1] == '_')))
			i--;
		s = simple_espand_core(s, &i, env);
		if (s[i] == '\0' || s[0] == '\0')
			return (s);
		if (werami(s, i, 0, 0) == 0 && werami(s, i + 1, 0, 0) == 1)
		{
			while (werami(s, ++i, 0, 0) != 0 && s[i] != '\0')
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

//funzione che crea l' heredoc e lo duplica nello stdin
void	heredoc(t_token *tree, t_fds fds, char **env)
{
	char	*str;

	dup2(fds.std[0], 0);
	fds.file = open("here_doc", O_RDWR | O_CREAT | O_TRUNC, 0777);
	if (fds.file == -1)
		return (perror("failed to open the file"), (void)exit_code(1));
	write(0, "> ", 2);
	signal(SIGQUIT, test);
	signal(SIGINT, test);
	str = get_next_line(0);
	if (g_sigal == 1)
		dup2(fds.std[0], 0);
	heredoc_while(tree, str, env, &fds);
	get_next_line(fds.file);
	close(fds.file);
	fds.file = open("here_doc", O_RDWR, 0777);
	file_control(fds.file, 0);
	unlink("here_doc");
}

//redirige i file
int	redir_check(t_token *tree, t_fds fds, char **env)
{
	int	file;

	while (tree != NULL && tree->type != PIPE && g_sigal == 0)
	{
		if (tree->type == REDIR_1)
		{
			file = open(tree->str, O_RDONLY);
			if (file_control(file, 0) == 1)
				return (1);
		}
		else if (tree->type == HEREDOC || tree->type == HEREDOC_2)
			heredoc(tree, fds, env);
		else if (tree->type == REDIR_2 || tree->type == REDIR_3)
		{
			signal(SIGINT, sig_redir);
			if (tree->type == REDIR_2)
				file = open(tree->str, O_WRONLY | O_CREAT | O_TRUNC, 0777);
			else if (tree->type == REDIR_3)
				file = open(tree->str, O_WRONLY | O_CREAT | O_APPEND, 0777);
			if (file_control(file, 1) == 1)
				return (1);
		}
		tree = tree->next;
	}
	return (0);
}
