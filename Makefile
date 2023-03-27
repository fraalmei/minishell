# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/25 17:18:27 by fraalmei          #+#    #+#              #
#    Updated: 2023/03/27 10:59:29 by fraalmei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##Colors #
RED		= @echo "\033[0;31m"
GREEN	= @echo "\033[0;32m"
BLUE	= @echo "\033[0;33m"
PURPLE	= @echo "\033[0;34m"
CYAN	= @echo "\033[0;35m"
RESET	= "\033[1;0m"

#	file's name
NAME	= minishell

#	compilation
CC		= gcc

#	options to force the remove
RM		= /bin/rm -f

#	flags
CFLAGS	= -Wall -Werror -Wextra

LEAK_FLAGS	= -fsanitize=address -g3

INCLUDES	= -I$(INCLUDE_DIR)

LIBS		= -L$(LIBFT_DIR) -lft -lreadline

# Directories
BIN_DIR		= bin
SRC_DIR		= srcs
SRCS		= main.c
LIBFT_DIR 	= ../libft		# path to libft libft
INCLUDE_DIR	= include		# path to headers

# Convert source files to binary
OBJS = $(SRCS:%.c=$(BIN_DIR)/%.o)

all: $(NAME)

restart: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) $(LIBS) -o $(NAME)

$(NAME): $(BIN) $(OBJS) | lib
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

#	Objects construction
$(OBJS): $(BIN_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) -g $(CFLAGS) $(INCLUDES) -c $< -o $@

#	Libraries compile
lib:
	make -C $(LIBFT_DIR)

re: fclean all

leaks: $(OBJS)
	$(CC) $(CFLAGS) $(LEAK_FLAGS) $(OBJS) $(INCLUDES) $(LIBS) -o $(NAME)

clean:
	$(RM) $(OBJS)
	make clean -C $(LIBFT_DIR)
	$(RM) -r $(BIN_DIR)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)

show:
	@printf "NAME		: $(NAME)\n"
	@printf "CC  		: $(CC)\n"
	@printf "CFLAGS		: $(CFLAGS)\n"
	@printf "SRCS		: $(SRCS)\n"
	@printf "OBJS		: $(OBJS)\n"

.PHONY: $(LIBFT) all clean fclean re
