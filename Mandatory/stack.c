/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarahhal <rarahhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 15:02:32 by rarahhal          #+#    #+#             */
/*   Updated: 2022/04/23 17:19:02 by rarahhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack *creat_stack(int capacity)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	stack->size = capacity;
	stack->top = -1;
	stack->items = (int *)malloc(sizeof(int) * stack->size);

	return(stack);
}

int	isFull(t_stack *stack)
{
	return (stack->top == stack->size - 1);
}

int	is_empty(t_stack *stack)
{
	return (stack->top == stack->size);
}

void	push(t_stack *stack, int item)
{
	if (!isFull(stack))
		stack->items[++stack->top] = item;
}

int	pop(t_stack *stack)
{
	if (!is_empty(stack))
		return (stack->items[stack->top--]);
	return (-1);
}