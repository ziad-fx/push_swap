/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyahansa <zyahansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:33:36 by zyahansa          #+#    #+#             */
/*   Updated: 2025/02/03 17:49:10 by zyahansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_len_word(const char *s, int start, char c)
{
	int	len;

	len = 0;
	while (s[start] && s[start] != c)
	{
		len++;
		start++;
	}
	return (len);
}

static int	count_words(const char *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			count++;
			in_word = 1;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static void	freemyhomie(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

static char	*fill_word(const char *s, int *i, char c)
{
	int		length;
	char	*res;
	int		j;

	length = count_len_word(s, *i, c);
	res = malloc(length + 1);
	if (!res)
		return (NULL);
	j = 0;
	while (j < length)
		res[j++] = s[(*i)++];
	res[j] = '\0';
	return (res);
}

char	**ft_split(const char *s, char c)
{
	int		i;
	int		word_index;
	char	**tab;

	i = 0;
	word_index = 0;
	if (!s)
		return (NULL);
	tab = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!tab)
		return (NULL);
	while (s[i])
	{
		if (s[i] != c)
		{
			tab[word_index] = fill_word(s, &i, c);
			if (!tab[word_index])
				return (freemyhomie(tab), tab = NULL, NULL);
			word_index++;
		}
		else
			i++;
	}
	tab[word_index] = NULL;
	return (tab);
}
// #include <stdio.h>
// int main()
// {
// 	char s1[] = "";
// 	char **tmp = ft_split(s1, ' ');
// 	int i = 0;
// 	while(tmp[i])
// 	{
// 		printf("%ld\n", ft_atoi(tmp[i]));
// 		i++;
// 	}
// }