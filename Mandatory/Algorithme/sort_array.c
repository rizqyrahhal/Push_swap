/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarahhal <rarahhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 17:39:29 by rarahhal          #+#    #+#             */
/*   Updated: 2022/05/16 17:40:04 by rarahhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int *copy(int *array, int len)
{
    int *new_array;
    int i;

    new_array = malloc(sizeof(int) * (len - 1));
    i = -1;
    while (++i<= len)
        new_array[i] = array[i];
    return (new_array);
}

int *sort_array(int *array, int len)
{
    int i;
    int j;
    int tmp;
    int *new_array;

    new_array = copy(array, len);
    i = -1;
    while (++i < len)
    {
        j = i;
        while (++j < len)
        {
            if (new_array[i] > new_array[j])
            {
                tmp = new_array[i];
                new_array[i] = new_array[j];
                new_array[j] = tmp;
            }
        }
    }
    return (new_array);
}