/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarahhal <rarahhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 13:01:04 by rarahhal          #+#    #+#             */
/*   Updated: 2022/05/17 22:06:00 by rarahhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int scan_stack_from_top(t_stack *stack_a, int start, int end)
{
    int top_index;

    top_index = stack_a->top;
    while (top_index-- > -1)
        if (stack_a->items[top_index] >= start && stack_a->items[top_index] <= end)
            return (top_index);
    return (-1);
}

int scan_stack_from_battom(t_stack *stack_a, int start, int end)
{
    int battom_index;

    battom_index = -1;
    while (++battom_index <= stack_a->top)
        if (stack_a->items[battom_index] >= start && stack_a->items[battom_index] <= end)
            return (battom_index);
    return (-1);
}

void    choose_right_operation(t_stack *stack_a, int top_index, int battom_index)
{
    if ((stack_a->top - top_index) < battom_index){
        while (++top_index <= stack_a->top){
            rotate(stack_a, 1, 'a');
        }
        
    }
    else{
        while (battom_index-- >= 0){
            reverse_rotate(stack_a, 1, 'a');
        }
    }
}

void    chunk(t_stack *stack_a, t_stack *stack_b, int start, int end)
{
    int hold_top_index;
    int hold_battom_index;
    int find;
    
    find = 1;
    while (find)
    {
        find = 0;
        hold_top_index = scan_stack_from_top(stack_a, start, end);
        // hold_top_index = stack_a->top;
        if (hold_top_index > -1)
            find = 1;
        hold_battom_index = scan_stack_from_battom(stack_a, start, end);
        // hold_battom_index = stack_a->top - stack_a->top;
        if (hold_battom_index > -1)
            find = 1;
        choose_right_operation(stack_a, hold_top_index, hold_battom_index);
        if (find)
            push_to_stack(stack_b, stack_a, 'b');
    }
}

void    split_chunks(t_stack *stack_a, t_stack *stack_b, int max, int step)
{
    int start;
    int end;
    int *sorted;
    
    start = 0;
    end = step - 1;
    sorted = sort_array(stack_a->items, stack_a->size);
    while (start < max)
    {
        chunk(stack_a, stack_b, sorted[start], sorted[end]);
        if (end + start - 1 > max)
        {
            start += step;
            end = max - 1;
        }
        else
        {
            start += step;
            end += step - 1;
        }
    }
    free(sorted);
}
