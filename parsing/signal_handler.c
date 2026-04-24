/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 11:47:15 by mfanelli          #+#    #+#             */
/*   Updated: 2025/05/15 12:40:37 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

/* Funzione che gestisce i segnali ^C e ^\ per gli heredoc.*/
void	test(int sig)
{
	if (sig == SIGQUIT)
		write(0, "\b\b  \b\b", 6);
	if (sig == SIGINT)
	{
		g_sigal = 1;
		exit_code(130);
		close(0);
	}
}

/* gestisce i segnali con SIGINT (^c), enter vuoto
e enter con solo spazi/tab */
void	routine(int sig)
{
	if (sig == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		exit_code(130);
	}
	if (sig == -1)
	{
		rl_on_new_line();
		rl_replace_line("", 0);
	}
	if (sig == -2)
	{
		rl_on_new_line();
		rl_replace_line("", 0);
	}
}

/* Gestisce il ^C in caso di redirection. Non va a capo...
non so perche'*/
void	sig_redir(int sig)
{
	if (sig == SIGINT)
	{
		write(2, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		g_sigal = 1;
	}
}

/* Gestisce il ^C per i comandi (es. con cat in attesa).*/
void	ctrl_c_sig(int sig)
{
	if (sig == SIGINT)
	{
		if (isatty(1) == 1)
			printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		g_sigal = 1;
	}
}
