/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarahhal <rarahhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 16:33:01 by rarahhal          #+#    #+#             */
/*   Updated: 2022/04/26 23:08:25 by rarahhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
	check_is_Duplicate(stack_a);
	if (check_is_Sorted(stack_a))
		exit(EXIT_SUCCESS);

	
	


	// swaping(stack_b, 1, 'b');
	// ss(stack_a, stack_b);
	// pb(stack_a, stack_b);
	// pa(stack_a, stack_b);
	// push_to_stack(stack_b, stack_a, 'b');
	// push_to_stack(stack_b, stack_a, 'b');
	// push_to_stack(stack_a, stack_b, 'a');
	// push_to_stack(stack_a, stack_b, 'a');
	// rotate(stack_b, 1, 'b');
	// ra(stack_a);
	// rb(stack_b);
	// rr(stack_a, stack_b); 
	// reverse_rotate(stack_b, 1, 'b');
	// reverse_rotate(stack_a, 1, 'a');
	// rrr(stack_a, stack_b);
	

	
	// print element of stack  /*le cas de "1 2 3" splete and assing*/
	n = -1;
	while(++n < stack_a->size)
		printf("%d\n", stack_a->items[stack_a->top--]);
	
    return(0);
}
