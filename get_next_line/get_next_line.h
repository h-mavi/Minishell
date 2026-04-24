/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:34:35 by mfanelli          #+#    #+#             */
/*   Updated: 2025/05/05 14:08:18 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <stdarg.h>
# include <fcntl.h>

size_t	ft_strlen_gnl(const char *str);
char	*ft_copy(char *bois);
char	*ft_substr_gnl(char const *s, unsigned int start, char stop_char);
char	*ft_prep(char *next);
char	*ft_backup(char *next, char *buff);
char	*ft_read(char *next, char *buff, int fd);
char	*get_next_line(int fd);
char	*ft_strchr_gnl(const char *str, int c);
void	*ft_calloc_gnl(size_t nmemb, size_t size);
void	*ft_bzero_gnl(void *buffer, size_t count);

#endif
