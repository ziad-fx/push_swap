/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_leaks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyahansa <zyahansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 20:51:14 by zyahansa          #+#    #+#             */
/*   Updated: 2025/02/03 17:49:20 by zyahansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_holder(char **holder)
{
	int	i;

	i = 0;
	while (holder[i])
	{
		free(holder[i]);
		i++;
	}
	free(holder);
}

void	ft_free_stack(t_list *stack_a)
{
	t_list	*tmp;

	tmp = stack_a;
	while (stack_a)
	{
		tmp = stack_a;
		stack_a = stack_a->next;
		free(tmp);
	}
}
