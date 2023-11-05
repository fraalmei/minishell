# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/25 17:18:27 by fraalmei          #+#    #+#              #
#    Updated: 2023/11/05 17:53:16 by fraalmei         ###   ########.fr        #
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
CFLAGS		= -Wall -Werror -Wextra

LEAK_FLAGS	= -fsanitize=address -g3 -pedantic

INCLUDES	= -I $(INCLUDE_DIR) $(INC1)

LIBS		= -L $(LIBFT_DIR) -lft -lreadline $(LIB1)

#------------------------------------------------------------------------------

# Directories
BIN_DIR		= bin
SRC_DIR		= srcs
SRCS		= main.c actions.c free.c $(ENV) $(BUILTINS) $(UTILS) $(EXECUTER) $(PARSE) $(SIGNALS)
ENV			= env/utils_env.c env/list_util.c env/read_env.c env/list_util2.c
UTILS		= utils/print_things.c utils/ft_split_trim.c utils/separation.c
BUILTINS	= builtins/pwd.c builtins/env.c builtins/export.c builtins/exit.c builtins/cd.c \
				builtins/unset.c builtins/echo.c
PARSE		= parse/parse_prompt_utils.c parse/parse_prompt.c parse/parse_word.c \
				parse/parse_redirects.c parse/parse_opt_args.c parse/parse_sustitution.c
EXECUTER	= executer/call_execve.c executer/child_manager.c executer/exec_utils.c executer/executer.c \
				executer/fd_utils.c executer/get_path.c executer/heredoc.c executer/open_fd.c
SIGNALS		= signals/signals.c
LIBFT_DIR	= libft		# path to libft libft
INCLUDE_DIR	= include		# path to headers


# to search the direccion of the library
# type "find / -name libreadline.a 2>/dev/null"
# if not installed in your user
# type "brew install readline"

READ1		= /System/Volumes/Data/Users/$(USER)/.brew/Cellar/readline/8.2.1
READ2		= /Users/$(USER)/.brew/opt/readline
READ3		= /System/Volumes/Data/sgoinfre/students/$(USER)/homebrew/Cellar/readline/8.2.1

LIB1		= -L $(READ1)/lib -L $(READ2)/lib -L $(READ3)/lib
INC1		= -I $(READ1)/include -I $(READ2)/include -I $(READ3)/include

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

.PHONY: $(LIBFT) all clean fclean re
