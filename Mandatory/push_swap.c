/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarahhal <rarahhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 16:33:01 by rarahhal          #+#    #+#             */
/*   Updated: 2022/05/05 19:33:55 by rarahhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// char	*tack_args(int argc, char *argv[])
// {
// 	int		i;
// 	int		j;
// 	int		len;
// 	char	**dawoz;
// 	char	*stock;

// 	i = 0;
// 	len = 0;
// 	while (++i < argc)
// 	{
// 		j = 0;
// 		dawoz = ft_split(argv[i], ' ');
// 		while (dawoz[j])
// 			stock[len++] = *dawoz[j++];
// 	}
// 	while (*stock)
// 	{
// 		printf("%s\n", stock);
// 		stock++;
// 	}
// 	return (stock);
// }

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
	char	**array;
	t_stack	*stack_a;
	t_stack	*stack_b;
	int n;
	int	counter;

	if (argc == 1)
		exit (EXIT_FAILURE);
	// array = tack_args(argc, argv);
	if (!check_args(argc, argv))
		ft_error();
	stack_a = creat_stack(argc - 1);
	stack_b = creat_stack(argc - 1);
	
	if (argc == 2)
	{
		n = argc - 1;
		while (argv[n])
		{
			if (ft_strnstr(argv[n], " ", ft_strlen(argv[n])))
			{
				array = ft_split(argv[n], ' ');
				counter = 4;
				while(counter >= 0)
				{
					push(stack_a, ft_atoi(array[counter]));
					counter--;
					printf("WWWWWWWW\n");
				}
				n--;
				free_array(array);
			}
				int i = -1;
				while (array[++i])
					printf("%s\n", array[i]);
				// printf("TEST\n");
		}
		// printf("|%d|\n", n);
	}
	else {
		n = argc - 1;
		while (--n >= 0)
			push(stack_a, ft_atoi(argv[n + 1]));
	}
	/*
	n = argc - 1;
	while (--n >= 0)
	{
		// if (ft_strncmp(" ", argv[n], ft_strlen(argv[n])))
			// push(stack_a, ft_atoi(argv[n + 1]));
		if (!ft_strnstr(argv[n + 1], " ", ft_strlen(argv[n + 1])))
			push(stack_a, ft_atoi(argv[n + 1]));
		else if (ft_strnstr(argv[n + 1], " ", ft_strlen(argv[n + 1])))
		{
			array = ft_split(argv[n + 1], ' ');
			// int i = -1;
			// while (array[++i])
			// 	printf("%s\n", array[i]);
			counter = 3;
			while(counter >= 0)
			{
				push(stack_a, ft_atoi(array[counter]));
				counter--;
				// printf("WWWWWWWW\n");
			}
			free_array(array);
		// printf("TEST\n");
		}
		// printf("|%d|\n", n);
	}
	*/
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
