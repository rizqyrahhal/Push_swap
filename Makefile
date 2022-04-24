# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rarahhal <rarahhal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/21 17:42:08 by rarahhal          #+#    #+#              #
#    Updated: 2022/04/24 20:57:19 by rarahhal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
FLAGS = -Wall -Werror -Wextra
CC = CC

SRCS = Mandatory/push_swap.c \
		Mandatory/stack.c \
		Mandatory/check_args.c \
		

LIBFT = libft/ft_atoi.c \
		libft/ft_isdigit.c \
		

OBJS = $(SRCS:.c=.o)
OBJS_L = $(LIBFT:.c=.o)

$(NAME): $(OBJS) $(OBJS_L)
	$(CC) $(FLAGS) $(OBJS) $(OBJS_L) -o $(NAME)

all: $(NAME)

clean:
	@rm -f Mandatory/*.o
	@rm -f libft/*.o

fclean: clean
	@rm -f $(NAME)

re: fclean
	@make all


.PHONY: all clean fclean re
