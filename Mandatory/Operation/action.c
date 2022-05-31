/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarahhal <rarahhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:24:17 by rarahhal          #+#    #+#             */
/*   Updated: 2022/05/31 13:36:12 by rarahhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	printing(char *str)
{
	write(1, str, ft_strlen(str));
}

int	swaping(t_stack *stack, int print, char type)
{
	int	tmp;

	if (stack->top <= 0)
		return (0);
	tmp = stack->items[stack->top];
	stack->items[stack->top] = stack->items[stack->top - 1];
	stack->items[stack->top - 1] = tmp;
	if (print == 1)
	{
		if (type == 'a')
			printing("sa\n");
		if (type == 'b')
			printing("sb\n");
	}
	return (1);
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	swaping(stack_a, 0, 'a');
	swaping(stack_b, 0, 'b');
	printing("ss\n");
}

void	push_to_stack(t_stack *receve, t_stack *send, char type)
{
	if (!is_empty(send))
	{
		push(receve, send->items[send->top]);
		pop(send);
		if (type == 'a')
			printing("pa\n");
		if (type == 'b')
			printing("pb\n");
	}
}
