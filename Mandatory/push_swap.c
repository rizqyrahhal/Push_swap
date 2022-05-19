/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarahhal <rarahhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 16:33:01 by rarahhal          #+#    #+#             */
/*   Updated: 2022/05/19 14:52:09 by rarahhal         ###   ########.fr       */
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
		one_hundred_numbers(stack_a, stack_b, stack_a->size, 20);
	// else 
	// 	five_hundred_numbers(stack_a, stack_b, stack_a->size, 40);
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

int main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**array;
	int size;

	if (argc == 1)
		exit (EXIT_FAILURE);
	if (!check_args(argc, argv))
		ft_error("some arguments aren’t integers");
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
	
	
	
    return (0);
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