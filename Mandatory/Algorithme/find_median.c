/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_median.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarahhal <rarahhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 17:41:36 by rarahhal          #+#    #+#             */
/*   Updated: 2022/05/19 13:22:41 by rarahhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int find_median(int *array, int len)
{
    int median;
    int *sorted;

    sorted = sort_array(array, len);
    // printf("len in find_median: %d\n", len);
    // int i = -1;
    // while (sorted[++i])
    //     printf("sorted[%d] = %d\n", i, sorted[i]);
    if (len == 4)
        median = sorted[1];
    else
        median = sorted[2];
    free(sorted);
    return (median);
}