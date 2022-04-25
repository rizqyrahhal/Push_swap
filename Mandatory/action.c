/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarahhal <rarahhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:24:17 by rarahhal          #+#    #+#             */
/*   Updated: 2022/04/25 17:01:29 by rarahhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    print(char *str)
{
    write(1, str, ft_strlen(str));
}

void    swaping(t_stack *stack)
{
    int tmp;
    
    tmp = stack->items[stack->top];
    stack->items[stack->top] = stack->items[stack->top - 1];
    stack->items[stack->top - 1] = tmp;
}

void    sa(t_stack *stack_a)
{
    swaping(stack_a);
    print("sa\n");
}

void    sb(t_stack *stack_b)
{
    swaping(stack_b);
    print("sb\n");
}

void    ss(t_stack *stack_a, t_stack *stack_b)
{
    sa(stack_a);
    sb(stack_b);
    print("ss");
}