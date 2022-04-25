/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_Sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarahhal <rarahhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 02:04:26 by rarahhal          #+#    #+#             */
/*   Updated: 2022/04/25 03:28:02 by rarahhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_stack_isSorted(t_stack *stack, t_stack *stack_b)
{
	int	i;
	
	// if (is_Empty(stack_b))
	// {
	// 	printf("stack B not empty\n");
	// 	return (0);
	// }
	i = 0;
	while(++i < stack->size)
		if (stack->items[i - 1] < stack->items[i])
			return (0);
	return (1);
}
