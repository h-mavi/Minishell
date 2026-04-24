/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 11:02:08 by mbiagi            #+#    #+#             */
/*   Updated: 2025/05/15 11:42:43 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

void	heredoc_while(t_token *tree, char *str, char **env, t_fds *fds)
{
	while (ctrl_str(str, tree->str) == 0)
	{
		if (tree->type == HEREDOC)
			str = simple_refine(str, env);
		ft_putstr_fd(str, fds->file);
		free(str);
		write(0, "> ", 2);
		str = get_next_line(0);
		if (g_sigal == 1)
			dup2(fds->std[0], 0);
	}
	free(str);
}

void	closeall(t_fds fds)
{
	int	i;

	i = 0;
	close(fds.pipe[0]);
	close(fds.pipe[1]);
	close(fds.std[0]);
	close(fds.std[1]);
	while (fds.heredoc[i] != 0)
	{
		close(fds.heredoc[i]);
		i++;
	}
}

int	has_input_redir(t_token *tree)
{
	while (tree->type != PIPE)
		tree = tree->next;
	tree = tree->next;
	while (tree != NULL && tree->type != PIPE)
	{
		if (tree->type == REDIR_1 || tree->type == HEREDOC || \
			tree->type == HEREDOC_2)
			return (0);
		tree = tree->next;
	}
	return (1);
}

void	trick(void)
{
	int	null;

	null = open("/dev/null", O_WRONLY);
	dup2(null, 1);
	close(null);
}

int	is_real(t_token *tree, char **env)
{
	char	*str;

	while (tree->type != PIPE)
		tree = tree->next;
	tree = tree->next;
	tree = find_comand(tree);
	if (tree == NULL)
		return (0);
	str = parse_cmd(tree->str, env);
	if (!str)
		return (0);
	return (free(str), 1);
}
