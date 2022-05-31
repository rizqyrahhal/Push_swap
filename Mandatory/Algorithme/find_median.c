/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_median.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarahhal <rarahhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 17:41:36 by rarahhal          #+#    #+#             */
/*   Updated: 2022/05/31 20:30:33 by rarahhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	find_median(int *array, int len)
{
	int	median;
	int	*sorted;

	sorted = sort_array(array, len);
	if (len == 4)
		median = sorted[1];
	else
		median = sorted[0];
	free(sorted);
	return (median);
}
