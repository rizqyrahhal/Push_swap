/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actoin2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarahhal <rarahhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 17:51:08 by rarahhal          #+#    #+#             */
/*   Updated: 2022/05/16 17:51:50 by rarahhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int rotate(t_stack *stack, int print, char type)
{
    int tmp[stack->top];
    int len;
    int fop;
    int i;

    if(stack->top <= 0)
        return(0);
    i = -1;
    len = stack->top;
    fop = pop(stack);
    while(!is_Empty(stack))
        tmp[++i] = pop(stack);
    push(stack, fop);
    while(--len >= 0)
        push(stack, tmp[len]);
    if (print == 1)
    {
        if (type == 'a')
            printing("ra\n");
        if (type == 'b')
            printing("rb\n");
    }
    return (1);
}

void    rr(t_stack *stack_a, t_stack *stack_b)
{
    rotate(stack_a, 0, 'a');
    rotate(stack_b, 0, 'b');
    printing("rr\n");
}

int reverse_rotate(t_stack *stack, int print, char type)
{
    int tmp[stack->top];
    int len;
    int last;
    int i;

    if (stack->top <= 0)
        return (0);
    i = -1;
    len = stack->top;
    last = stack->items[0];
    while (!is_Empty(stack))
        tmp[++i] = pop(stack);
    while (len-- > 0)
        push(stack, tmp[len]);
    push(stack, last);
    if (print == 1)
    {
        if (type == 'a')
            printing("rra\n");
        if (type == 'b')
            printing("rrb\n");
    }
    return (1);
}

void    rrr(t_stack *stack_a, t_stack *stack_b)
{
    reverse_rotate(stack_a, 0, 'a');
    reverse_rotate(stack_b, 0, 'b');
    printing("rrr\n");
}
