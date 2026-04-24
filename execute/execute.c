/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 14:53:27 by mbiagi            #+#    #+#             */
/*   Updated: 2025/05/13 14:58:42 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

//funzione che trova il path corretto del cmd, se non lo trova retituisce NULL
char	*parse_cmd(char *argv, char **env)
{
	int		i;
	char	*command;
	char	**path;
	char	*temp;

	i = -1;
	path = NULL;
	while (env[++i])
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			path = ft_split(env[i] + 5, ':');
	if (!path)
		return (ft_strdup(argv));
	i = -1;
	while (path[++i])
	{
		temp = ft_strjoin(path[i], "/");
		command = ft_strjoin(temp, argv);
		free(temp);
		if (access(command, F_OK) == 0)
			return (freemtr(path), command);
		free(command);
	}
	return (freemtr(path), NULL);
}

//crea una matrice con cmd e flag
static char	**full_cmd(t_token *tree)
{
	t_token	*head;
	char	**mtr;
	int		option;
	int		i;

	i = 0;
	head = tree;
	option = 1;
	while (tree && tree->type != PIPE)
	{
		if (tree->type == FLAG || tree->type == COMMAND)
			option++;
		tree = tree->next;
	}
	mtr = ft_calloc(option, sizeof(char *));
	tree = head;
	while (tree && tree->type != PIPE)
	{
		if (tree->type == FLAG || tree->type == COMMAND)
			mtr[i++] = ft_strdup(tree->str);
		tree = tree->next;
	}
	return (mtr);
}

//controllo se il comando e' una builtin e nel caso eseguo
int	is_builtin(t_token *tree, char ***env, int *std)
{
	if (ft_compare(tree->str, "env") == 0)
		return (ft_env(tree, *env));
	if (ft_compare(tree->str, "export") == 0)
		return (ft_export(env, tree->next));
	if (ft_compare(tree->str, "exit") == 0)
		return (ft_printf("exit\n"), ft_exit(tree, *env, std), 1);
	if (ft_compare(tree->str, "echo") == 0)
		return (ft_echo(tree));
	if (ft_compare(tree->str, "cd") == 0)
		return (ft_cd(tree->next, *env));
	if (ft_compare(tree->str, "pwd") == 0)
		return (ft_pwd());
	if (ft_compare(tree->str, "unset") == 0)
		return (ft_unset(tree->next, env));
	return (0);
}

//funzione che esegue i comandi
void	exec_cmd(t_token *tree, char **env)
{
	char	*path;
	char	**arg;

	signal(SIGQUIT, SIG_DFL);
	path = parse_cmd(tree->str, env);
	arg = full_cmd(tree);
	if (!path)
		path = ft_strdup(arg[0]);
	free_lst(tree);
	execve(path, arg, env);
	if (arg[0][0] == '\0')
		write (2, "\"\"", 3);
	else
		write(2, arg[0], ft_strlen(arg[0]));
	perror(" :command not found");
	return (free(path), freemtr(arg), freemtr(env), close(1), \
	close(0), exit(127));
}

//funzione principale che richiama le altre
void	execute(t_token *tree, char ***env)
{
	int		pid;
	t_fds	fds;
	int		n;

	fds.std[0] = dup(0);
	fds.std[1] = dup(1);
	signal(SIGINT, ctrl_c_sig);
	if (pipe_check(tree) == 1)
		return (for_fork(tree, env, fds));
	if (redir_check(tree, fds, *env) == 1)
		return (reset_fd(fds.std));
	tree = find_comand(tree);
	if (tree == NULL || g_sigal == 1)
		return (reset_fd(fds.std));
	if (is_builtin(tree, env, fds.std) == 1)
		return (reset_fd(fds.std));
	pid = fork();
	if (pid == 0)
		(close(fds.std[0]), close(fds.std[1]), exec_cmd(tree, *env));
	wait(&n);
	exit_code(n / 256);
	if (g_sigal == 1)
		exit_code(130);
	reset_fd(fds.std);
}
