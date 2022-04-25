/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_duplicate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarahhal <rarahhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 14:50:38 by rarahhal          #+#    #+#             */
/*   Updated: 2022/04/25 14:58:37 by rarahhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	check_is_Duplicate(t_stack *stack)
{
	int	i;
	int	j;

	i = -1;
	while(++i < stack->size - 1)
	{
		j = i;
		while(++j < stack->size)
			if (stack->items[i] == stack->items[j])
				ft_error();
	}
}
