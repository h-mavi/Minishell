/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 08:56:13 by mbiagi            #+#    #+#             */
/*   Updated: 2025/05/15 16:01:53 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	ft_env(t_token *tree, char **env)
{
	int	i;
	int	j;

	i = 0;
	if (num_argument(tree->next) != 0)
		return (perror("too many argument"), exit_code(1), 1);
	while (env[i])
	{
		j = 0;
		while (env[i][j])
		{
			if (env[i][j] == '=')
			{
				ft_printf("%s\n", env[i]);
				break ;
			}
			j++;
		}
		i++;
	}
	return (exit_code(0), 1);
}

int	ft_export(char ***env, t_token *tree)
{
	if (tree == NULL)
		return (print_export(*env), 1);
	if (tree->type == PIPE)
		return (print_export(*env), 1);
	while (tree)
	{
		if (tree->type == FLAG)
		{
			if (control_variable(tree->str) == 1)
			{
				if (new_variable(tree->str, *env) == 1)
					*env = export_param(tree, *env);
				else
					*env = change_param(tree, *env);
			}
		}
		tree = tree->next;
	}
	return (1);
}

int	ft_unset(t_token *tree, char ***env)
{
	exit_code(0);
	while (tree)
	{
		if (tree->type == FLAG)
		{
			if (control_variable(tree->str) == 1 && \
			(!ft_strchr(tree->str, '=')) == 1)
			{
				if (existing_variable(tree->str, *env) == 0)
					*env = unset_param(tree, *env);
			}
			else
				exit_code(1);
		}
		tree = tree->next;
	}
	return (1);
}
