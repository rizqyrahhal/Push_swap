# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rarahhal <rarahhal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/21 17:42:08 by rarahhal          #+#    #+#              #
#    Updated: 2022/04/21 17:56:17 by rarahhal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
FLAGS = -Wall -Werror -Wextra
CC = CC

SRCS = Mandatory/push_swap.c \

LIBFT = libft/ft_atoi.c \


$(NAME):
	@$(CC) $(FLAGS) $(SRCS) $(LIBFT) -o $(NAME)

all: $(NAME)

clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)

re: fclean
	@make all


.PHONY: all clean fclean re
