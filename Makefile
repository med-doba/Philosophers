NAME= philo

CC= gcc

CFLAGS= -Wall -Wextra -Werror

SRC= main/philo.c main/utils/ft_atoi.c main/utils/ft_isdigit.c main/utils/ft_memset.c main/utils/ft_min_max.c main/utils/ft_putendl_fd.c \
	 main/utils/ft_split.c main/utils/ft_handle_arg.c main/utils/ft_check_arg.c main/utils/ft_end.c main/utils/ft_putstr_fd.c \
	 main/utils/ft_memcpy.c \

INC= philo.h

TEM = node/ft_alloc_node.c node/ft_node_create.c \
	 node/ft_lstsize_ps.c node/ft_lstlast_ps.c node/ft_lstdelone_ps.c \
	 node/ft_lstclear_ps.c node/ft_lstadd_front_ps.c node/ft_lstadd_back_ps.c \
	 node/ft_pop.c node/ft_push.c \

OBJ= $(SRC:%.c=%.o)

MAKE = -fsanitize=address

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(LIBFT):
	@make -C libft

$(PRINTF):
	@make -C ft_printf

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
