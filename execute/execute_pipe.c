/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:11:12 by mbiagi            #+#    #+#             */
/*   Updated: 2025/05/15 15:20:07 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

static int	pipe_number(t_token *tree)
{
	int	i;

	i = 0;
	while (tree)
	{
		if (tree->type == PIPE)
			i++;
		tree = tree->next;
	}
	return (i);
}

void	other_parent(t_token *tree, t_fds fds, char ***env)
{
	if (has_input_redir(tree) == 1 && is_real(tree, *env) == 1)
		dup2(fds.pipe[0], 0);
	return ((void) close(fds.pipe[0]), (void) close(fds.pipe[1]));
}

int	other_command(t_token *tree, char ***env, t_fds fds, int *n)
{
	int	pid;

	if (has_input_redir(tree) == 1 && is_real(tree, *env) == 1)
		dup2(fds.pipe[1], 1);
	else
		trick();
	if (redir_check_pipe(tree, &n, fds) == 1)
		return (other_parent(tree, fds, env), 0);
	tree = find_comand(tree);
	if (tree == NULL)
		return (0);
	pid = fork();
	if (pid == 0)
	{
		free(fds.pid);
		closeall(fds);
		if (is_builtin(tree, env, fds.std) != 1)
			exec_cmd(tree, *env);
		return (freemtr(*env), free_lst(tree), close(1), close(0), \
		exit(exit_code(12345)), 0);
	}
	return (other_parent(tree, fds, env), pid);
}

int	last_command(t_fds fds, t_token *tree, char ***env, int *n)
{
	int	pid;

	dup2(fds.std[1], 1);
	if (redir_check_pipe(tree, &n, fds) == 1)
		return ((void)close(fds.pipe[0]), (void)close(fds.pipe[1]), 0);
	tree = find_comand(tree);
	if (tree == NULL)
		return (0);
	pid = fork();
	if (pid == 0)
	{
		free(fds.pid);
		if (ft_compare(tree->str, "exit") == 0)
			return (closeall(fds), ft_exit(tree, *env, fds.std), \
			freemtr(*env), close(1), close(0), free_lst(tree), exit(0), 0);
		if (is_builtin(tree, env, fds.std) != 1)
			return (closeall(fds), exec_cmd(tree, *env), 0);
		return (freemtr(*env), free_lst(tree), closeall(fds), close(1), \
		close(0), exit(exit_code(12345)), 0);
	}
	else
		return (close(fds.pipe[1]), close(fds.pipe[0]), pid);
}

void	for_fork(t_token *tree, char ***env, t_fds fds)
{
	static int	n;
	int			npipe;
	int			p;

	n = 0;
	npipe = -1;
	p = pipe_number(tree);
	open_heredoc(tree, &fds, *env);
	fds.pid = ft_calloc(p + 1, sizeof(int));
	while (tree)
	{
		if (pipe(fds.pipe) == -1)
			return (perror("pipe failed"));
		if (++npipe < p)
			fds.pid[npipe] = other_command(tree, env, fds, &n);
		else
			fds.pid[npipe] = last_command(fds, tree, env, &n);
		tree = tree->next;
		while (tree && tree->prev->type != PIPE)
			tree = tree->next;
	}
	pipe_exit_code(0, p, fds);
	return (free(fds.pid), reset_fd(fds.std), closeall(fds));
}
