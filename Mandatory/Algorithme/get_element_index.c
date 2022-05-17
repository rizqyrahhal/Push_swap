/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_element_index.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarahhal <rarahhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 13:04:15 by rarahhal          #+#    #+#             */
/*   Updated: 2022/05/17 13:04:21 by rarahhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int get_element_index(t_stack *stack, int el)
{
    int i;

    i = -1;
    while (++i < stack->size)
        if (stack->items[i] == el)
            return (i);
    return (0);
}
