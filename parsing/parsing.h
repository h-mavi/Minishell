/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:02:37 by mfanelli          #+#    #+#             */
/*   Updated: 2025/05/15 11:01:12 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H
# include "./../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include "./../execute/execute.h"
# include "token.h"

# include <stdio.h>
# include <signal.h>
# include <ctype.h>
# include <stdlib.h>
# include <strings.h>
# include <string.h>
# include <dirent.h>
# include <bsd/string.h>
# include <fcntl.h>
# include <unistd.h>
# include <linux/stat.h>
# include <sys/stat.h>
# include <stddef.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdbool.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>

# define COMMAND 1
# define FLAG 2 //option
# define PIPE 3
//<
# define REDIR_1 4
// >
# define REDIR_2 5
// >>
# define REDIR_3 6
# define HEREDOC 7
// << "$USER"
# define HEREDOC_2 8

extern int	g_sigal;

//----------------------------------------------------------------------------
//in parsing/pars_extra.c (ft 5/5)

char		*set_str(char *s);
char		*set_path(char *tmp, char **env);
int			len_arr_utils(char *s, int *i, int *x, int app);
int			count_len_wrd(char *s, int *y, int conta);
char		*ft_mycpy(char *str, int y);

//----------------------------------------------------------------------------
//in parsing/pars_heredoc.c (ft 5/5)

int			control_str(char *str, char *argv);
char		*error_exit(t_token *head, int syn, char *str, char *input);

//----------------------------------------------------------------------------
//in parsing/pars_main.c (ft 5/5)

int			parsing(char *pwd, char ***env_cpy);
int			smol(char *s, int i);
int			is_all_whitespace(char *cmd);

//----------------------------------------------------------------------------
//in parsing/pars_more.c (ft 5/5)

int			werami(char *s, int i, int a, int v);
int			rm_dollar_if(char *s, int i);
char		*set_exit_status(char *s);
char		*espand_core(char *s, int *i, int which);

//----------------------------------------------------------------------------
//in parsing/pars_other.c (ft 4/5)

char		*put_in_square(char *path);
char		*divide(char *s, int y);
void		other_heredoc_while(char *str, char *input, int file, int std);

//----------------------------------------------------------------------------
//in parsing/pars_refine.c (ft 5/5)

char		*rewrite(char *orig, int i, int x);
char		*here_glued(char *s);
char		*espand(char *s, char **env);
char		*esp_special_case(char *s, char **env, int i);
char		*refine(char *s, char **env);

//----------------------------------------------------------------------------
//in parsing/pars_rm.c (ft 5/5)

char		*rm_spaces(char *s);
char		*rm_app(char *s);
char		*rm_dollar(char *s);
char		*rm_square(char *str);

//----------------------------------------------------------------------------
//in parsing/pars_set_data.c (ft 5/5)

void		set_data(t_token **head, char **str, int flag);
void		set_prev(t_token **head);
char		**ft_env_cpy(char **env);
char		*more_espand_core(char *s, char **env, int *i, int which);

//----------------------------------------------------------------------------
//in parsing/pars_split.c (ft 5/5)

char		**custom_split(char *s);

//----------------------------------------------------------------------------
//in parsing/pars_utils.c (ft 5/5)

void		free_arr(char **arr);
int			find_char(char *s, int i);
int			find_dollar(char *s, int i);
int			check_error(char *s);
int			for_normi(char *s, int i, int what);

//----------------------------------------------------------------------------
//in parsing/parsing.c (ft 5/5)

char		*reassemble(char *first, char *espan, char *after, int len_cmd);
int			check_error_lst(t_token *head);
void		free_lst(t_token *head);
int			do_skip(char *s, int i);

//----------------------------------------------------------------------------
//in parsing/signal_handler.c (ft 4/5)

void		test(int sig);
void		routine(int sig);
void		sig_redir(int sig);
void		ctrl_c_sig(int sig);

//----------------------------------------------------------------------------

#endif