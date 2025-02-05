/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyahansa <zyahansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:07:34 by zyahansa          #+#    #+#             */
/*   Updated: 2025/02/04 14:50:45 by zyahansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	**holder;

	stack_a = NULL;
	stack_b = NULL;
	holder = NULL;
	if (ac > 1)
	{
		ft_check(ac, av);
		holder = ft_arg(ac, av);
		ft_arg_checker(holder);
		if (ft_check_is_sorted(holder) == 0)
		{
			ft_free_holder(holder);
			exit(0);
		}
		ft_fill_stack_a(&stack_a, holder);
		ft_free_holder(holder);
		ft_any_sort(&stack_a, &stack_b);
		ft_free_stack(stack_a);
	}
}
