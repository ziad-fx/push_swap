/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyahansa <zyahansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:10:20 by zyahansa          #+#    #+#             */
/*   Updated: 2025/02/03 17:49:36 by zyahansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//don't forget this kkhra -->
// kkhra : "   " '    ' 1 2 3 "    ";
int	ft_check_is_sorted(char **holder)
{
	int	i;

	i = 0;
	while (holder[i] && holder[i + 1])
	{
		if (ft_atoi(holder[i]) > ft_atoi(holder[i + 1]))
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_check_multuple(char **holder)
{
	int	i;
	int	j;

	j = 1;
	i = 0;
	while (holder[i])
	{
		j = i + 1;
		while (holder[j])
		{
			if ((ft_atoi(holder[i]) == ft_atoi(holder[j])))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_arg_checker01(char *holder)
{
	int	i;

	i = 0;
	if ((holder[i] == '+' || holder[i] == '-') && holder[i + 1] == '\0')
		return (1);
	else if ((holder[i] == '+' && holder[i + 1] != '+')
		|| (holder[i] == '-' && holder[i + 1] != '-'))
		i++;
	while (holder[i])
	{
		if (holder[i] < '0' || holder[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

void	ft_arg_checker(char **holder)
{
	int		j;
	long	value;

	j = 0;
	while (holder[j])
	{
		if (ft_arg_checker01(holder[j]) == 1)
		{
			ft_free_holder(holder);
			ft_write_exit();
		}
		value = ft_atoi(holder[j]);
		if (value > INT_MAX || value < INT_MIN)
		{
			ft_free_holder(holder);
			ft_write_exit();
		}
		j++;
	}
	if (ft_check_multuple(holder) == 1)
	{
		ft_free_holder(holder);
		ft_write_exit();
	}
}

char	**ft_arg(int ac, char **av)
{
	int		i;
	char	**holder;
	char	*ptr;

	holder = 0;
	i = 1;
	ptr = ft_strdup("");
	while (i < ac)
	{
		ptr = ft_strjoin(ptr, av[i]);
		ptr = ft_strjoin(ptr, " ");
		i++;
	}
	holder = ft_split(ptr, ' ');
	if (!holder)
		ft_write_exit();
	free(ptr);
	return (holder);
}
