/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyahansa <zyahansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:18:23 by zyahansa          #+#    #+#             */
/*   Updated: 2025/02/04 12:00:08 by zyahansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_list
{
	int				value;
	int				index;
	int				max_index;
	struct s_list	*next;
}	t_list;

long	ft_atoi(const char *str);
char	**ft_split(const char *s, char c);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char	*s1, char	*s2);
size_t	ft_strlen(const char *str);
void	ft_arg_checker(char **holder);

int		ft_is_only_spaces(char *str);
void	ft_check(int ac, char **av);
int		ft_arg_checker01(char *holder);
void	ft_write_exit(void);
void	ft_fill_stack_a(t_list **stack_a, char **holder);

char	**ft_arg(int ac, char **av);

// node function

t_list	*ft_lstnew(int content);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
t_list	*ft_lstlast(t_list *lst);
int		size_list(t_list *stack_a);
void	ft_indexing(t_list **stack_a);
// void	ft_lstdelone(t_list *lst, void (*del)(void *));

//moves
void	swap(t_list **stack_a);
void	rotate_a(t_list **stack_a);
void	push_a(t_list **stack_a, t_list **stack_b);
void	push_b(t_list **stack_a, t_list **stack_b);
void	r_rotate_a(t_list **stack_a);
void	swap_b(t_list **stack_b);

///
void	r_rotate_b(t_list **stack_b);
void	rotate_b(t_list **stack_b);

//sorting alogo

int		ft_check_multuple(char **holder);

//////
void	ft_free_holder(char **holder);
void	ft_free_stack(t_list *stack_a);
//bonus
void	ft_do_moves(char **holder, t_list **stack_a, t_list **stack_b);
void	ft_read_line(t_list **stack_a, t_list **stack_b, char **holder);
int		ft_check_move(char *line);
int		ft_strcmp(const char *s1, const char *s2);
void	rrr(t_list **stack_a, t_list **stack_b);
void	ft_check_is_sorted_bonus(t_list **stack_a, t_list **stack_b);
void	ft_write_exit_bonus(void);
void	ft_do_move_helper(char **h, t_list **stack_a, t_list **stack_b, int *i);

int		ft_max_index(t_list **stack_a, int max_index);

#endif