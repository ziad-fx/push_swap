/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_b_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyahansa <zyahansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 12:58:13 by zyahansa          #+#    #+#             */
/*   Updated: 2025/02/03 21:19:23 by zyahansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

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
}

void	r_rotate_b(t_list **stack_b)
{
	t_list	*last;
	t_list	*ma9bel_last;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	last = *stack_b;
	while (last->next)
	{
		ma9bel_last = last;
		last = last->next;
	}
	ma9bel_last->next = NULL;
	last->next = *stack_b;
	*stack_b = last;
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
}

void	push_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*new_node;

	new_node = *stack_a;
	if (!stack_a || !(*stack_a))
		return ;
	*stack_a = (*stack_a)->next;
	new_node->next = *stack_b;
	*stack_b = new_node;
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	rotate_a(stack_a);
	rotate_b(stack_b);
}
