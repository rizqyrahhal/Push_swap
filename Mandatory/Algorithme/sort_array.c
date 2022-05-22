/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarahhal <rarahhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 17:39:29 by rarahhal          #+#    #+#             */
/*   Updated: 2022/05/22 14:46:12 by rarahhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int *copy(int *array, int len)
{
    int *new_array;
    int i;

    new_array = malloc(sizeof(int) * (len - 1));
    i = -1;
    while (++i <= len)
        new_array[i] = array[i];
    // i = -1;
    // printf("new_array[%d] = %d\n", 74, new_array[74]);
    // while(new_array[++i])
    //     printf("new_array[%d] = %d\n", i, new_array[i]);
    return (new_array);
}

int *sort_array(int *array, int len)
{
    int i;
    int j;
    int tmp;
    int *new_array;

    new_array = copy(array, len);
    i = 0;
    while (i <= len)
    {
        j = i + 1;
        while (j <= len)
        {
            if (new_array[i] > new_array[j])
            {
                tmp = new_array[i];
                new_array[i] = new_array[j];
                new_array[j] = tmp;
            }
            j++;
        }
        i++;
    }
    return (new_array);
}