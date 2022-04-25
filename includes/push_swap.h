/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarahhal <rarahhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 16:33:08 by rarahhal          #+#    #+#             */
/*   Updated: 2022/04/25 02:04:47 by rarahhal         ###   ########.fr       */
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
int	check_args(int argc, char *argv[]);
int	check_stack_isSorted(t_stack *stack);
void	ft_error();


// stack
t_stack *creat_stack(int capacity);
void    push(t_stack *stack, int item);
int pop(t_stack *stack);

// libft
int	ft_isdigit(int c);
int	ft_atoi(char *str);

#endif
