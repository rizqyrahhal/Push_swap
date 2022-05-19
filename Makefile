# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rarahhal <rarahhal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/21 17:42:08 by rarahhal          #+#    #+#              #
#    Updated: 2022/05/19 01:14:14 by rarahhal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
FLAGS = -Wall -Werror -Wextra
CC = CC

SRCS = Mandatory/push_swap.c \
		Mandatory/checker.c \
		Mandatory/stack.c \
		Mandatory/Function/check_args.c \
		Mandatory/Function/ft_error.c \
		Mandatory/Function/is_Sorted.c \
		Mandatory/Function/is_duplicate.c \
		Mandatory/Operation/action.c \
		Mandatory/Operation/action2.c \
		Mandatory/Algorithme/algorithme3_5.c \
		Mandatory/Algorithme/sort_array.c \
		Mandatory/Algorithme/find_median.c \
		Mandatory/Algorithme/algorithme100.c \
		Mandatory/Algorithme/algo_func.c \
		Mandatory/Algorithme/get_element_index.c \
		Mandatory/Algorithme/algorithme500.c \

LIBFT = libft/ft_atoi.c \
		libft/ft_isdigit.c \
		libft/ft_strlen.c \
		libft/ft_strlcpy.c \
		libft/ft_split.c \
		libft/ft_strnstr.c \
		libft/ft_strjoin.c \

OBJS = $(SRCS:.c=.o)
OBJS_L = $(LIBFT:.c=.o)

$(NAME): $(OBJS) $(OBJS_L)
	$(CC) $(FLAGS) $(OBJS) $(OBJS_L) -o $(NAME)

all: $(NAME)

clean:
	@rm -f Mandatory/*.o
	@rm -f libft/*.o
	@rm -f Mandatory/Algorithme/*.o
	@rm -f Mandatory/Operation/*.o
	@rm -f Mandatory/Function/*.o

fclean: clean
	@rm -f $(NAME)

re: fclean
	@make all


.PHONY: all clean fclean re
