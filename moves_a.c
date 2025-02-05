/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyahansa <zyahansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 11:17:38 by zyahansa          #+#    #+#             */
/*   Updated: 2025/02/03 17:49:01 by zyahansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **stack_a)
{
	t_list	*first;
	t_list	*second;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	first = *stack_a;
	second = first->next;
	first->next = second->next;
	second->next = *stack_a;
	*stack_a = second;
	write(1, "sa\n", 3);
}

void	r_rotate_a(t_list **stack_a)
{
	t_list	*last;
	t_list	*ma9bel_last;

	last = *stack_a;
	while (last->next)
	{
		ma9bel_last = last;
		last = last->next;
	}
	ma9bel_last->next = NULL;
	last->next = *stack_a;
	*stack_a = last;
	write(1, "rra\n", 4);
}

void	rotate_a(t_list **stack_a)
{
	t_list	*tmp;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	ft_lstadd_back(stack_a, tmp);
	tmp->next = NULL;
	write(1, "ra\n", 3);
}

void	push_a(t_list **stack_b, t_list **stack_a)
{
	t_list	*new_node;

	if (!stack_b || !stack_a || !*stack_b)
		exit(1);
	new_node = *stack_b;
	*stack_b = (*stack_b)->next;
	new_node->next = *stack_a;
	*stack_a = new_node;
	write(1, "pa\n", 3);
}
