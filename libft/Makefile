# Exit
NAME = libft.a

# Compilation
CC = gcc
CFLAGS = -Wall -Werror -Wextra

# Sources
SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
	  ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c \
	  ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
	  ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c \
	  ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
	  ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c \
	  ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
	  ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
	  ft_putendl_fd.c ft_putnbr_fd.c

OBJS =	$(SRC:.c=.o)

BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c \
		ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c \
		ft_lstmap_bonus.c

BONUS_OBJS = $(BONUS:.c=.o)

# Linking
INCLUDE = libft.h

$(NAME):$(OBJS)	$(INCLUDE)
	ar -rsc	$(NAME)	$(OBJS)

# Default target for compilation
all: $(NAME)

# Generate .o from respective .c
%.o : %.c
	@$(CC) $(CFLAGS) -c -o $@ $<

# Clean objects
clean:
	rm -f $(OBJS) $(BONUS_OBJS)

# Clean objects and executable
fclean: clean
	rm -f $(NAME)

# Clean objects and executable and then compilation but just OBJS
re: fclean all

# Bonus > For testers use: ar -rsc	$(NAME) $(BONUS_OBJS)
bonus: $(BONUS_OBJS)
	@make OBJS="$(OBJS) $(BONUS_OBJS)"

# Clean objects and executable and then compilation (OBJS + BONUS_OBJS)
rebonus: fclean bonus

# Key words
.PHONY: all clean fclean re