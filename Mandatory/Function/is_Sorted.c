/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_Sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarahhal <rarahhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 02:04:26 by rarahhal          #+#    #+#             */
/*   Updated: 2022/05/19 12:00:13 by rarahhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	check_is_Sorted(t_stack *stack_a)
{
	int	i;

	i = -1;
	while(++i < stack_a->size - 1)
		if (stack_a->items[i] < stack_a->items[i + 1])
			return (0);
	return (1);
}
