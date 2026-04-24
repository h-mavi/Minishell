/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:34:24 by mfanelli          #+#    #+#             */
/*   Updated: 2025/05/05 14:08:30 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_gnl(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr_gnl(const char *str, int c)
{
	int		i;

	i = -1;
	while (str[++i])
		if (str[i] == (char)c)
			return ((char *)str + i);
	if (str[i] == (char)c)
		return ((char *)str + i);
	return (NULL);
}

char	*ft_substr_gnl(char const *s, unsigned int start, char stop_char)
{
	char	*str;
	size_t	i;
	size_t	len;

	if (s == NULL || s[0] == '\0')
		return (NULL);
	len = 0;
	while (s[len] != stop_char && s[len] != '\0')
		len++;
	str = (char *)ft_calloc_gnl(((len - start) + 2), sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (s && s[start] != stop_char && s[start] != '\0')
		str[i++] = s[start++];
	if (s && s[start] == stop_char)
		str[i++] = '\n';
	str[i] = '\0';
	return (str);
}

void	*ft_calloc_gnl(size_t nmemb, size_t size)
{
	void	*str;

	str = malloc(nmemb * size);
	if (!str)
		return (NULL);
	ft_bzero_gnl(str, size * nmemb);
	return (str);
}

void	*ft_bzero_gnl(void *buffer, size_t count)
{
	char	*str;
	size_t	i;

	if (buffer == NULL)
		return (NULL);
	str = (char *)buffer;
	i = 0;
	while (i < count)
		str[i++] = 0;
	return (buffer);
}
