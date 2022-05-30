/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarahhal <rarahhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 00:33:01 by rarahhal          #+#    #+#             */
/*   Updated: 2022/05/27 23:42:28 by rarahhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
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
	// printf("operation: %s\n", operation);
	return (ret);
}

void    applicate_the_operation(char *operation, t_stack *a, t_stack *b)
{
	// printf("%d\n", ft_strncmp(operation, "ssss\n", 5));
	// exit(0);
    if (ft_strcmp(operation, "sa\n"))
	{
		printf("Operation: %s\n", operation);
		printf("\n====SA====\n");
        swaping(a, 0, 'a');
	}
    else if (ft_strcmp(operation, "sb\n"))
	{
		printf("\n====Sb====\n");
        swaping(b, 0, 'b');
	}
    else if (ft_strcmp(operation, "ss\n"))
	{
		printf("\n====SS====\n");
        ss(a, b);
	}
    else if (ft_strcmp(operation, "pa\n"))
	{
		printf("\n====PA====\n");
        push_to_stack(a, b, 'a');
	}
    else if (ft_strcmp(operation, "pb\n"))
	{
		printf("\n====PB====\n");
        push_to_stack(b, a, 'b');
	}
    else if (ft_strcmp(operation, "ra\n"))
	{
		printf("\n====RA====\n");
		rotate(a, 0, 'a');
	}
    else if (ft_strcmp(operation, "rb\n"))
	{
		printf("\n====RB====\n");	
        rotate(b, 0, 'b');
	}
    else if (ft_strcmp(operation, "rr\n"))
	{
		printf("\n====RR====\n");
        rr(a, b);
	}
    else if (ft_strcmp(operation, "rra\n"))
	{
		printf("\n====RRA====\n");	
        reverse_rotate(a, 0, 'a');
	}
    else if (ft_strcmp(operation, "rrb\n"))
	{
		printf("\n====RRB====\n");
        reverse_rotate(b, 0, 'b');
	}
    else if (ft_strcmp(operation, "rrr\n"))
	{
		printf("\n====RRR====\n");
        rrr(a, b);
	}
	else {
		printf("\n====ERROR====\n");
		ft_error("This Instruction Does Not Exist\n");
	}
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
	// printf("stack_A\n");
	// size = -1;
	// // stack_a->size
	// while(++size < stack_a->size)
	// 	printf("%d\n", stack_a->items[stack_a->top--]);
	// printf("stack_B\n");
	// size = -1;
	// while (++size < 2)
	// {
	// 	printf("%d\n", stack_b->items[stack_b->top--]);
	// }

	check_stacks(stack_a, stack_b);
	return (0);
}
