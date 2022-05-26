/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarahhal <rarahhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 13:01:04 by rarahhal          #+#    #+#             */
/*   Updated: 2022/05/26 20:50:24 by rarahhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// int scan_stack_from_top(t_stack *stack_a, int start, int end)
// {
//     int top_index;

//     top_index = stack_a->top;
//     while (top_index-- <= -1)
//         if (stack_a->items[top_index] >= start && stack_a->items[top_index] <= end)
//             return (top_index);
//     return (-1);
// }

int scan_stack_from_battom(t_stack *stack_a, int start, int end)
{
    int battom_index;

    battom_index = -1;
    while (++battom_index <= stack_a->top)
        if (stack_a->items[battom_index] >= start && stack_a->items[battom_index] <= end)
            return (battom_index);
    return (-1);
}

// void    chunk(t_stack *stack_a, t_stack *stack_b, int start, int end)
// {
//     int hold_small;
//     int find;

//     find = 1;
//     while (find)
//     {
//         find = 0;
//         hold_small = scan_stack_from_top(stack_a, start, end);
//         if (hold_small > -1)
//             find = 1;
//         while (++hold_small < stack_a->top){
//             rotate(stack_a, 1, 'a');
//             // hold_small++;
//         }
//         if (find)
//             push_to_stack(stack_b, stack_a, 'b');
//     }
// }

void    chunk(t_stack *stack_a, t_stack *stack_b, int start, int end)
{
    int hold_small;
    int find;

    find = 1;
    while (find)
    {
        find = 0;
        hold_small = scan_stack_from_battom(stack_a, start, end);
        if (hold_small > -1)
            find = 1;
        while (hold_small-- >= 0)
            reverse_rotate(stack_a, 1, 'a');
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
    while (stack_a->top > 4)
    {
        if (stack_a->top < step)
        {
            start = 0;
            end = stack_a->top;
        }
        sorted = sort_array(stack_a->items, stack_a->top);
        chunk(stack_a, stack_b, sorted[start], sorted[end]);
        free(sorted);
    }
        // if (stack_a->top == 4)
        //     five_numbers(stack_a, stack_b);
        // else
        //     three_numbers(stack_a);
}




// void    split_chunks(t_stack *stack_a, t_stack *stack_b, int max, int step)
// {
//     int start;
//     int end;
//     int *sorted;

//     start = 0;
//     end = step - 1;
//     sorted = sort_array(stack_a->items, stack_a->top);
//     while (start < max)
//     {
//     // printf("=============sort_array==============\n");
//     // int i = 0;
//     // printf("sorted[%d] = %d\n", 0, sorted[0]);
//     // while (sorted[++i]){
//     //     printf("sorted[%d] = %d\n", i, sorted[i]);
//     // }
//     // printf("=============sort_array==============\n");
//     //     printf("====in split_chunks in the lope====\n");
//     //     printf("start: %d\nend: %d\n", start, end);
//     //     printf("sorted[start] = %d\nsorted[end] = %d\n", sorted[start], sorted[end]);
//         chunk(stack_a, stack_b, sorted[start], sorted[end]);
//         if (end + step - 1 > max)
//         {
//             start += step;
//             end = max - 1;
//         }
//         else
//         {
//             start += step;
//             end = start + step - 1;
//         }
//     // printf("#####*******----stack_A----*******#####\n");
// 	// int size = -1;
// 	// int top_a = stack_a->top;
// 	// while(++size <= stack_a->top){
// 	// 	printf("satck_a->items[%d] = %d\n", top_a, stack_a->items[top_a]);
// 	// 	top_a--;
// 	// }
// 	// printf("#####*******----stack_B----*******#####\n");
// 	// size = -1;
// 	// int top_b = stack_b->top;
// 	// while (++size <= stack_b->top){
// 	// 	printf("stack_b->items[%d] = %d\n", top_b, stack_b->items[top_b]);
// 	// 	top_b--;
// 	// }
//     }
//     // exit(0);
//     free(sorted);
// }
