NAME= philo

CC= gcc

CFLAGS= -Wall -Wextra -Werror

SRC= main/philo.c main/utils/ft_atoi.c main/utils/ft_isdigit.c main/utils/ft_memset.c main/utils/ft_min_max.c main/utils/ft_putendl_fd.c \
	 main/utils/ft_split.c main/utils/ft_handle_arg.c main/utils/ft_check_arg.c main/utils/ft_end.c main/utils/ft_putstr_fd.c \
	 main/utils/ft_memcpy.c main/utils/ft_time.c main/utils/ft_init_shared.c main/utils/ft_free_all.c main/utils/ft_init_philo.c \
	 main/utils/ft_while_handler.c main/utils/ft_is_die.c\

INC= philo.h

OBJ= $(SRC:%.c=%.o)

MAKE = -fsanitize=address

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) -pthread -fsanitize=address $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
