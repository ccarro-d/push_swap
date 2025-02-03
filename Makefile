# Exit
NAME = push_swap

# Compilation
CC = gcc
CFLAGS = -Wall -Werror -Wextra

LIBFT_DIR = libft/
SRC_DIR = src/

# Sources
SRC = parser.c main.c operations_push.c operations_swap.c \
	  operations_rotate.c operations_revrotate.c push_swap.c \
	  push_swap_utils.c push_swap_utils_chunks.c

OBJS =	$(SRC:.c=.o)

# Linking
INCLUDE = -L ./libft -lft

$(NAME):$(OBJS)
	make -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(INCLUDE)

# Default target for compilation
all: $(NAME)

# Clean objects
clean:
	rm -f $(OBJS)
	cd $(LIBFT_DIR) && $(MAKE) clean

# Clean objects and executable
fclean: clean
	rm -f $(NAME)
	cd $(LIBFT_DIR) && $(MAKE) fclean

# Clean objects and executable and then compilation but just OBJS
re: fclean all

# Key words
.PHONY: all clean fclean re