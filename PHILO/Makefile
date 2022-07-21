NAME= philo

CC= gcc

CFLAGS= -Wall -Wextra -Werror

SRC= philo.c utils/ft_atoi.c utils/ft_isdigit.c utils/ft_putendl_fd.c \
	 utils/ft_handle_arg.c utils/ft_check_arg.c utils/ft_putstr_fd.c \
	 utils/ft_time.c utils/ft_init_shared.c utils/ft_free_all.c utils/ft_init_philo.c \
	 utils/ft_while_handler.c utils/ft_is_die.c\

INC= philo.h

OBJ= $(SRC:%.c=%.o)

MAKE = -fsanitize=address

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) -pthread $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
