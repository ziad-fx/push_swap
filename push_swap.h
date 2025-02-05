/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyahansa <zyahansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:34:29 by zyahansa          #+#    #+#             */
/*   Updated: 2025/02/04 13:35:00 by zyahansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

//#define malloc(x) 0

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
int		ft_check_is_sorted(char **holder);

char	**ft_arg(int ac, char **av);

// node function

t_list	*ft_lstnew(int content);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
t_list	*ft_lstlast(t_list *lst);
int		size_list(t_list *stack_a);
void	ft_indexing(t_list **stack_a);
// void	ft_lstdelone(t_list *lst, void (*del)(void *));

// sort function
void	ft_sort_2(t_list **stack_a);
void	ft_sort_3(t_list **stack_a);
void	ft_sort_4(t_list **stack_a, t_list **stack_b);
void	ft_sort_5(t_list **stack_a, t_list **stack_b);
void	ft_sort_plus6(t_list **stack_a, t_list **stack_b);

void	ft_any_sort(t_list **stack_a, t_list **stack_b);
void	ft_sort_plus6_helper(t_list **stack_a, t_list **stack_b);
void	ft_get_position(int index, t_list **stack_b, t_list **stack_a, int *b);
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

void	ft_move_index_top(t_list **stack_a, t_list **stack_b);
int		ft_get_min_index(t_list **stack_a, int index);
void	ft_norm(t_list **stack_a, t_list **stack_b);
void	ft_norm1(t_list **stack_a, t_list **stack_b);
void	ft_norm2(t_list **stack_a, t_list **stack_b);

int		ft_check_multuple(char **holder);
int		ft_update_bottom(t_list **stack_a);
void	ft_update(int *l_t, int *first_pivot, int *second_pivot, t_list **a);

/////
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