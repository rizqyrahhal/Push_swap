/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithme3_5.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarahhal <rarahhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 16:43:20 by rarahhal          #+#    #+#             */
/*   Updated: 2022/05/22 23:06:03 by rarahhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void    three_numbers(t_stack *stack)
{
    int top;
    int middle;
    int bottom;

    top = stack->items[stack->top];
    middle = stack->items[stack->top / 2];
    bottom =stack->items[0];

    if (top > middle && middle < bottom && bottom > top)
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
    else if (top < middle && middle > bottom)
        reverse_rotate(stack, 1, 'a');
}


void    five_numbers(t_stack *stack_a, t_stack *stack_b)
{
    int i;
    int median;

    median = find_median(stack_a->items, stack_a->top);
    // printf("median: %d\n", median);
    i = -1;
    if (stack_a->size == 4)
    {
        // printf("In 44444444\n");
        while (++i < stack_a->size)
        {
            // printf("a->top: %d\n", stack_a->top);
            // printf("a->items[a->top]: %d\n", stack_a->items[stack_a->top]);
            if (stack_a->items[stack_a->top] < median)
                push_to_stack(stack_b, stack_a, 'b');
            reverse_rotate(stack_a, 1, 'a');
    //         	printf("#####*******----stack_A----*******#####\n");
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
    else
    {
        // printf("In 5555555\n");
        while (++i < stack_a->size)
        {
            if (stack_a->items[stack_a->top] <= median)
                push_to_stack(stack_b, stack_a, 'b');
            reverse_rotate(stack_a, 1, 'a');
        }   
    }
    if (stack_a->top == 1)
    {
        if (stack_a->items[1] > stack_a->items[0])
            swaping(stack_a, 1, 'a');
    }
    else
        three_numbers(stack_a);
    if (stack_b->top == 0)
        push_to_stack(stack_a, stack_b, 'a');
    else
    {
        if (stack_b->items[0] > stack_b->items[1])
            swaping(stack_b, 1, 'b');
        while (stack_b->top > -1)
            push_to_stack(stack_a, stack_b, 'a');
    }
}


// void	three_numbers(t_stack *a)
// {
// 	int	*sorted;
// 	int	bigger;
// 	int	smaller;

// 	sorted = sort_array(a->items, a->top);
// 	smaller = sorted[0];
// 	bigger = sorted[2];
// 	if (a->items[0] == bigger && a->items[1] == smaller)
// 		swaping(a, 1, 'a');
// 	else if (a->items[2] == bigger && a->items[1] == smaller)
// 		rotate(a, 1, 'a');
// 	else if (a->items[2] == bigger && a->items[0] == smaller)
// 	{
// 		swaping(a, 1, 'a');
// 		reverse_rotate(a, 1, 'a');
// 	}
// 	else if (a->items[1] == bigger && a->items[2] == smaller)
// 	{
// 		swaping(a, 1, 'a');
// 		rotate(a, 1, 'a');
// 	}
// 	else if (a->items[1] == bigger && a->items[0] == smaller)
// 		reverse_rotate(a, 1, 'a');
// 	free(sorted);
// }