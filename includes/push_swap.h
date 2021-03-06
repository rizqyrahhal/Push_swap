/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarahhal <rarahhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 16:33:08 by rarahhal          #+#    #+#             */
/*   Updated: 2022/06/01 12:34:09 by rarahhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	int	size;
	int	top;
	int	*items;
}	t_stack;

// stack
t_stack	*creat_stack(int capacity);
void	push(t_stack *stack, int item);
int		pop(t_stack *stack);
int		is_empty(t_stack *stack);

// function
void	amplement_stack(int argc, char *argv[],
			t_stack **stack_a, t_stack **stack_b);
int		check_args(int argc, char *argv[]);
int		check_is_sorted(t_stack *stack_a);
void	check_is_duplicate(t_stack *stack);
void	ft_error(char *str);
void	free_array(char **array);
int		calculat_size(char **str);

// Algorithme function
void	logic(t_stack *stack_a, t_stack *stack_b);
void	three_numbers(t_stack *stack);
void	five_numbers(t_stack *stack_a, t_stack *stack_b);
int		*sort_array(int *array, int len);
int		find_median(int *array, int len);
void	one_100_numbers(t_stack *stack_a, t_stack *stack_b, int max, int step);
void	chunk(t_stack *stack_a, t_stack *stack_b, int start, int end);
int		get_element_index(t_stack *stack, int el);
void	split_chunks(t_stack *stack_a, t_stack *stack_b, int max, int step);
void	five_100_numbers(t_stack *stack_a, t_stack *stack_b, int max, int step);

// action 
void	printing(char *str);
int		swaping(t_stack *stack, int print, char type);
void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	push_to_stack(t_stack *receve, t_stack *send, char type);
int		rotate(t_stack *stack, int print, char type);
void	rr(t_stack *stack_a, t_stack *stack_b);
int		reverse_rotate(t_stack *stack, int print, char type);
void	rrr(t_stack *stack_a, t_stack *stack_b);

// libft
int		ft_isdigit(int c);
int		ft_atoi(char *str);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dist, const char *src, size_t dstsize);
char	**ft_split(char *s, char c);

#endif