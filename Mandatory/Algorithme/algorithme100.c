/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithme100.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarahhal <rarahhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 10:13:30 by rarahhal          #+#    #+#             */
/*   Updated: 2022/05/23 14:11:13 by rarahhal         ###   ########.fr       */
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

void    choise_rigth_operation(t_stack *stack_a, int hold_first, int hold_second)
{
    if ((stack_a->top - hold_first) < hold_second)
        while (++hold_first <= stack_a->top)
            rotate(stack_a, 1, 'a');
    else
        while (hold_second-- >= 0)
            reverse_rotate(stack_a, 1, 'a');
}

void    chunk(t_stack *stack_a, t_stack *stack_b, int start, int end)
{
    int hold_first;
    int hold_second;
    int find;
    // int startt;
    // int endd;

    find = 1;
    // startt = (int)&start;
    // endd = (int)&end;
    // printf("start = %d\nend = %d\n", &start, &end);
    while (find)
    {
        find = 0;
        hold_first = scan_stack_from_top(stack_a, start, end);
        // printf("hold_first = %d\n", hold_first);
        if (hold_first > -1)
            find = 1;
        hold_second = scan_stack_from_battom(stack_a, start, end);
        // printf("hold_second = %d\n", hold_second);
        if (hold_second > -1)
            find = 1;
        choise_rigth_operation(stack_a, hold_first, hold_second);
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
    sorted = sort_array(stack_a->items, stack_a->top);
    while (start < max)
    {
    // printf("====***************=========*************************==============********************************=======*/********************/=====\n");
    
    // int i = 1;
    // printf("sorted[%d] = %d\n", 0, sorted[0]);
    // printf("sorted[%d] = %d\n", 1, sorted[1]);
    // while (sorted[++i])
    //     printf("sorted[%d] = %d\n", i, sorted[i]);
    // // while (sorted[++i])
    // //     printf("sorted[%d] = %d\n", i, sorted[i]);

    // printf("====***************=========*************************==============********************************=======*/********************/=====\n");
    // exit(0);
    //     printf("====in split_chunks in the lope====\n");
    //     printf("start: %d\nend: %d\n", start, end);
    //     printf("sorted[start] = %d\nsorted[end] = %d\n", sorted[start], sorted[end]);
        // printf("====================================%d\n", sorted[24]);
        chunk(stack_a, stack_b, sorted[start], sorted[end]);
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
        if (end + step - 1 > max)
        {
            // start = end + 1;
            start += step;
            end = max - 1;
        }
        else
        {
            // start = end + 1;
            start += step;
            end = start + step - 1;
        }
    }
    free(sorted);
}

void    one_hundred_numbers(t_stack *stack_a, t_stack *stack_b, int max, int step)
{
    int bigger_index;
    int *sorted;

    sorted = sort_array(stack_a->items, stack_a->top);
    // printf("====***************=========*************************==============********************************=======*/********************/=====\n");
    
    // int i = 1;
    // printf("sorted[%d] = %d\n", 0, sorted[0]);
    // printf("sorted[%d] = %d\n", 1, sorted[1]);
    // while (sorted[++i])
    //     printf("sorted[%d] = %d\n", i, sorted[i]);
    // // while (sorted[++i])
    // //     printf("sorted[%d] = %d\n", i, sorted[i]);

    // printf("====***************=========*************************==============********************************=======*/********************/=====\n");
    if (max <= step)
        chunk(stack_a, stack_b, sorted[0], sorted[max - 1]);
    else
        split_chunks(stack_a, stack_b, max, step);
    sorted = sort_array(stack_b->items, stack_b->top);
    bigger_index = 0;
    if (stack_a->items[stack_a->top] > stack_a->items[0])
        swaping(stack_a, 1, 'a');
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
	// };
    while (stack_b->top > -1)
    {
        bigger_index = get_element_index(stack_b, sorted[stack_b->top]);
        // printf("bigger_index = %d\n", bigger_index);
        // printf("stack_b->top / 2 = %d\n", (int)(stack_b->top / 2));
        // if (stack_b->top < step)
        // {
            if (bigger_index < (int)(stack_b->top / 2))
                while (bigger_index-- >= 0)
                    reverse_rotate(stack_b, 1, 'b');
            else
                while (bigger_index++ < stack_b->top)
                    rotate(stack_b, 1, 'b');
        // }
        // else
        //     while (bigger_index++ < stack_b->top)
        //             rotate(stack_b, 1, 'b');
        push_to_stack(stack_a, stack_b, 'a');
    }
    free(sorted);
}
