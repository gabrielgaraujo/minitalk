# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gaaraujo <gaaraujo@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/20 11:17:44 by gaaraujo          #+#    #+#              #
#    Updated: 2025/07/20 11:17:52 by gaaraujo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Project names
SERVER = server
CLIENT = client

# Source files
SERVER_SRC = server.c
CLIENT_SRC = client.c

# Object files
SERVER_OBJ = $(SERVER_SRC:.c=.o)
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)

# Libft
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

# Header
HEADER = minitalk.h

# Default target
all: $(LIBFT) $(SERVER) $(CLIENT)

# Compile libft
$(LIBFT):
	@make -C $(LIBFT_DIR) printf

# Server compilation
$(SERVER): $(SERVER_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(SERVER_OBJ) -L$(LIBFT_DIR) -lft -o $(SERVER)

# Client compilation  
$(CLIENT): $(CLIENT_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(CLIENT_OBJ) -L$(LIBFT_DIR) -lft -o $(CLIENT)

# Object file compilation
%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -I$(LIBFT_DIR)/includes -c $< -o $@

# Clean object files
clean:
	rm -f $(SERVER_OBJ) $(CLIENT_OBJ)
	@make -C $(LIBFT_DIR) clean

# Clean everything
fclean: clean
	rm -f $(SERVER) $(CLIENT)
	@make -C $(LIBFT_DIR) fclean

# Rebuild everything
re: fclean all

# Phony targets
.PHONY: all clean fclean re
