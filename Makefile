# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rarahhal <rarahhal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/21 17:42:08 by rarahhal          #+#    #+#              #
#    Updated: 2022/05/21 21:28:56 by rarahhal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_BONUS = checker
FLAGS = -Wall -Werror -Wextra
CC = CC

SRCS = Mandatory/push_swap.c \
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
		Mandatory/Algorithme/get_element_index.c \
		# Mandatory/Algorithme/algo_func.c \
		Mandatory/Algorithme/algorithme500.c \

BONUS_SRCS = bonus/checker.c \
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
		libft/ft_strncmp.c \

OBJS = $(SRCS:.c=.o)
OBJS_L = $(LIBFT:.c=.o)
OBJS_B = $(BONUS_SRCS:.c=.o)

$(NAME): $(OBJS) $(OBJS_L)
	$(CC) $(FLAGS) $(OBJS) $(OBJS_L) -o $(NAME)

$(NAME_BONUS): $(OBJS_B) $(OBJS_L)
	$(CC) $(FLAGS) $(OBJS_B) $(OBJS_L) -o $(NAME_BONUS)


all: $(NAME)

bonus: $(NAME_BONUS)

clean:
	@rm -f bonus/*.o
	@rm -f Mandatory/*.o
	@rm -f libft/*.o
	@rm -f Mandatory/Algorithme/*.o
	@rm -f Mandatory/Operation/*.o
	@rm -f Mandatory/Function/*.o

fclean: clean
	@rm -f $(NAME)
	@rm -f $(NAME_BONUS)

re: fclean
	@make all


.PHONY: all clean fclean re
