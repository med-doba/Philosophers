NAME= philo

CC= gcc

CFLAGS= -Wall -Wextra -Werror

SRC= main/philo.c utils/ft_atoi.c utils/ft_isdigit.c utils/ft_memset.c utils/ft_min_max.c utils/ft_putendl_fd.c \
	 utils/ft_split.c utils/ft_handle_arg.c utils/ft_check_arg.c utils/ft_end.c utils/ft_putstr_fd.c \
	 utils/ft_memcpy.c utils/ft_time.c utils/ft_init_shared.c utils/ft_free_all.c utils/ft_init_philo.c \
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
