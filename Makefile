SRCS    =	ft_arg_checker.c ft_write_exit.c push_swap.c helper.c \
			ft_fill_stack_a.c node.c  ft_split.c ft_sort.c moves_a.c\
			ft_sorting_algo.c ft_sorting_helper.c moves_b.c ft_leaks.c

BONUS   =	bonus/cheker.c bonus/ft_arg_checker_bonus.c bonus/ft_fill_stack_a_bonus.c bonus/ft_leaks_bonus.c\
			bonus/ft_split_bonus.c bonus/ft_write_exit_bonus.c bonus/helper_bonus.c bonus/moves_a_bonus.c\
			bonus/moves_b_bonus.c bonus/node_bonus.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

 
OBJS    = ${SRCS:.c=.o}
BONUS_OBJS    = ${BONUS:.c=.o}
NAME    = push_swap
NAME_BONUS    = checker
CC      = cc
RM        = rm -f
CFLAGS    = -Wall -Wextra -Werror 

$(NAME) : $(OBJS)
	cc $(OBJS) ${CFLAGS} -o $(NAME)

%.o: %.c push_swap.h
	${CC} ${CFLAGS} -c $< -o $@

all: ${NAME}

${NAME}: ${OBJS}

bonus: ${NAME_BONUS}

${NAME_BONUS} : $(BONUS_OBJS)
	cc $(BONUS_OBJS) ${CFLAGS} -o $(NAME_BONUS)

fclean: clean
	${RM} ${NAME} $(NAME_BONUS)

clean:
	${RM} ${OBJS} ${BONUS_OBJS}

re: fclean all
