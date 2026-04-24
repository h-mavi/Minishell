/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 12:37:35 by mbiagi            #+#    #+#             */
/*   Updated: 2025/05/09 10:33:24 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

char	**unset_param(t_token *tree, char **env)
{
	char	**new_env;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new_env = ft_calloc(ft_matrixlen(env), sizeof(char *));
	while (env[i])
	{
		if (ft_strncmp(env[i], tree->str, \
		ft_strlen(tree->str)) != 0)
		{
			new_env[j] = ft_strdup(env[i]);
			j++;
		}
		i++;
	}
	freemtr(env);
	return (new_env);
}

void	print_env_var(char *var)
{
	int		i;
	bool	n;

	i = -1;
	n = 0;
	write(1, "declare -x ", 11);
	while (var[++i])
	{
		write(1, &var[i], 1);
		if (var[i] == '=' && n != 1)
		{
			write(1, "\"", 1);
			n = 1;
		}
		if (var[i + 1] == '\0' && n == 1)
			write(1, "\"", 1);
	}
	write (1, "\n", 1);
}

void	print_export(char **env)
{
	int		i;
	int		j;
	char	*temp;
	char	*temp2;

	i = 0;
	j = 0;
	temp = "@@";
	while (i <= (int)ft_matrixlen(env) - 1)
	{
		j = -1;
		temp2 = "\0";
		while (env[++j])
		{
			if (temp2[0] == '\0' && ft_strncmp(temp, env[j], 4294967295) < 0)
				temp2 = env[j];
			if (temp2[0] != '\0' && ft_strncmp(temp2, env[j], 4294967295) \
			> 0 && ft_strncmp(temp, env[j], 4294967295) < 0)
				temp2 = env[j];
		}
		if (temp2[0] != '_')
			print_env_var(temp2);
		temp = temp2;
		i++;
	}
}

char	**change_param(t_token *tree, char **env)
{
	char	**new_env;
	int		i;

	i = 0;
	new_env = ft_calloc((ft_matrixlen(env) + 1), sizeof(char *));
	while (env[i])
	{
		if (ft_compare2(tree->str, env[i]) == 0)
		{
			if (tree->str[until(tree->str)] == '+')
				new_env[i] = ft_strjoin(env[i], \
				(tree->str + until(tree->str) + 2));
			else if (tree->str[until(tree->str)] == '=')
				new_env[i] = ft_strdup(tree->str);
			else
				new_env[i] = ft_strdup(env[i]);
		}
		else
			new_env[i] = ft_strdup(env[i]);
		i++;
	}
	return (freemtr(env), new_env);
}

char	**export_param(t_token *tree, char **env)
{
	int		i;
	char	**new_env;

	i = 0;
	new_env = ft_calloc((ft_matrixlen(env) + 2), sizeof(char *));
	while (env[i])
	{
		new_env[i] = ft_strdup(env[i]);
		i++;
	}
	new_env[i] = string_control(tree->str);
	new_env[i + 1] = NULL;
	return (freemtr(env), new_env);
}
