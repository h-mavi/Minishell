/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 12:43:25 by mbiagi            #+#    #+#             */
/*   Updated: 2025/05/07 17:38:38 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

static int	is_all_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
		{
			if (!(i == 0 && str[i] == '-'))
				return (0);
		}
		i++;
	}
	return (1);
}

//devo sempre tornare al nodo iniziale
void	ft_exit(t_token *tree, char **env, int *std)
{
	int	ex;

	if (tree->next)
	{
		if (tree->next->type == FLAG)
		{
			if (is_all_digit(tree->next->str) == 0)
				return (perror("not numeric argument"), free_lst(tree), \
				reset_fd(std), close(1), close(0), freemtr(env), exit(2));
			if (tree->next->next)
				if (tree->next->next->type == FLAG)
					return (perror("too many arguments"), (void)exit_code(1));
			if (is_all_digit(tree->next->str) != 0)
			{
				ex = ft_atoi(tree->next->str);
				if (ex > 256)
					return (freemtr(env), free_lst(tree), reset_fd(std), \
					close(1), close(0), exit(ex % 256));
				return (freemtr(env), free_lst(tree), reset_fd(std), \
				close(1), close(0), exit(ex));
			}
		}
	}
	return (free_lst(tree), freemtr(env), reset_fd(std), close(1), close(0), \
	exit(0));
}

static int	is_n(char *str, char c)
{
	int		i;
	char	*cmp;

	i = 0;
	cmp = ft_calloc(ft_strlen(str) + 1, sizeof(char));
	while (str[i])
	{
		cmp[i] = c;
		i++;
	}
	if (ft_strncmp(str, cmp, ft_strlen(cmp)) == 0)
		return (free(cmp), 0);
	return (free(cmp), 1);
}

static void	print_option(t_token *tree)
{
	int	i;

	i = 0;
	while (tree && tree->type != PIPE)
	{
		if (tree->type == FLAG)
		{
			if (i != 0)
				ft_printf(" ");
			ft_printf("%s", tree->str);
			i++;
		}
		tree = tree->next;
	}
}

int	ft_echo(t_token *tree)
{
	bool	n;

	n = 1;
	while (tree->type != FLAG && tree->type != PIPE && tree->next)
		tree = tree->next;
	while (tree && tree->str[0] == '-' && tree->str[1] == 'n' && \
	is_n(&tree->str[1], 'n') == 0)
	{
		n = 0;
		tree = tree->next;
	}
	print_option(tree);
	if (n == 1)
		ft_printf("\n");
	return (exit_code(0), 1);
}
// echo uidss <<b | cat <<c | cat <<a