NAME= philo_bonus

CC= gcc

CFLAGS= -Wall -Wextra -Werror

CFILES = philo_bonus.c ft_atoi.c ft_isdigit.c ft_putendl_fd.c \
	 ft_handle_arg.c ft_check_arg.c ft_putstr_fd.c \
	 ft_time.c ft_init_shared.c ft_free_all.c ft_init_philo.c \
	 ft_while_handler.c ft_is_die.c\

OFILES = $(addprefix $(OBJ_DIR)/,$(CFILES:.c=.o))

OBJ_DIR = ./OBJ

SRC_DIR = ./SRC

INC= philo_bonus.h

SIG = -fsanitize=address

all: $(NAME)

$(NAME) : $(OBJ_DIR) $(OFILES)
	@$(CC) -pthread $(OFILES) -o $(NAME)
	@echo "done for philo"

$(OBJ_DIR):
	@mkdir OBJ

$(OFILES): $(OBJ_DIR)/%.o : $(SRC_DIR)/%.c $(INC)
	@$(CC) -c $(CFLAGS) $< -o $@

clean :
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
