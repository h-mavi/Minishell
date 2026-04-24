/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 11:01:48 by mbiagi            #+#    #+#             */
/*   Updated: 2025/05/09 09:33:09 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

//controlla il limiter dell' heredoc
int	ctrl_str(char *str, char *limiter)
{
	if (str == NULL)
		return (write(0, "\n", 2), 1);
	if ((ft_strncmp(str, limiter, ft_strlen(limiter)) == 0) && \
	str[ft_strlen(limiter)] == '\n')
		return (1);
	return (0);
}

//funzione ausiliaria che libera la matrice
void	freemtr(char **mtr)
{
	int	i;

	i = 0;
	while (mtr[i])
	{
		free(mtr[i]);
		i++;
	}
	free(mtr[i]);
	free(mtr);
}

//funzione ausiliaria che ripristina le stdfds
void	reset_fd(int *std)
{
	dup2(std[0], 0);
	dup2(std[1], 1);
	close(std[0]);
	close(std[1]);
}

//funzione ausiliaria ch emi serve per comparare
// il nome dei comandi alle builtin
int	ft_compare(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (1);
		i++;
	}
	if (s1[i] == '=' && s2[i] == '\0')
		return (0);
	if (s1[i] != s2[i])
		return (1);
	else
		return (0);
}

int	ft_compare2(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s2[i] != '=' && s1[i] != '=' && s1[i] != '+' && \
		s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (1);
		i++;
	}
	if ((s1[i] == '=' || s1[i] == '+') && s2[i] == '_')
		return (0);
	if ((s2[i] == '=' && (s1[i] == '=' || s1[i] == '+')) && \
	(s1[i - 1] == s2[i - 1]))
		return (0);
	else
		return (1);
}
