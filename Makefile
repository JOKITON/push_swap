# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaizpuru <jaizpuru@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/30 12:48:04 by jaizpuru          #+#    #+#              #
#    Updated: 2023/01/16 11:47:38 by jaizpuru         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

OBJS = $(UTILS:.c=.o)

UTILS = main.c \
	utils.c \
	utils_numbers.c \
	swap.c \
	push.c \
	rotate.c \
	reverse_rotate.c \
	sorting.c \
	sorting_utils.c \
	free.c

CC = gcc

CFLAGS = -fsanitize=address -Wall -Wextra -Werror

EXTRA_FLAGS = -g3 -fsanitize

CP = cp

CP_FLAGS = -rf

RM = rm

RM_FLAGS = -rf

all: $(NAME)

$(OBJS) : $(UTILS)
	$(CC) $(CFLAGS) -c $(UTILS)

$(NAME) : $(OBJS)
	make -C libft/ all
	$(CP) $(CP_FLAGS) libft/libft.a .
	$(CC) $(CFLAGS) $(OBJS) libft/libft.a -o $(NAME)

clean: 
	make -C libft/ clean
	$(RM) $(RM_FLAGS) $(OBJS)
	$(RM) $(RM_FLAGS) libft.a
	
fclean: clean
	make -C libft/ fclean
	$(RM) $(RM_FLAGS) $(NAME)

norminette: $(UTILS)
	norminette $(UTILS)

re : fclean all

.PHONY : all clean fclean re
