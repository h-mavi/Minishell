/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:36:43 by mbiagi            #+#    #+#             */
/*   Updated: 2025/05/12 10:30:48 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	ft_pwd(void)
{
	char	*str;

	str = getcwd(NULL, 0);
	ft_printf("%s\n", str);
	free(str);
	return (exit_code(0), 1);
}

int	num_argument(t_token *tree)
{
	int	i;

	i = 0;
	while (tree && tree->type != PIPE)
	{
		if (tree->type == FLAG)
			return (1);
		i++;
		tree = tree->next;
	}
	return (0);
}

static void	change_dir(char **env, char *temp)
{
	int		i;
	char	*temp2;

	i = 0;
	temp2 = getcwd(NULL, 0);
	while (env[i])
	{
		if (ft_compare(env[i], "PWD") == 0)
		{
			free(env[i]);
			env[i] = ft_strjoin("PWD=", temp2);
		}
		else if (ft_compare(env[i], "OLDPWD") == 0)
		{
			free(env[i]);
			env[i] = ft_strjoin("OLDPWD=", temp);
		}
		i++;
	}
	free(temp2);
	free(temp);
}

static void	return_home(char **env)
{
	int	i;

	i = 0;
	exit_code(0);
	while (env[i])
	{
		if (ft_compare(env[i], "HOME") == 0)
		{
			chdir(env[i] + 5);
			return ;
		}
		i++;
	}
	perror("HOME not set");
	exit_code(1);
}

int	ft_cd(t_token *tree, char **env)
{
	char	*temp;
	int		i;

	i = -1;
	temp = getcwd(NULL, 0);
	if (tree == NULL || tree->type == PIPE)
	{
		return_home(env);
		change_dir(env, temp);
		return (1);
	}
	if (num_argument(tree->next) != 0)
		return (perror("too many argument"), free(temp), exit_code(1), 1);
	else if (tree->str[0] == '-' && tree->str[1] == '\0')
	{
		while (env[++i])
			if (ft_strncmp(env[i], "OLDPWD", 6) == 0)
				if (chdir(env[i] + 7) == -1)
					perror("no such directory");
	}
	else if (chdir(tree->str) == -1)
		return (perror("no such directory"), free(temp), exit_code(1), 1);
	change_dir(env, temp);
	return (exit_code(0), 1);
}
