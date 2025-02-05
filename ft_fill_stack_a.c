/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_stack_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyahansa <zyahansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:07:24 by zyahansa          #+#    #+#             */
/*   Updated: 2025/02/03 18:49:24 by zyahansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_fill_stack_a(t_list **stack_a, char **holder)
{
	int		i;
	t_list	*node;

	i = 0;
	while (holder[i])
	{
		node = ft_lstnew(ft_atoi(holder[i]));
		ft_lstadd_back(stack_a, node);
		i++;
	}
	ft_indexing(stack_a);
}

void	ft_indexing(t_list **stack_a)
{
	t_list	*first_node;
	t_list	*secon_node;
	int		index;

	first_node = *stack_a;
	while (first_node)
	{
		index = 0;
		secon_node = *stack_a;
		while (secon_node)
		{
			if (secon_node->value < first_node->value)
				index++;
			secon_node = secon_node->next;
		}
		first_node->index = index;
		first_node = first_node->next;
	}
}
