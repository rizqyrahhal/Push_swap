/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3random_numbers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarahhal <rarahhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 16:43:20 by rarahhal          #+#    #+#             */
/*   Updated: 2022/05/09 20:22:17 by rarahhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    sort_three_numbers(t_stack *stack)
{
    int top;
    int middle;
    int bottom;

    top = stack->items[stack->top];
    middle = stack->items[stack->top / 2];
    bottom =stack->items[0];
    
    if (top > middle && middle < bottom && bottom && top < bottom)
        swaping(stack, 1, 'a');
    else if (top > middle && middle > bottom)
    {
        swaping(stack, 1, 'a');
        reverse_rotate(stack, 1, 'a');
    }
    else if (top > middle && middle < bottom && top > bottom)
        rotate(stack, 1, 'a');
    else if(top < middle && middle > bottom && bottom > top)
    {
        swaping(stack, 1, 'a');
        rotate(stack, 1, 'a');
    }
    else
        reverse_rotate(stack, 1, 'a');
}

void    sort_for_numbers(t_stack *stack_a, t_stack *stack_b)
{
    push_to_stack(stack_b, stack_a, 'b');
    push_to_stack(stack_b, stack_a, 'b');
    if (!check_is_Sorted(stack_a))
        sort_three_numbers(stack_a);
    if (stack_b->items[stack_b->top] < stack_b->items[0])
        swaping(stack_b, 1, 'b');
    if (stack_a->items[stack_a->top] > stack_b->items[stack_b->top] && stack_a->items[stack_a->top] > stack_b->items[0]) // ila kano bjoj l9dam
    {
        push_to_stack(stack_a, stack_b, 'a');
        push_to_stack(stack_a, stack_b, 'a');
    }
    // top dyal B kbar man bottom dyal A wo lbatam dyal B akbsr mn top A wo sghar man top -1
    else if (stack_b->items[stack_b->top] > stack_a->items[0] && stack_b->items[0] > stack_a->items[stack_a->top] && stack_b->items[0] < stack_a->items[1])
    {
        push_to_stack(stack_a, stack_b , 'a');
        rotate(stack_a, 1, 'a');
        push_to_stack(stack_a, stack_b , 'a');
        swaping(stack_a, 1, 'a');
    }
    // top dyal B kbar man bottom dyal A wo lbatam dyal B akbsr mn top -1 dyal A wo sghar man bottam dayl A
    else if (stack_b->items[stack_b->top] > stack_a->items[0] && stack_b->items[0] > stack_a->items[stack_a->top - 1] && stack_b->items[0] < stack_a->items[0])
    {
        push_to_stack(stack_a, stack_b , 'a');
        rotate(stack_a, 1, 'a');
        rotate(stack_a, 1, 'a');
        push_to_stack(stack_a, stack_b , 'a');
        swaping(stack_a, 1, 'a');
        reverse_rotate(stack_a, 1, 'a');
    }
    else if (stack_a->items[0] < stack_b->items[stack_b->top]) // ila kano bjoj lor
    {
        swaping(stack_b, 1, 'b');
        push_to_stack(stack_a, stack_b, 'a');
        push_to_stack(stack_a, stack_b, 'a');
        rotate(stack_a, 1, 'a');
        rotate(stack_a, 1, 'a');
    }
    // ila kano mabin lowl wo tani
    else if (stack_a->items[stack_a->top] < stack_b->items[stack_b->top] && stack_a->items[stack_a->top - 1] > stack_b->items[stack_b->top])
    {
        rotate(stack_a, 1, 'a');
        push_to_stack(stack_a, stack_b, 'a');
        push_to_stack(stack_a, stack_b, 'a');
        reverse_rotate(stack_a, 1, 'a');
    }
    // ila kan top_B bin tani wo lakhar wo bottom_B bin lowl wo tani
    else if (stack_b->items[stack_b->top] < stack_a->items[0] && stack_b->items[stack_b->top] > stack_a->items[1] && stack_b->items[0] < stack_a->items[1] && stack_b->items[0] > stack_a->items[stack_a->top])
    {
        reverse_rotate(stack_a, 1, 'a');
        push_to_stack(stack_a, stack_b, 'a');
        rotate(stack_a, 1, 'a');
        rotate(stack_a, 1, 'a');
        push_to_stack(stack_a, stack_b, 'a');
        swaping(stack_a, 1, 'a');
    }
    // ila kano mabin tani wo talt
    else if (stack_b->items[stack_b->top] > stack_a->items[1] && stack_b->items[stack_b->top] < stack_a->items[0])
    {
        reverse_rotate(stack_a, 1, 'a');
        push_to_stack(stack_a, stack_b, 'a');
        push_to_stack(stack_a, stack_b, 'a');
        rotate(stack_a, 1, 'a');
        rotate(stack_a, 1, 'a');
        rotate(stack_a, 1, 'a');
    }
    // else if (stack_a->items[stack_a->top] < stack_b->items[stack_b->top] && stack_a->items[stack_a->top] < stack_b->items[0])
    // {
    //     push_to_stack(stack_a, stack_b , 'a');
    //     push_to_stack(stack_a, stack_b , 'a');
    //     rotate(stack_a, 1, 'a');
    //     rotate(stack_a, 1, 'a');
    // }
    else if (stack_a->items[stack_a->top] < stack_b->items[stack_b->top] && stack_a->items[stack_a->top] > stack_b->items[0])
    {
        push_to_stack(stack_a, stack_b , 'a');
        rotate(stack_a, 1, 'a');
        push_to_stack(stack_a, stack_b , 'a');
    }
}