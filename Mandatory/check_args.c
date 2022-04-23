/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarahhal <rarahhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 15:56:00 by rarahhal          #+#    #+#             */
/*   Updated: 2022/04/23 15:56:26 by rarahhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_args(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 0;
	while(++i < argc)
	{
		j = 0;
		while(argv[i][j])
		{
			if (argv[i][j] == '+' || argv[i][j] == '-')
				j++;
			if (!ft_isdigit(argv[i][j]))
				return (0);
			j++;
		}
	}
	return (1);
}
