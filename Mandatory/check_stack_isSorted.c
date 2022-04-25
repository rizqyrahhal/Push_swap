/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stack_isSorted.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarahhal <rarahhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 02:04:26 by rarahhal          #+#    #+#             */
/*   Updated: 2022/04/25 02:04:52 by rarahhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_stack_isSorted(t_stack *stack)
{
	int	i;
	
	i = 0;
	while(++i < stack->size)
		if (stack->items[i - 1] < stack->items[i])
			return (0);
	return (1);
}
