/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithme3_5.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarahhal <rarahhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 16:43:20 by rarahhal          #+#    #+#             */
/*   Updated: 2022/05/30 22:11:39 by rarahhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	three_numbers(t_stack *stack)
{
	int	top;
	int	middle;
	int	bottom;

	top = stack->items[stack->top];
	middle = stack->items[stack->top / 2];
	bottom = stack->items[0];
	if (top > middle && middle < bottom && bottom > top)
		swaping(stack, 1, 'a');
	else if (top > middle && middle > bottom)
	{
		swaping(stack, 1, 'a');
		reverse_rotate(stack, 1, 'a');
	}
	else if (top > middle && middle < bottom && top > bottom)
		rotate(stack, 1, 'a');
	else if (top < middle && middle > bottom && bottom > top)
	{
		swaping(stack, 1, 'a');
		rotate(stack, 1, 'a');
	}
	else if (top < middle && middle > bottom)
		reverse_rotate(stack, 1, 'a');
}

void	five_numbers(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	median;

	median = find_median(stack_a->items, stack_a->top);
	i = -1;
	if (stack_a->size == 4)
	{
		while (++i < stack_a->size)
		{
			if (stack_a->items[stack_a->top] < median)
				push_to_stack(stack_b, stack_a, 'b');
			reverse_rotate(stack_a, 1, 'a');
		}
	}
	else
	{
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
