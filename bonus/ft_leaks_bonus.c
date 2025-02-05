/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_leaks_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyahansa <zyahansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 20:51:14 by zyahansa          #+#    #+#             */
/*   Updated: 2025/02/04 14:02:53 by zyahansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

void	ft_free_holder(char **holder)
{
	int	i;

	i = 0;
	while (holder[i])
	{
		free(holder[i]);
		*holder = NULL;
		i++;
	}
	free(holder);
	*holder = NULL;
}

void	ft_free_stack(t_list *stack_a)
{
	t_list	*tmp;

	while (stack_a)
	{
		tmp = stack_a->next;
		free(stack_a);
		stack_a = tmp;
	}
}

void	ft_do_move_helper(char **h, t_list **stack_a, t_list **stack_b, int *i)
{
	if (ft_strcmp(h[*i], "rrr") == 0)
		rrr(stack_a, stack_b);
	else
	{
		ft_free_holder(h);
		ft_write_exit_bonus();
	}
}
