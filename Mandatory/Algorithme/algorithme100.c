/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithme100.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarahhal <rarahhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 10:13:30 by rarahhal          #+#    #+#             */
/*   Updated: 2022/05/20 23:19:54 by rarahhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// int scan_stack_from_top(t_stack *stack_a, int start, int end)
// {
//     int top_index;

//     top_index = stack_a->top;
//     while (top_index > -1)
//     {
//         printf("top_index = %d\n", top_index);
//         if (stack_a->items[top_index] >= start && stack_a->items[top_index] <= end)
//         {
//             printf("start in scan_satc_from_top = %d\nend in scan_stack_from_top = %d\n", start, end);
//             printf("TEST========== stack_a->items[%d] = %d\n", top_index, stack_a->items[top_index]);
//             return (top_index);
//         }
//         top_index--;
//     }
//     return (-1);
// }

// int scan_stack_from_battom(t_stack *stack_a, int start, int end)
// {
//     int battom_index;

//     battom_index = -1;
//     while (++battom_index <= stack_a->top)
//     {
//         printf("battom_index = %d\n", battom_index);
//         if (stack_a->items[battom_index] >= start && stack_a->items[battom_index] <= end)
//         {
//             printf("start in scan_satck_from_battom = %d\nend in scan_stack_from_battom = %d\n", start, end);
//             printf("TEST========== stack_a->items[%d] = %d\n", battom_index, stack_a->items[battom_index]);    
//             return (battom_index);
//         }
//     }
//     return (-1);
// }

int scan_stack_from_top(t_stack *stack_a, int start)
{
    int top_index;

    top_index = stack_a->top;
    while (top_index > -1)
    {
        // printf("top_index = %d\n", top_index);
        if (stack_a->items[top_index] == start)
        {
            // printf("start in scan_satc_from_top = %d\n", start);
            // printf("TEST========== stack_a->items[%d] = %d\n", top_index, stack_a->items[top_index]);
            return (top_index);
        }
        top_index--;
    }
    return (-1);
}

void    choise_rigth_operation(t_stack *stack_a, int hold_first)
{
    int middel;
    
    middel = (int)(stack_a->size / 2);
    // printf("middel = %d\n", middel);
    if (hold_first > middel)
    {
        while (++hold_first <= stack_a->top)
            rotate(stack_a, 1, 'a');
    }
    else
    {
        while (--hold_first >= -1)
            reverse_rotate(stack_a, 1, 'a');
    }
}

// void    chunk(t_stack *stack_a, t_stack *stack_b, int start, int end)
// {
//     int hold_first;
//     int hold_second;
//     int find;

//     find = 1;
//     printf("start = %d\nend = %d\n", start, end);
//     while (find)
//     {
//         find = 0;
//         hold_first = scan_stack_from_top(stack_a, start, end);
//         printf("hold_first = %d\n", hold_first);
//         if (hold_first > -1)
//             find = 1;
//         hold_second = scan_stack_from_battom(stack_a, start, end);
//         printf("hold_second = %d\n", hold_second);
//         if (hold_second > -1)
//             find = 1;
//         choise_rigth_operation(stack_a, hold_first, hold_second);
//         if (find)
//             push_to_stack(stack_b, stack_a, 'b');
//     }
    
// }

void    chunk(t_stack *stack_a, t_stack *stack_b)
{
    int hold_first;
    int find;
    int *sorted;
    
    find = 1;
    while(stack_a->top > 0)
    {
        find = 0;
        sorted = sort_array(stack_a->items, stack_a->top + 1);
        // printf("sorted[0] = %d\n", sorted[0]);
        hold_first = scan_stack_from_top(stack_a, sorted[0]);
        if (hold_first > -1)
            find = 1;
        choise_rigth_operation(stack_a, hold_first);
        if (find)
            push_to_stack(stack_b, stack_a, 'b');
    }
    free(sorted);
}

void    split_chunks(t_stack *stack_a, t_stack *stack_b, int max, int step)
{
    int start;
    int end;

    start = sorted[0];
    end = sorted[step - 1];
    printf("start = %d\nend = %d\n", start, end);
    while (start < max)
    {
        chunk(stack_a, stack_b, start, end);
        if (end + step - 1 < max)
        {
            start += step;
            end = start + step - 1;
        }
        else
        {
            start += step;
            end = start + max - 1;
        }
    }    
    free(sorted);
}

void    one_hundred_numbers(t_stack *stack_a, t_stack *stack_b, int max, int step)
{
    int small_index;
    int *sorted;

    sorted = sort_array(stack_a->items, stack_a->size);
    // printf("max = %d\n", max);
    if (max < step)
       chunk(stack_a, stack_b);
    else
        split_chunks(stack_a, stack_b, max, step);
    while (stack_b->top > -1)
    {
        push_to_stack(stack_a, stack_b, 'a');
    }
}






// void    one_hundred_numbers(t_stack *stack_a, t_stack *stack_b, int max, int step)
// {
//     int bigger_index;
//     int *sorted;

//     sorted = sort_array(stack_a->items, stack_a->top);
//     // int i = -1;
//     // while (sorted[++i])
//         // printf("sorted[%d] = %d\n", i, sorted[i]);
//     if (max < step)
//         chunk(stack_a, stack_b, sorted[0], sorted[max - 1]);
//     else
//         split_chunks(stack_a, stack_b, max, step);
//     sorted = sort_array(stack_b->items, stack_b->top);
//     bigger_index = 0;
//     while (stack_b->top > - 1)
//     {
//         bigger_index = get_element_index(stack_b, sorted[stack_b->top]);
//         if (bigger_index < (int)(stack_b->top / 2))
//             while (bigger_index-- >= 0)
//                 reverse_rotate(stack_b, 1, 'b');
//         else
//             while (bigger_index++ < stack_b->top)
//                 rotate(stack_b, 1, 'b');
//         push_to_stack(stack_a, stack_b, 'a');
//     }
//     free(sorted);
// }