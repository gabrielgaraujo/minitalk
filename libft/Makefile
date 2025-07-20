# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gaaraujo <gaaraujo@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/16 15:11:44 by gaaraujo          #+#    #+#              #
#    Updated: 2025/01/23 11:59:51 by gaaraujo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I includes -I src/ft_printf -I src/get_next_line

# Library name
NAME = libft.a

# Source directories
SRCDIR = src
MANDATORY_DIR = $(SRCDIR)/mandatory
BONUS_DIR = $(SRCDIR)/bonus
PRINTF_DIR = $(SRCDIR)/ft_printf
GNL_DIR = $(SRCDIR)/get_next_line

# Source files
MANDATORY_SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
	ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c \
	ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c \
	ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c \
	ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c \
	ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c \
	ft_substr.c ft_tolower.c ft_toupper.c

BONUS_SRCS = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c \
	ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c

# Printf source files
PRINTF_SRCS = ft_printf.c ft_printf_utils.c print_char.c print_hex.c \
	print_integer.c print_percentage.c print_pointer.c print_string.c

# Get Next Line source files
GNL_SRCS = get_next_line.c get_next_line_utils.c

# Object files
MANDATORY_OBJS = $(addprefix $(MANDATORY_DIR)/, $(MANDATORY_SRCS:.c=.o))
BONUS_OBJS = $(addprefix $(BONUS_DIR)/, $(BONUS_SRCS:.c=.o))
PRINTF_OBJS = $(addprefix $(PRINTF_DIR)/, $(PRINTF_SRCS:.c=.o))
GNL_OBJS = $(addprefix $(GNL_DIR)/, $(GNL_SRCS:.c=.o))

# All objects
ALL_OBJS = $(MANDATORY_OBJS) $(BONUS_OBJS) $(PRINTF_OBJS) $(GNL_OBJS)

# Debug flag
ifeq ($(DEBUG), 1)
	CFLAGS += -g -fsanitize=address
endif

# Default target
all: $(NAME)

# Create library with mandatory functions
$(NAME): $(MANDATORY_OBJS)
	ar rcs $(NAME) $(MANDATORY_OBJS)

# Bonus target (includes mandatory + bonus)
bonus: $(MANDATORY_OBJS) $(BONUS_OBJS)
	ar rcs $(NAME) $(MANDATORY_OBJS) $(BONUS_OBJS)

# Full target (includes everything)
full: $(ALL_OBJS)
	ar rcs $(NAME) $(ALL_OBJS)

# Printf target (includes mandatory + printf)
printf: $(MANDATORY_OBJS) $(PRINTF_OBJS)
	ar rcs $(NAME) $(MANDATORY_OBJS) $(PRINTF_OBJS)

# GNL target (includes mandatory + gnl)
gnl: $(MANDATORY_OBJS) $(GNL_OBJS)
	ar rcs $(NAME) $(MANDATORY_OBJS) $(GNL_OBJS)

# Compile object files
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Clean object files
clean:
	rm -f $(ALL_OBJS)

# Clean everything (including tests)
fclean: clean
	rm -f $(NAME) test/test_libft test/simple_test

# Rebuild everything
re: fclean all

# Create directory structure if it doesn't exist
$(MANDATORY_DIR) $(BONUS_DIR) $(PRINTF_DIR) $(GNL_DIR):
	mkdir -p $@

# Test target (compile and run)
test: full
	$(CC) $(CFLAGS) $(INCLUDES) -L. -lft test/test_libft.c -o test/test_libft
	$(CC) $(CFLAGS) $(INCLUDES) -L. -lft test/simple_test.c -o test/simple_test
	@echo "=== Running comprehensive test ==="
	./test/test_libft
	@echo "\n=== Running simple test ==="
	./test/simple_test

# Show help
help:
	@echo "Available targets:"
	@echo "  all         - Build libft with mandatory functions"
	@echo "  bonus       - Build libft with mandatory + bonus functions"
	@echo "  printf      - Build libft with mandatory + ft_printf functions"
	@echo "  gnl         - Build libft with mandatory + get_next_line functions"
	@echo "  full        - Build libft with all functions"
	@echo "  test        - Compile and run all tests"
	@echo "  clean       - Remove object files"
	@echo "  fclean      - Remove object files, library, and test binaries"
	@echo "  re          - Rebuild everything"
	@echo "  help        - Show this help message"

.PHONY: all bonus full printf gnl clean fclean re test help
