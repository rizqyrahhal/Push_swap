/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarahhal <rarahhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:24:17 by rarahhal          #+#    #+#             */
/*   Updated: 2022/05/16 17:51:38 by rarahhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void    printing(char *str)
{
    write(1, str, ft_strlen(str));
}

int swaping(t_stack *stack, int print, char type)
{
    if (stack->top <= 0)
        return (0);
    int tmp;

    tmp = stack->items[stack->top];
    stack->items[stack->top] = stack->items[stack->top - 1];
    stack->items[stack->top - 1] = tmp;
    if(print == 1)
    {
        if (type == 'a')
            printing("sa\n");
        if (type == 'b')
            printing("sb\n");
    }
    return (1);
}

void    ss(t_stack *stack_a, t_stack *stack_b)
{
    swaping(stack_a, 0, 'a');
    swaping(stack_b, 0, 'b');
    printing("ss\n");
}

void    push_to_stack(t_stack *receve, t_stack *send, char type)
{
        if (!is_Empty(send))
    {
        push(receve, send->items[send->top]);
        pop(send);
        if (type == 'a')
            printing("pa\n");
        if (type == 'b')
            printing("pb\n");
    }
}











// push A function detai
// void    pa(t_stack *stack_a, t_stack *stack_b)
// {
//     if (!is_Empty(stack_b))
//     {
//         push(stack_a, stack_b->items[stack_b->top]);
//         pop(stack_b);
//         printing("pa\n");
//     }
// }

// push B function detai
// void    pb(t_stack *stack_a, t_stack *stack_b)
// {
//     if (!is_Empty(stack_a))
//     {
//         push(stack_b, stack_a->items[stack_a->top]);
//         pop(stack_a);
//         printing("pa\n");
//     }
// }




// rotate A function detai
// void    ra(t_stack *stack_a)
// {
//     if(is_Empty(stack_a))
//        exit(EXIT_FAILURE);
//     int tmp[stack_a->top];
//     int len;
//     int fop;
//     int i;

//     i = -1;
//     len = stack_a->top;
//     fop = pop(stack_a);
//     while(!is_Empty(stack_a))
//         tmp[++i] = pop(stack_a);
//     push(stack_a, fop);
//     while(--len >= 0)
//         push(stack_a, tmp[len]);
//     printf("ra\n");
// }

// rotate B function detai
// void    rb(t_stack *stack_b)
// {
//     if(is_Empty(stack_b))
//         exit(EXIT_FAILURE);
//     int tmp[stack_b->top];
//     int len;
//     int fop;
//     int i;

//     i = -1;
//     len = stack_b->top;
//     fop = pop(stack_b);
//     while(!is_Empty(stack_b))
//         tmp[++i] = pop(stack_b);
//     push(stack_b, fop);
//     while(--len >= 0)
//         push(stack_b, tmp[len]);
//     printf("rb\n");
// }

