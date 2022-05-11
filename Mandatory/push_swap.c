/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarahhal <rarahhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 16:33:01 by rarahhal          #+#    #+#             */
/*   Updated: 2022/05/09 19:47:20 by rarahhal         ###   ########.fr       */
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
}

int	calculat_size(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
		
}

void	free_array(char **array)
{
	int	i;

	i = -1;
	while (array[++i])
		free(array[i]);
	free(array);
}

// void	amplement_stack(int argc, char **argv, t_stack *stack_a, t_stack *stack_b)
// {
// 	char	**array;
// 	int		size;

// 	if (argc == 2)
// 	{
// 		array = ft_split(argv[argc - 1], ' ');
// 		size = calculat_size(array);
// 		stack_a = creat_stack(size);
// 		stack_b = creat_stack(size);
// 		if (ft_strnstr(argv[argc - 1], " ", size))
// 		{
// 			while(--size >= 0)
// 				push(stack_a, ft_atoi(array[size]));
// 			free_array(array);
// 		}
// 	}
// 	else 
// 	{
// 		stack_a = creat_stack(argc - 1);
// 		stack_b = creat_stack(argc - 1);
// 		size = argc - 1;
// 		while (--size >= 0)
// 			push(stack_a, ft_atoi(argv[size + 1]));
// 	}
// }

int main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**array;
	int size;

	if (argc == 1)
		exit (EXIT_FAILURE);
	printf("TEST");
	if (!check_args(argc, argv))
		ft_error();
	// amplement_stack(argc, argv, stack_a, stack_b);
	if (argc == 2)
	{
		array = ft_split(argv[argc - 1], ' ');
		size = calculat_size(array);
		stack_a = creat_stack(size);
		stack_b = creat_stack(size);
		if (ft_strnstr(argv[argc - 1], " ", size))
		{
			while(--size >= 0)
				push(stack_a, ft_atoi(array[size]));
			free_array(array);
		}
	}
	else 
	{
		stack_a = creat_stack(argc - 1);
		stack_b = creat_stack(argc - 1);
		size = argc - 1;
		while (--size >= 0)
			push(stack_a, ft_atoi(argv[size + 1]));
	}
	
	check_is_Duplicate(stack_a);
	if (check_is_Sorted(stack_a))
		exit(EXIT_SUCCESS);

	// applique logic :
	logic(stack_a, stack_b);

	

	// reverse_rotate(stack_a, 1, 'a');
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
	printf("stack_A\n");
	size = -1;
	// stack_a->size
	while(++size < stack_a->size)
		printf("%d\n", stack_a->items[stack_a->top--]);
	printf("stack_B\n");
	size = -1;
	while (++size < 2)
	{
		printf("%d\n", stack_b->items[stack_b->top--]);
	}
	
	
	
    return(0);
}
