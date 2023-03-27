# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/08 12:46:18 by cagonzal          #+#    #+#              #
#    Updated: 2023/03/27 12:34:59 by cagonzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Binaries variables
BIN_DIR		=	bin# Bin location
SRC_DIR		=	src# Source location

# Libraries
LIBFT_DIR	=	libft/
LIBFT_A		=	libft/libft.a
LIBFT_INC	=	libft/include
LIBS		=	-L$(LIBFT_DIR) -lft -lreadline

# Compiler options
CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror	#-g3 -fsanitize=address
INC_DIR		=	include/
INCLUDE		=	-I$(INC_DIR)
COMPILE		=	$(CC) $(FLAGS) $(INCLUDE)
NAME		=	minishell

# Colors:
NC			=	'\033[0m'
TITLE		=	'\033[38;5;33m'
DEFAULT		=	'\033[0;39m'
GRAY		=	'\033[2;37m'
RED			=	'\033[0;91m'
GREEN		=	'\033[0;32m'
YELLOW		=	'\033[0;33m'
BLUE		=	'\033[0;94m'
LRED		=	'\033[1;31m'
LGREEN		=	'\033[1;32m'
LBLUE		=	'\033[1;34m'
MAGENTA		=	'\033[0;95m'
CYAN		=	'\033[0;96m'
WHITE		=	'\033[0;97m'
CURSIVE		=	'\033[3m'

# Binaries variables
SRCS		=	main.c

OBJS		=	$(SRCS:%.c=$(BIN_DIR)/%.o)

# Makefile logic
all: $(NAME)

$(NAME): $(OBJS) | lib
	@echo ${TITLE}"\nCompiling "${YELLOW}"${NAME}	\c"${NC}
	@$(COMPILE) $(OBJS) $(LIBS) -o $(NAME)
	@echo ${LGREEN}"	[OK]\n"$(NC)

#	Objects construction
$(BIN_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(COMPILE) -c $< -o $@ $(DEBUG)

#	Libraries compile
lib:
	@make -C $(LIBFT_DIR)

# Clean logic
re: fclean all

clean:
	@echo $(CURSIVE)$(GRAY)"- Removing binary directory..." $(NC)
	@rm -rf $(BIN)

fclean: clean
	@echo $(CURSIVE)$(GRAY)"- Removing $(NAME)..." $(NC)
	@rm -rf $(NAME)
	@make fclean -C $(LIBFT_DIR)
	@echo ${CURSIVE}${GRAY}"- Project $(NAME) clean" ${NC}

.PHONY: re fclean
