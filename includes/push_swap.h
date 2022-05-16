/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarahhal <rarahhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 16:33:08 by rarahhal          #+#    #+#             */
/*   Updated: 2022/05/09 17:59:32 by rarahhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
    int size;
    int top;
    int *items;
} t_stack;

// function
void	amplement_stack(int argc, char **argv, t_stack *stack_a, t_stack *stack_b);
int     check_args(int argc, char *argv[]);
int     check_is_Sorted(t_stack *stack);
void	check_is_Duplicate(t_stack *stack);
void	ft_error();

// logicale function
void	logic(t_stack *stack_a, t_stack *stack_b);
void    three_numbers(t_stack *stack);
void    five_numbers(t_stack *stack_a, t_stack *stack_b);







// stack
t_stack *creat_stack(int capacity);
void    push(t_stack *stack, int item);
int     pop(t_stack *stack);
int     is_Empty(t_stack *stack);


// action 
int     swaping(t_stack *stack, int print, char type);
void    sa(t_stack *stack_a);
void    sb(t_stack *stack_b);
void    ss(t_stack *stack_a, t_stack *stack_b);
void    push_to_stack(t_stack *receve, t_stack *send, char type);
int     rotate(t_stack *stack, int print, char type);
void    rr(t_stack *stack_a, t_stack *stack_b);
int     reverse_rotate(t_stack *stack, int print, char type);
void    rrr(t_stack *stack_a, t_stack *stack_b);







// libft
int     ft_isdigit(int c);
int     ft_atoi(char *str);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dist, const char *src, size_t dstsize);
char	**ft_split(char *s, char c);
int     ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);





#endif
