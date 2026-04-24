/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_redir_pipe.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 11:21:40 by mbiagi            #+#    #+#             */
/*   Updated: 2025/05/15 15:40:44 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

void	pipe_exit_code(int npipe, int p, t_fds fds)
{
	int	w;

	w = 0;
	(void)npipe;
	waitpid(fds.pid[p], &w, 0);
	if ((w & 0x7F) == 0)
		exit_code((w >> 8) & 0xFF);
	else
		exit_code(128 + (w & 0x7F));
	while (wait(&w) != -1)
		;
}

static int	check_redir_out(t_token *tree, int file)
{
	if (tree->type == REDIR_2)
		file = open(tree->str, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	else if (tree->type == REDIR_3)
		file = open(tree->str, O_WRONLY | O_CREAT | O_APPEND, 0777);
	if (file_control(file, 1) == 1)
		return (1);
	return (0);
}

int	redir_check_pipe(t_token *tree, int **n, t_fds fds)
{
	int	file;

	while (tree != NULL && tree->type != PIPE)
	{
		if (tree->type == REDIR_1)
		{
			file = open(tree->str, O_RDONLY);
			if (file_control(file, 0) == 1)
				return (1);
		}
		else if ((tree->type == HEREDOC || tree->type == HEREDOC_2) && \
		g_sigal == 0)
		{
			if (file_control(fds.heredoc[**n], 0) == 1)
				return (1);
			(**n)++;
		}
		else if (tree->type == REDIR_2 || tree->type == REDIR_3)
			if (check_redir_out(tree, file) == 1)
				return (1);
		tree = tree->next;
	}
	return (0);
}

void	heredoc_for_normi(t_token *tree, char *str, char **env, t_fds *fds)
{
	if (g_sigal == 1)
		dup2(fds->std[0], 0);
	heredoc_while(tree, str, env, fds);
	get_next_line(fds->file);
	close(fds->file);
	fds->file = open("here_doc", O_RDWR, 0777);
	unlink("here_doc");
}

void	open_heredoc(t_token *tree, t_fds *fds, char **env)
{
	char	*str;
	int		i;

	i = -1;
	fds->heredoc[0] = 0;
	while (tree != NULL && g_sigal == 0)
	{
		if (tree->type != HEREDOC && tree->type != HEREDOC_2)
		{
			tree = tree->next;
			continue ;
		}
		fds->file = open("here_doc", O_RDWR | O_CREAT | O_TRUNC, 0777);
		if (fds->file == -1)
			return (perror("failed to open the file"), (void)exit_code(1));
		write(0, "> ", 2);
		signal(SIGQUIT, test);
		signal(SIGINT, test);
		str = get_next_line(0);
		heredoc_for_normi(tree, str, env, fds);
		fds->heredoc[++i] = fds->file;
		tree = tree->next;
	}
	fds->heredoc[++i] = 0;
}
