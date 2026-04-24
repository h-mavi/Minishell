/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:23:18 by mfanelli          #+#    #+#             */
/*   Updated: 2025/05/13 17:07:48 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

/* Fa la comparazione tra l'input dato dallo user e il limiter
dell'heredoc */
int	control_str(char *str, char *argv)
{
	if (str == NULL)
		return (write(0, "\n", 2), 1);
	if (argv[0] == '<')
		argv = argv + 2;
	if ((ft_strncmp(str, argv, ft_strlen(argv)) == 0) && \
	str[ft_strlen(argv)] == '\n')
		return (1);
	return (0);
}

/* Apre l'heredoc usando input come limiter */
static void	here_doc(char *input)
{
	char	*str;
	int		file;
	int		std;

	std = dup(0);
	file = open("here_doc", O_RDWR | O_CREAT | O_TRUNC, 0777);
	if (file == -1)
		return ;
	write(1, "> ", 2);
	signal(SIGINT, test);
	str = get_next_line(0);
	if (g_sigal == 1)
		dup2(std, 0);
	other_heredoc_while(str, input, file, std);
	close(std);
	get_next_line(file);
	close(file);
	unlink("here_doc");
}

/* Filtra la lista head fino al nodo 'where' 
per trovare gli heredoc da aprire */
static void	ft_openhd_ls(t_token *head, int where)
{
	signal(SIGQUIT, test);
	while (head->id < where)
	{
		if ((head->type == HEREDOC || head->type == HEREDOC_2) && \
		g_sigal == 0)
			here_doc(head->str);
		head = head->next;
	}
}

/* Filtra la stringa str fino all'indice 'where'
per trovare gli heredoc da aprire */
static void	ft_openhd_str(char *str, int where, int i)
{
	int		x;
	char	*tmp;

	tmp = NULL;
	signal(SIGQUIT, test);
	if ((size_t)where == ft_strlen(str) - 1)
		if (find_char(str, where - 1) != 0 && where > 0)
			where -= 1;
	while (str[++i] && i < where)
	{
		if ((find_char(str, i) == HEREDOC || find_char(str, i) == HEREDOC_2) \
		&& g_sigal == 0)
		{
			x = i + 2;
			while (str[x] != ' ' && find_char(str, x) == 0)
				x++;
			if (x > where)
				continue ;
			tmp = ft_substr(str, i, x - i);
			if (find_char(str, i) == HEREDOC_2)
				tmp = rm_app(tmp);
			here_doc(tmp);
			free(tmp);
		}
	}
}

/* Funzione da chiamare in caso di errore! Libera la lista head e
la stringa input e controlla se ci sono heredoc tramite syn.
Se syn != -1 allora gli heredoc sono da aprire (in caso
di errore di sintassi). */
char	*error_exit(t_token *head, int syn, char *str, char *input)
{
	printf("%s", str);
	if (syn != -1)
		exit_code(2);
	if (syn != -1 && head != NULL && input == NULL)
		ft_openhd_ls(head, syn);
	else if (syn != -1 && head == NULL && input != NULL)
		ft_openhd_str(input, syn, -1);
	if (input != NULL)
		free(input);
	if (head != NULL)
		free_lst(head);
	return (NULL);
}
