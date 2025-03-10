BLUE = \033[34m
RESET = \033[0m

NAME = push_swap

CC = cc

CFLAGS =  -Werror -Wextra -Wall

INCLUDE = includes

LIBFT_DIR =	includes/libft/
LIBFT_NAME = libft.a
LIBFT = $(LIBFT_DIR)$(LIBFT_NAME)

SRCS = utils/swap.c\
		utils/push.c\
		utils/rrotate.c\
		utils/rotate.c\
		utils/utils.c\
		utils/utils_lst.c\
		utils/array_sorter.c\
		utils/stacks.c\
		srcs/sort_numbers.c\
		srcs/utils.c\
		srcs/sort.c\
		srcs/sort_three_numbers.c\
		srcs/main.c
		
OBJ = utils/swap.o\
		utils/push.o\
		utils/rrotate.o\
		utils/rotate.o\
		utils/utils.o\
		utils/utils_lst.o\
		utils/array_sorter.o\
		utils/stacks.o\
		srcs/sort_numbers.o\
		srcs/utils.o\
		srcs/sort.o\
		srcs/sort_three_numbers.o\
		srcs/main.o

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
		$(CC) $(CFLAGS) -I$(INCLUDE) -L$(LIBFT_DIR) -o $(NAME) $(OBJ) $(LIBFT)

$(LIBFT):
	@$(MAKE) -sC $(LIBFT_DIR)
	@echo "$(BLUE)LIBFT created$(RESET)"

clean:
		rm -rf $(OBJ)
		@$(MAKE) clean -C $(LIBFT_DIR)
fclean: clean
		rm -rf $(NAME)
		rm -f $(LIBFT_DIR)$(LIBFT_NAME)
re: fclean all

.PHONY: fclean clean all re