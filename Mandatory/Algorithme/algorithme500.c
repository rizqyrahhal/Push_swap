/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithme500.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarahhal <rarahhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 22:35:20 by rarahhal          #+#    #+#             */
/*   Updated: 2022/05/31 13:53:20 by rarahhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	five_100_numbers(t_stack *stack_a, t_stack *stack_b,
							int max, int step)
{
	int	bigger_index;
	int	*sorted;

	sorted = sort_array(stack_a->items, stack_a->top);
	split_chunks(stack_a, stack_b, max, step);
	sorted = sort_array(stack_b->items, stack_b->top);
	bigger_index = 0;
	while (stack_b->top > -1)
	{
		bigger_index = get_element_index(stack_b, sorted[stack_b->top]);
		if (bigger_index < (int)(stack_b->top / 2))
			while (bigger_index-- >= 0)
				reverse_rotate(stack_b, 1, 'b');
		else
			while (bigger_index++ < stack_b->top)
				rotate(stack_b, 1, 'b');
		push_to_stack(stack_a, stack_b, 'a');
	}
	free(sorted);
}
