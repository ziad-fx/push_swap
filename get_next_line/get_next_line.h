/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyahansa <zyahansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 20:52:43 by zyahansa          #+#    #+#             */
/*   Updated: 2025/02/01 20:52:44 by zyahansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

char	*get_next_line(int fd);
char	*ft_strdup_gnl(const char *s);
char	*ft_strchr_gnl(const char *s, int c);
char	*ft_strjoin_gnl(char	*s1, char *s2);
size_t	ft_strlen_gnl(const char *s);
char	*ft_strcpy_gnl(char *dest, char *src);

#endif