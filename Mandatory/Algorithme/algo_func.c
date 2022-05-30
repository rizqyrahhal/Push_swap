/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarahhal <rarahhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 13:01:04 by rarahhal          #+#    #+#             */
/*   Updated: 2022/05/30 20:52:59 by rarahhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	scan_stack_from_battom(t_stack *stack_a, int start, int end)
{
	int	battom_index;

	battom_index = -1;
	while (++battom_index <= stack_a->top)
		if (stack_a->items[battom_index] >= start
			&& stack_a->items[battom_index] <= end)
			return (battom_index);
	return (-1);
}

void	chunk(t_stack *stack_a, t_stack *stack_b, int start, int end)
{
	int	hold_small;
	int	find;

	find = 1;
	while (find)
	{
		find = 0;
		hold_small = scan_stack_from_battom(stack_a, start, end);
		if (hold_small > -1)
			find = 1;
		while (hold_small-- > -1)
			reverse_rotate(stack_a, 1, 'a');
		if (find)
			push_to_stack(stack_b, stack_a, 'b');
	}
}

void	split_chunks(t_stack *stack_a, t_stack *stack_b, int max, int step)
{
	int	start;
	int	end;
	int	*sorted;

	start = 0;
	end = step - 1;
	while (stack_a->top > -1)
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
}
