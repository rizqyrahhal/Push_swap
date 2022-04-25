/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarahhal <rarahhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 16:33:01 by rarahhal          #+#    #+#             */
/*   Updated: 2022/04/25 03:29:01 by rarahhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	check_is_duplicate(t_stack *stack)
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

int main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int n;

	if (argc == 1)
		exit (EXIT_FAILURE);
	if (!check_args(argc, argv))
		ft_error();
	stack_a = creat_stack(argc - 1);
	stack_b = creat_stack(argc - 1);
	n = argc - 1;
	while (--n >= 0)
		push(stack_a, ft_atoi(argv[n + 1]));
	// stack_b->items[0] = 4;
	// n = check_stack_isSorted(stack_a, stack_b);
	// printf("||%d||\n", n);
	if (check_stack_isSorted(stack_a, stack_b))
		exit(EXIT_SUCCESS);
	check_is_duplicate(stack_a);
	
	// print element of stack 
	n = -1;
	while(++n <= stack_a->size)
		printf("%d\n", stack_a->items[stack_a->top--]);
	
    return(0);
}
