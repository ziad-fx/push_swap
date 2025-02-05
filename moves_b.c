/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyahansa <zyahansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 18:42:52 by zyahansa          #+#    #+#             */
/*   Updated: 2025/02/01 20:56:14 by zyahansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_b(t_list **stack_b)
{
	t_list	*first;
	t_list	*second;

	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	first = *stack_b;
	second = first->next;
	first->next = second->next;
	second->next = *stack_b;
	*stack_b = second;
	write(1, "sb\n", 3);
}

void	r_rotate_b(t_list **stack_b)
{
	t_list	*last;
	t_list	*ma9bel_last;

	last = *stack_b;
	while (last->next)
	{
		ma9bel_last = last;
		last = last->next;
	}
	ma9bel_last->next = NULL;
	last->next = *stack_b;
	*stack_b = last;
	write(1, "rrb\n", 4);
}

void	rotate_b(t_list **stack_b)
{
	t_list	*tmp;

	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	ft_lstadd_back(stack_b, tmp);
	tmp->next = NULL;
	write(1, "rb\n", 3);
}

void	push_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*new_node;

	new_node = *stack_a;
	if (!stack_a || !*stack_a)
		ft_write_exit();
	*stack_a = (*stack_a)->next;
	new_node->next = *stack_b;
	*stack_b = new_node;
	write(1, "pb\n", 3);
}
