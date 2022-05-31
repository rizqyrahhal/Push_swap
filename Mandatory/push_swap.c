/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarahhal <rarahhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 16:33:01 by rarahhal          #+#    #+#             */
/*   Updated: 2022/05/31 20:52:13 by rarahhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	logic(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size <= 3)
	{
		if (stack_a->size == 2)
			swaping(stack_a, 1, 'a');
		else
			three_numbers(stack_a);
	}
	else if (stack_a->size <= 5)
		five_numbers(stack_a, stack_b);
	else if (stack_a->size <= 100)
		one_100_numbers(stack_a, stack_b, stack_a->size, 20);
	else
		five_100_numbers(stack_a, stack_b, stack_a->size, 40);
}

void	free_stack(t_stack *stack_a, t_stack *stack_b)
{
	free(stack_a->items);
	free(stack_b->items);
	free(stack_a);
	free(stack_b);
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc == 1)
		exit (EXIT_FAILURE);
	if (!check_args(argc, argv))
		ft_error("some arguments aren't integers");
	amplement_stack(argc, argv, &stack_a, &stack_b);
	check_is_duplicate(stack_a);
	if (check_is_sorted(stack_a))
		exit(EXIT_SUCCESS);
	logic(stack_a, stack_b);
	free_stack(stack_a, stack_b);
	return (0);
}

// print element of stack
// printf("#####*******----stack_A----*******#####\n");
// int size = -1;
// int top_a = stack_a->top;
// while(++size <= stack_a->top){
// 	printf("satck_a->items[%d] = %d\n", top_a, stack_a->items[top_a]);
// 	top_a--;
// }
// printf("#####*******----stack_B----*******#####\n");
// size = -1;
// int top_b = stack_b->top;
// while (++size <= stack_b->top){
// 	printf("stack_b->items[%d] = %d\n", top_b, stack_b->items[top_b]);
// 	top_b--;
// }
