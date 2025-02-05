/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheker.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyahansa <zyahansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 20:12:00 by zyahansa          #+#    #+#             */
/*   Updated: 2025/02/04 14:08:42 by zyahansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"
#include "../get_next_line/get_next_line.h"

void	ft_check_is_sorted_bonus(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	tmp = *stack_a;
	while (tmp && tmp->next)
	{
		if (tmp->index > tmp->next->index)
		{
			write(1, "KO\n", 3);
			exit(1);
		}
		tmp = tmp->next;
	}
	if (size_list(*stack_b) == 0)
	{
		write(1, "OK\n", 3);
		exit(0);
	}
	else
		write(1, "KO\n", 3);
}

void	ft_do_moves(char **holder, t_list **stack_a, t_list **stack_b)
{
	int	i;

	i = -1;
	while (holder[++i])
	{
		if (ft_strcmp(holder[i], "sa") == 0)
			swap(stack_a);
		else if (ft_strcmp(holder[i], "sb") == 0)
			swap(stack_b);
		else if (ft_strcmp(holder[i], "pa") == 0)
			push_a(stack_b, stack_a);
		else if (ft_strcmp(holder[i], "ra") == 0)
			rotate_a(stack_a);
		else if (ft_strcmp(holder[i], "rra") == 0)
			r_rotate_a(stack_a);
		else if (ft_strcmp(holder[i], "rb") == 0)
			rotate_b(stack_b);
		else if (ft_strcmp(holder[i], "pb") == 0)
			push_b(stack_a, stack_b);
		else if (ft_strcmp(holder[i], "rrb") == 0)
			r_rotate_b(stack_b);
		else
			ft_do_move_helper(holder, stack_a, stack_b, &i);
	}
}

void	ft_read_line(t_list **stack_a, t_list **stack_b, char **holder)
{
	char	*str;
	char	*line;

	str = ft_strdup("");
	line = get_next_line(0);
	while ((line) != NULL)
	{
		if (ft_check_move(line) == 0)
		{
			free(str);
			ft_write_exit();
		}
		str = ft_strjoin(str, line);
		free(line);
		line = get_next_line(0);
	}
	holder = ft_split(str, '\n');
	free (str);
	ft_do_moves(holder, stack_a, stack_b);
	ft_free_holder(holder);
	ft_check_is_sorted_bonus(stack_a, stack_b);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	**holder;

	stack_a = NULL;
	stack_b = NULL;
	if (ac > 1)
	{
		ft_check(ac, av);
		holder = ft_arg(ac, av);
		ft_arg_checker(holder);
		ft_fill_stack_a(&stack_a, holder);
		ft_read_line(&stack_a, &stack_b, holder);
		ft_free_holder(holder);
		ft_free_stack(stack_a);
		ft_free_stack(stack_b);
	}
}

int	ft_check_move(char *line)
{
	if ((ft_strcmp(line, "sa\n") == 0))
		return (1);
	else if ((ft_strcmp(line, "sb\n") == 0))
		return (1);
	else if ((ft_strcmp(line, "ra\n") == 0))
		return (1);
	else if ((ft_strcmp(line, "rb\n") == 0))
		return (1);
	else if ((ft_strcmp(line, "pa\n") == 0))
		return (1);
	else if ((ft_strcmp(line, "pb\n") == 0))
		return (1);
	else if ((ft_strcmp(line, "rra\n") == 0))
		return (1);
	else if ((ft_strcmp(line, "rrb\n") == 0))
		return (1);
	else if ((ft_strcmp(line, "rrr\n") == 0))
		return (1);
	return (0);
}
