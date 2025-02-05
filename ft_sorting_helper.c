/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting_helper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyahansa <zyahansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:32:03 by zyahansa          #+#    #+#             */
/*   Updated: 2025/02/04 13:29:40 by zyahansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_update_bottom(t_list **stack_a)
{
	t_list	*tmp;
	int		button;

	tmp = ft_lstlast(*stack_a);
	button = tmp->index;
	return (button);
}

int	ft_get_min_index(t_list **stack_a, int index)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->index == index)
			return (i);
		i++;
		tmp = tmp->next;
	}
	return (0);
}

void	ft_norm(t_list **stack_a, t_list **stack_b)
{
	push_b(stack_a, stack_b);
	ft_sort_3(stack_a);
	push_a(stack_b, stack_a);
}

void	ft_norm1(t_list **stack_a, t_list **stack_b)
{
	push_b(stack_a, stack_b);
	ft_sort_4(stack_a, stack_b);
	push_a(stack_b, stack_a);
}

void	ft_norm2(t_list **stack_a, t_list **stack_b)
{
	push_a(stack_b, stack_a);
	rotate_a(stack_a);
}
