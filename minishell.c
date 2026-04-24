/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:14:58 by mfanelli          #+#    #+#             */
/*   Updated: 2025/05/06 09:04:33 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_sigal = 0;

int	main(int argc, char *argv[], char **env)
{
	char	*temp;
	char	*pwd;
	char	**env_cpy;

	(void)argc;
	(void)argv;
	signal(SIGINT, routine);
	signal(SIGQUIT, SIG_IGN);
	env_cpy = ft_env_cpy(env);
	while (1)
	{
		g_sigal = 0;
		temp = getcwd(NULL, 0);
		pwd = ft_strjoin(temp, "$ ");
		free(temp);
		if (parsing(pwd, &env_cpy) == 0)
			break ;
		signal(SIGINT, routine);
	}
	free_arr(env_cpy);
	return (0);
}
