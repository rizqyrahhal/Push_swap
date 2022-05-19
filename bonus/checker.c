/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarahhal <rarahhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 00:33:01 by rarahhal          #+#    #+#             */
/*   Updated: 2022/05/19 12:08:46 by rarahhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

// void	print_stacks(t_stack *a, t_stack *b)
// {
// 	int	i;

// 	i = -1;
// 	printf("\na | ");
// 	while (++i <= a->top)
// 		printf("%d ", a->items[i]);
// 	printf("\n");
// 	printf("b | ");
// 	i = -1;
// 	while (++i <= b->top)
// 		printf("%d ", b->items[i]);
// 	printf("\n\n");
// }

int	get_operation(char **operation)
{
	char	*buffer;
	int		ret;

	buffer = (char *)malloc(2);
	*operation = (char *)malloc(1);
	*operation[0] = '\0';
	ret = 1;
	while (ret)
	{
		ret = read(0, buffer, 1);
		if (ret)
		{
			if (buffer[0] == '\n' || ret == EOF)
				break ;
			*operation = ft_strjoin(*operation, &buffer[0]);
		}
	}
	free(buffer);
	return (ret);
}

void    applicate_the_operation(char *operation, t_stack *a, t_stack *b)
{
    if (ft_strncmp(operation, "sa\n", 3)){
		// printf("\nTEST\n");
        swaping(a, 0, 'a');
	}
    else if (ft_strncmp(operation, "sb\n", 3))
        swaping(b, 0, 'b');
    else if (ft_strncmp(operation, "ss\n", 3))
        ss(a, b);
    else if (ft_strncmp(operation, "pa\n", 3))
        push_to_stack(a, b, 'a');
    else if (ft_strncmp(operation, "pb\n", 3))
        push_to_stack(b, a, 'b');
    else if (ft_strncmp(operation, "ra\n", 3))
        rotate(a, 0, 'a');
    else if (ft_strncmp(operation, "rb\n", 3))
        rotate(b, 0, 'b');
    else if (ft_strncmp(operation, "rr\n", 3))
        rr(a, b);
    else if (ft_strncmp(operation, "rra\n", 4))
        reverse_rotate(a, 0, 'a');
    else if (ft_strncmp(operation, "rrb\n", 4))
        reverse_rotate(b, 0, 'b');
    else if (ft_strncmp(operation, "rrr\n", 4))
        rrr(a, b);
	else
		ft_error("This Instruction Does Not Exist\n");
	free(operation);
}

void	check_stacks(t_stack *a, t_stack *b)
{
	if (check_is_Sorted(a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int argc, char **argv)
{	
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**array;
	char	*operation;
	int		size;

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
	while (get_operation(&operation) > 0)
		applicate_the_operation(operation, stack_a, stack_b);
	if (operation[0] != '\0')
		applicate_the_operation(operation, stack_a, stack_b);
	// print_stacks(stack_a, stack_b);

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

	check_stacks(stack_a, stack_b);
	return (0);
}