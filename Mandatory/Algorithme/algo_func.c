/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarahhal <rarahhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 13:01:04 by rarahhal          #+#    #+#             */
/*   Updated: 2022/05/25 15:53:22 by rarahhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int scan_stack_from_battom(t_stack *stack_a, int start, int end)
{
    int battom_index;

    battom_index = -1;
    // printf("starttttttt = %d\nendddddd = %d\n", start, end);
    while (++battom_index <= stack_a->top)
        if (stack_a->items[battom_index] >= start && stack_a->items[battom_index] <= end)
            return (battom_index);
    return (-1);
}

void    chunk(t_stack *stack_a, t_stack *stack_b, int start, int end)
{
    int hold_small;
    int find;

    find = 1;
    while (find)
    {
        // printf("stack_a->top = %d\n", stack_a->top);
        // printf("start = %d\nend = %d\n", start, end);
        find = 0;
        hold_small = scan_stack_from_battom(stack_a, start, end);
        if (hold_small > -1)
            find = 1;
        // printf("hold_small = %d\n", hold_small);
        while (hold_small-- >= 0)
            reverse_rotate(stack_a, 1, 'a');
        if (find)
            push_to_stack(stack_b, stack_a, 'b');
    // printf("#####*******----stack_A----*******#####\n");
	// int size = -1;
	// int top_a = stack_a->top;
	// while(++size <= stack_a->top){
	// 	printf("satck_a->items[%d] = %d\n", top_a, stack_a->items[top_a]);
	// 	top_a--;
	// }
	// printf("#####*******----stack_B----*******#####\n");
	// size = -1;
	// int top_b = stack_b->top;
	// while (++size <= stack_b->top){
	// 	printf("stack_b->items[%d] = %d\n", top_b, stack_b->items[top_b]);
	// 	top_b--;
	// }
    }
}

void    split_chunks(t_stack *stack_a, t_stack *stack_b, int max, int step)
{
    int start;
    int end;
    int *sorted;

    start = 0;
    end = step - 1;
    while (stack_a->top > -1)
    {
        sorted = sort_array(stack_a->items, stack_a->top);
        // printf("====in split_chunks in the lope====\n");
        // printf("start: %d\nend: %d\n", start, end);
        // printf("sorted[start] = %d\nsorted[end] = %d\n", sorted[start], sorted[end]);
        chunk(stack_a, stack_b, sorted[start], sorted[end]);
        if (stack_a->top < step)
        {
            start = 0;
            end = stack_a->top;
        }
        free(sorted);
    }
    // exit(0);
}




//  37
// 25 15 4 1 23 26 37 10 19 5 20 7 30 18 11 2 32 13 33 0 34 36 21 29 22 14 16 6 28 9 38 3 27 17 31 12 24 35 8




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
