/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   amplmentation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarahhal <rarahhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 12:47:48 by rarahhal          #+#    #+#             */
/*   Updated: 2022/06/01 12:33:44 by rarahhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	calculat_size(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	amplement_stack(int argc, char *argv[],
				t_stack **stack_a, t_stack **stack_b)
{
	char	**array;
	int		size;

	if (argc == 2)
	{
		array = ft_split(argv[argc - 1], ' ');
		size = calculat_size(array);
		*stack_a = creat_stack(size);
		*stack_b = creat_stack(size);
		while (--size >= 0)
			push(*stack_a, ft_atoi(array[size]));
		free_array(array);
	}
	else
	{
		*stack_a = creat_stack(argc - 1);
		*stack_b = creat_stack(argc - 1);
		size = argc - 1;
		while (--size >= 0)
			push(*stack_a, ft_atoi(argv[size + 1]));
	}
}
