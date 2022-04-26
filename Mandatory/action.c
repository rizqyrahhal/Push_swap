/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarahhal <rarahhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:24:17 by rarahhal          #+#    #+#             */
/*   Updated: 2022/04/26 18:07:22 by rarahhal         ###   ########.fr       */
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
    print("ss\n");
}

void    pa(t_stack *stack_a, t_stack *stack_b)
{
    if (!is_Empty(stack_b))
    {
        push(stack_a, stack_b->items[stack_b->top]);
        pop(stack_b);
        print("pa\n");
    }
}

void    pb(t_stack *stack_a, t_stack *stack_b)
{
    if (!is_Empty(stack_a))
    {
        push(stack_b, stack_a->items[stack_a->top]);
        pop(stack_a);
        print("pa\n");
    }
}

void    ra(t_stack *stack_a)
{
    if(is_Empty(stack_a))
       exit(EXIT_FAILURE); 
    int tmp[stack_a->top];
    int len;
    int fop;
    int i;

    i = -1;
    len = stack_a->top;
    fop = pop(stack_a);
    while(!is_Empty(stack_a))
        tmp[++i] = pop(stack_a);
    push(stack_a, fop);
    while(--len >= 0)
        push(stack_a, tmp[len]);
    print("ra\n");
}

void    rb(t_stack *stack_b)
{
    if(is_Empty(stack_b))
        exit(EXIT_FAILURE);
    int tmp[stack_b->top];
    int len;
    int fop;
    int i;

    i = -1;
    len = stack_b->top;
    fop = pop(stack_b);
    while(!is_Empty(stack_b))
        tmp[++i] = pop(stack_b);
    push(stack_b, fop);
    while(--len >= 0)
        push(stack_b, tmp[len]);
    print("rb\n");
}

void    rr(t_stack *stack_a, t_stack *stack_b)
{
    ra(stack_a);
    rb(stack_b);
    print("rr\n");   
}