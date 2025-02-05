/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting_algo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyahansa <zyahansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:29:12 by zyahansa          #+#    #+#             */
/*   Updated: 2025/02/04 13:34:17 by zyahansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_get_position(int index, t_list **stack_b, t_list **stack_a, int *b)
{
	static int	max_index = -1;

	if (max_index == -1)
		max_index = *b;
	if (ft_get_min_index(stack_b, index) > size_list(*stack_b) / 2)
	{
		if (*b < (*stack_b)->index || *b == max_index)
		{
			ft_norm2(stack_a, stack_b);
			*b = ft_update_bottom(stack_a);
		}
		else if (*stack_b)
			r_rotate_b(stack_b);
	}
	else
	{
		if (*b < (*stack_b)->index || *b == max_index)
		{
			ft_norm2(stack_a, stack_b);
			*b = ft_update_bottom(stack_a);
		}
		else if (*stack_b)
			rotate_b(stack_b);
	}
}

void	ft_sort_plus6_helper(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	int		bottom;

	tmp = ft_lstlast(*stack_a);
	bottom = tmp->index;
	while (size_list(*stack_b) > 0)
	{
		while ((*stack_b) && (*stack_a)->index - 1 != (*stack_b)->index)
			ft_get_position(((*stack_a)->index - 1), stack_b, stack_a, &bottom);
		while ((*stack_b) && (*stack_a)->index - 1 == (*stack_b)->index)
			push_a(stack_b, stack_a);
		if ((*stack_a)->index - 1 == bottom)
		{
			while (bottom == (*stack_a)->index - 1)
			{
				r_rotate_a(stack_a);
				bottom = ft_update_bottom(stack_a);
			}
		}
	}
}

void	ft_update(int *l_t, int *first_pivot, int *second_pivot, t_list **a)
{
	*l_t = *first_pivot;
	*second_pivot = (size_list(*a) / 6) + *first_pivot;
	*first_pivot += (size_list(*a) / 3);
}

void	ft_sort_plus6(t_list **stack_a, t_list **stack_b)
{
	int		l_t;
	int		firts_pivot;
	int		second_pivot;

	if (!stack_a || !*stack_a || !stack_b)
		return ;
	l_t = -1;
	firts_pivot = size_list(*stack_a) / 3;
	second_pivot = size_list(*stack_a) / 6;
	while (size_list(*stack_a) > 3)
	{
		if (size_list(*stack_b) == firts_pivot)
			ft_update(&l_t, &firts_pivot, &second_pivot, stack_a);
		if ((*stack_a)->index < firts_pivot)
		{
			push_b(stack_a, stack_b);
			if (l_t <= (*stack_b)->index && (*stack_b)->index <= second_pivot)
				rotate_b(stack_b);
		}
		else
			rotate_a(stack_a);
	}
	ft_sort_3(stack_a);
	ft_sort_plus6_helper(stack_a, stack_b);
}
