/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarahhal <rarahhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 16:33:01 by rarahhal          #+#    #+#             */
/*   Updated: 2022/04/21 03:03:27 by rarahhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// ft_atoi convirt string to numbre
int	ft_atoi(char *str)
{
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
	{
		sign *= -1;
		str++;
	}
	else if (*str == '+')
	{
		sign *= +1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - '0';
		str++;
	}
	return (res * sign);
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

int main(int argc, char *argv[])
{
	int *stack_a;
	int i = 0;
	int check_isdegit;
	
	stack_a = (int *)malloc((argc - 1) * sizeof(int));
	// assinge args to stak_a <<< rest le cas de 0 pour check par ce qe exite if in while >>>
	argv++;
	while (*argv)
		stack_a[i++] = ft_atoi(*argv++);
	stack_a[i] = 0;
	// while (*stack_a) {
	// 	printf("%d\n", *stack_a);
	// 	stack_a++;
	// }

	// Error <<< pour check is digit convirt stack_a to str par itoi and lope caracter par caracter whit using ft_isdegit>>>
	while (*stack_a) {
		check_isdegit = ft_isdigit(*stack_a);
		if (check_isdegit == 1)
			stack_a++;
		else if (check_isdegit == 0) {
			write(2, "Error\n", 6);
			exit (EXIT_FAILURE);
		}
	}


    return(0);
}
