/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarahhal <rarahhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 16:33:01 by rarahhal          #+#    #+#             */
/*   Updated: 2022/04/24 23:39:59 by rarahhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_error()
{
	write(2, "Error\n", 6);
	exit (EXIT_FAILURE);
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

    return(0);
}
