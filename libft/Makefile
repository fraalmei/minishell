# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/21 13:09:37 by fraalmei          #+#    #+#              #
#    Updated: 2023/04/21 13:31:06 by fraalmei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#comments

#	part 1
MANDATORY_FUNCTIONS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
	ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
	ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
	ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
	ft_atoi.c ft_calloc.c ft_strdup.c \
	ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
	ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
	ft_putnbr_fd.c

MANDATORY_OBJS = $(MANDATORY_FUNCTIONS:.c=.o)

#	bonus part
BONUS_FUNCTIONS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
	ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
	ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

OBJS_BONUS = $(BONUS_FUNCTIONS:.c=.o)

#	functions out of libft
EXTRA_FUNCTIONS = ft_chrjoin.c ft_printf.c get_next_line.c ft_strchr_nbr.c \
	ft_intlen.c free.c

OBJS_EXTRA = $(EXTRA_FUNCTIONS:.c=.o)

#	file's name
NAME = libft.a

NAME_B = libftb.a

#	flags
FLAGS = -Wall -Werror -Wextra #-fsanitize=address

MAIN = main.c

MBONUS = main_bonus.c

#	options to create the library
AR = ar -rc

#	options to force the remove
RM = rm -f

#	compilation
CC = gcc

all: $(NAME)

bonus: $(NAME_B)

#	execute make
$(NAME):	$(MANDATORY_OBJS) $(OBJS_EXTRA)
		@$(AR) $@ $?

#	execute make with bonus
$(NAME_B):	$(MANDATORY_OBJS) $(OBJS_EXTRA) $(OBJS_BONUS)
		@$(AR) $@ $?

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@
#	@$(COMPILE.c) -c $< -o $@

clean:
	@$(RM) $(OBJS) $(MANDATORY_OBJS) $(OBJS_PART_2) $(OBJS_EXTRA) $(OBJS_BONUS)

fclean: clean
	@$(RM) $(NAME) $(NAME_B) a.out bonus

re: fclean all

reb: fclean bonus

.PHONY: all bonus clean fclean re bonus

main:
	$(CC) $(FLAGS) $(MANDATORY_FUNCTIONS) $(EXTRA_FUNCTIONS) $(MAIN)
		&& ./a.out

mbonus:
	$(CC) $(FLAGS) $(MANDATORY_FUNCTIONS) $(BONUS_FUNCTIONS) $(EXTRA_FUNCTIONS) $(MBONUS)
