/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarahhal <rarahhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 00:33:01 by rarahhal          #+#    #+#             */
/*   Updated: 2022/05/19 01:19:39 by rarahhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
			*operation = ft_strjoin(*operation, buffer[0]);
		}
	}
	free(buffer);
	return (ret);
}

void    applicate_the_operation(char *operation, t_stack *a, t_stack *b)
{
    if (operation == "sa\n")
        swaping(a, 0, 'a');
    else if (operation == "sb")
        swaping(b, 0, 'b');
    else if (operation == "ss\n")
        ss(a, b);
    else if (operation == "pa\n")
        push_to_stack(a, b, 'a');
    else if (operation == "pb\n")
        push_to_stack(b, a, 'b');
    else if (operation == "ra\n")
        rotate(a, 0, 'a');
    else if (operation == "rb\n")
        rotate(b, 0, 'b');
    else if (operation == "rr\n")
        rr(a, b);
    else if (operation == "rra\n")
        reverse_rotate(a, 0, 'a');
    else if (operation == "rrb\n")
        reverse_rotate(b, 0, 'b');
    else if (operation == "rrr\n")
        rrr(a, b);
}

void	check_stacks(t_stack *a, t_stack *b)
{
	if (check_is_Sorted(a) && check_is_Sorted(b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int len, char **args)
{
	t_stack	*a;
	t_stack	*b;
	char	*operation;
	int		i;

	if (len < 2)
		return (1);
	len = len - 1;
	a = creat_stack(len - 1);
	b = creat_stack(len - 1);
	i = len;
	while (--i >= 0)
		push(&a, ft_atoi(args[i + 1]));
	if (a->size == 1)
		return (0);
	// if (duplicates_check(a.items, len))
	// 	ft_error("There Are Duplicates\n");
	while (get_operation(&operation) > 0)
		applicate_the_operation(operation, a, b);
	if (operation[0] != '\0')
		applicate_the_operation(operation, a, b);
	// print_stacks(&a, &b);
	check_stacks(a, b);
	return (0);
}