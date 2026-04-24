/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_other.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 16:49:48 by mfanelli          #+#    #+#             */
/*   Updated: 2025/05/15 11:00:53 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char	*put_in_square(char *path)
{
	char	*end;
	int		i;

	i = 0;
	end = (char *)ft_calloc(ft_strlen(path) + 3, sizeof(char));
	end[i++] = 6;
	while (path[i - 1] != '\0')
	{
		end[i] = path[i - 1];
		i++;
	}
	end[i++] = 6;
	end[i] = '\0';
	return (free(path), end);
}

/* Funzione per contenere un if enorme utilizzato da divide. */
static int	if_divide(char *s, int i, int y)
{
	if (((((s[i] != ' ' && find_char(s, i) == 0 && werami(s, i, 0, 0) == -1) \
	|| ((s[i] == 39 || s[i] == 34) && werami(s, i + 1, 0, 0) != 1)) && \
	find_char(s, i + 1) != 0) || (find_char(s, i) == 3 && \
	werami(s, i, 0, 0) == -1 && s[i + 1] != ' ') || (find_char(s, i) == 0 && \
	find_char(s, i + 1) == 3 && s[i] != ' ')) && i <= y)
		return (1);
	return (0);
}

/* La funzione chiamata da here_glued che divide redirection,
heredoc e pipe attaccati */
char	*divide(char *s, int y)
{
	int		i;
	int		x;
	char	*end;

	i = -1;
	x = 0;
	while (s[++i])
	{
		if (if_divide(s, i, y) == 1)
			x++;
		x++;
	}
	end = (char *)ft_calloc((x + 1), sizeof(char));
	if (!end)
		return (NULL);
	i = -1;
	x = 0;
	while (s[++i])
	{
		end[x++] = s[i];
		if (if_divide(s, i, y) == 1)
			end[x++] = ' ';
	}
	end[x] = '\0';
	return (free(s), end);
}

void	other_heredoc_while(char *str, char *input, int file, int std)
{
	while (control_str(str, input) == 0)
	{
		ft_putstr_fd(str, file);
		free(str);
		write(1, "> ", 2);
		str = get_next_line(0);
		if (g_sigal == 1)
			dup2(std, 0);
	}
	free(str);
}
