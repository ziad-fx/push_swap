/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyahansa <zyahansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:59:16 by zyahansa          #+#    #+#             */
/*   Updated: 2025/02/01 20:36:51 by zyahansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strncpy_gnl(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

static void	extract_append_helper(char **append, char **line, int *i)
{
	if ((*append)[*i] == '\n')
	{
		*line = malloc(*i + 2);
		if (!*line)
			return ;
		ft_strncpy_gnl(*line, *append, *i + 1);
		(*line)[*i + 1] = '\0';
	}
	else
	{
		*line = malloc(*i + 1);
		if (!*line)
			return ;
		ft_strncpy_gnl(*line, *append, *i);
		(*line)[*i] = '\0';
	}
}

static char	*extract_append(char **append)
{
	int		i;
	char	*line;
	char	*tmp;

	i = 0;
	tmp = NULL;
	while ((*append)[i] && (*append)[i] != '\n')
		i++;
	if ((*append)[i] == '\n')
	{
		extract_append_helper(append, &line, &i);
		tmp = ft_strdup_gnl(*append + i + 1);
		if (!tmp)
			return (NULL);
	}
	else
	{
		extract_append_helper(append, &line, &i);
		if (!line)
			return (NULL);
		tmp = NULL;
	}
	return (free(*append), *append = tmp, line);
}

static char	*read_and_append_line(int fd, char *append)
{
	int		c_bytes;
	char	*buffer;

	c_bytes = 1;
	buffer = malloc((size_t)BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (free(append), append = NULL, NULL);
	while (c_bytes > 0)
	{
		c_bytes = read(fd, buffer, BUFFER_SIZE);
		if (c_bytes < 0)
			return (free(buffer), buffer = NULL, NULL);
		if (c_bytes == 0)
			break ;
		buffer[c_bytes] = '\0';
		append = ft_strjoin_gnl(append, buffer);
		if (!append)
			return (free(buffer), buffer = NULL, NULL);
		if (ft_strchr_gnl(append, '\n'))
			break ;
	}
	free(buffer);
	return (append);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*append;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0
		|| BUFFER_SIZE > INT_MAX)
		return (free(append), append = NULL, NULL);
	append = read_and_append_line(fd, append);
	if (!append || *append == '\0')
		return (free(append), append = NULL, NULL);
	line = extract_append(&append);
	if (!line)
		return (free(line), NULL);
	return (line);
}
