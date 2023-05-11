# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/25 17:18:27 by fraalmei          #+#    #+#              #
#    Updated: 2023/05/11 12:30:06 by cagonzal         ###   ########.fr        #
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
#------------------------------------------------------------------------------
CFLAGS	= -Wall -Werror -Wextra #-pedantic

LEAK_FLAGS	= -fsanitize=address -g3

INCLUDES	= -I $(INCLUDE_DIR) -I $(READ)/include

LIBS		= -L $(LIBFT_DIR) -lft -lreadline -L $(READ)/lib

#------------------------------------------------------------------------------
BUILTINS	=   ./srcs/executer/builtins/cd.c ./srcs/executer/builtins/echo.c ./srcs/executer/builtins/env.c ./srcs/executer/builtins/exit.c \
				./srcs/executer/builtins/export.c ./srcs/executer/builtins/print_env.c ./srcs/executer/builtins/pwd.c ./srcs/executer/builtins/unset.c ./srcs/executer/builtins/builtin_utils.c

EXECVE		=	./srcs/executer/execve/child_manager.c ./srcs/executer/execve/exec_utils.c ./srcs/executer/execve/executer.c \
				./srcs/executer/execve/fd_utils.c ./srcs/executer/execve/pathfinder.c
# Directories
BIN_DIR		= bin
SRC_DIR		= srcs
SRCS		= main.c signals.c parse.c free.c $(BUILTINS) $(ENV_HANDLER) $(EXECVE) #actions.c pipe.c
LIBFT_DIR	= libft			# path to libft libft
INCLUDE_DIR	= include		# path to headers

# to search the direccion of the library
# type "find / -name libreadline.a 2>/dev/null"
# if not installed in your user
# type "brew install readline"

# READ		= /System/Volumes/Data/sgoinfre/students/fraalmei/homebrew/Cellar/readline/8.2.1
READ		= /System/Volumes/Data/sgoinfre/students/cagonzal/homebrew/Cellar/readline/8.2.1

# Convert source files to binary
OBJS = $(SRCS:%.c=$(BIN_DIR)/%.o)

all: $(NAME)

restart: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) $(LIBS) -o $(NAME)

$(NAME): $(BIN) $(OBJS) | lib
	@echo "\033[0;32mCompiling minishell..."
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) $(LIBS) -o $(NAME)
	@echo "\n\033[0mDone !"

#	Objects construction
$(OBJS): $(BIN_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@printf "\033[0;33mGenerating minishell objects... %-33.33s\r" $@
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

#	Libraries compile
lib:
	@make -C $(LIBFT_DIR)

re: fclean all

leaks: $(BIN) $(OBJS) | lib
	@echo "\033[0;32mCompiling minishell with sanitizer..."
	$(CC) $(CFLAGS) $(LEAK_FLAGS) $(OBJS) $(INCLUDES) $(LIBS) -o $(NAME)
	@echo "\n\033[0mDone !"

clean:
	@echo "\nRemoving binaries..."
	@$(RM) $(OBJS)
	@echo "\033[0;31mCleaning libft..."
	@make clean -C $(LIBFT_DIR)
	@$(RM) -r $(BIN_DIR)
	@echo "\033[0m"

fclean: clean
	@echo "\033[0;31mFcleaning libft..."
	@make fclean -C $(LIBFT_DIR)
	@echo "\nDeleting executable..."
	@$(RM) $(NAME)
	@echo "\033[0m"

show:
	@printf "NAME		: $(NAME)\n"
	@printf "CC  		: $(CC)\n"
	@printf "CFLAGS		: $(CFLAGS)\n"
	@printf "SRCS		: $(SRCS)\n"
	@printf "OBJS		: $(OBJS)\n"

.PHONY: $(LIBFT) all clean fclean re
