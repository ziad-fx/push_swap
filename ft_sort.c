/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyahansa <zyahansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:23:49 by zyahansa          #+#    #+#             */
/*   Updated: 2025/02/03 17:49:18 by zyahansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_any_sort(t_list **stack_a, t_list **stack_b)
{
	int	lst_size;

	lst_size = size_list(*stack_a);
	if (lst_size == 2)
		ft_sort_2(stack_a);
	else if (lst_size == 3)
		ft_sort_3(stack_a);
	else if (lst_size == 4)
		ft_sort_4(stack_a, stack_b);
	else if (lst_size == 5)
		ft_sort_5(stack_a, stack_b);
	else if (lst_size >= 6)
		ft_sort_plus6(stack_a, stack_b);
}

void	ft_sort_2(t_list **stack_a)
{
	swap(stack_a);
}

void	ft_sort_3(t_list **stack_a)
{
	int	node_1;
	int	node_2;
	int	node_3;

	node_1 = (*stack_a)->value;
	node_2 = (*stack_a)->next->value;
	node_3 = (*stack_a)->next->next->value;
	if (node_1 > node_2 && node_2 < node_3 && node_1 > node_3)
		rotate_a(stack_a);
	else if (node_1 < node_2 && node_2 > node_3 && node_1 > node_3)
		r_rotate_a(stack_a);
	else if (node_1 < node_2 && node_2 > node_3 && node_1 < node_3)
	{
		r_rotate_a(stack_a);
		swap(stack_a);
	}
	else if (node_1 > node_2 && node_2 < node_3 && node_1 < node_3)
		swap(stack_a);
	else if (node_1 > node_2 && node_2 > node_3)
	{
		rotate_a(stack_a);
		swap(stack_a);
	}
	else if (node_1 < node_2 && node_2 < node_3 && node_1 < node_3)
		return ;
}

void	ft_sort_4(t_list **stack_a, t_list **stack_b)
{
	int	size;

	ft_indexing(stack_a);
	size = ft_get_min_index(stack_a, 0);
	if (size == 0)
		ft_norm(stack_a, stack_b);
	else if (size == 1)
	{
		swap(stack_a);
		ft_norm(stack_a, stack_b);
	}
	else if (size == 2)
	{
		r_rotate_a(stack_a);
		r_rotate_a(stack_a);
		ft_norm(stack_a, stack_b);
	}
	else if (size == 3)
	{
		r_rotate_a(stack_a);
		ft_norm(stack_a, stack_b);
	}
}

void	ft_sort_5(t_list **stack_a, t_list **stack_b)
{
	int	size;
	int	min_index;
	int	push;

	push = 0;
	while (push < 2)
	{
		size = size_list(*stack_a);
		ft_indexing(stack_a);
		min_index = ft_get_min_index(stack_a, 0);
		if (min_index <= size / 2)
			while ((*stack_a)->index != 0)
				rotate_a(stack_a);
		else
			while ((*stack_a)->index != 0)
				r_rotate_a(stack_a);
		push_b(stack_a, stack_b);
		push++;
	}
	ft_sort_3(stack_a);
	push_a(stack_b, stack_a);
	push_a(stack_b, stack_a);
}
