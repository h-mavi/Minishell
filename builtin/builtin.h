/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:32:42 by mbiagi            #+#    #+#             */
/*   Updated: 2025/04/29 15:45:58 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include "../execute/execute.h"
# include "../printf/ft_printf.h"
# include "../parsing/token.h"

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
# define FLAG 2
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

//----------------------------------------------------------------------------
//in builtin/builtin_env_controls.c (ft 5/5)

int		control_variable(char *var);
int		existing_variable(char *var, char **env);
int		new_variable(char *var, char **env);
char	*string_control(char *str);
size_t	until(char *str);

//----------------------------------------------------------------------------
//in builtin/builtin_env_utils.c (ft 4/5)

char	**unset_param(t_token *tree, char **env);
void	print_export(char **env);
char	**change_param(t_token *tree, char **env);
char	**export_param(t_token *tree, char **env);

//----------------------------------------------------------------------------
//in builtin/builtin_env.c (ft 3/5)

int		ft_env(t_token *tree, char **env);
int		ft_export(char ***env, t_token *tree);
int		ft_unset(t_token *tree, char ***env);

//----------------------------------------------------------------------------
//in builtin/builtin.c (ft 5/5)

int		ft_pwd(void);
int		num_argument(t_token *tree);
int		ft_cd(t_token *tree, char **env);

//----------------------------------------------------------------------------
//in builtin/builtin2.c (ft 5/5)

void	ft_exit(t_token *tree, char **env, int *std);
int		ft_echo(t_token *tree);

//----------------------------------------------------------------------------

#endif