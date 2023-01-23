/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 14:51:56 by tvasilev          #+#    #+#             */
/*   Updated: 2023/01/23 13:41:48 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//* BAISC STACK FUNCTIONS
void	display(t_stack stack)
{
	while (stack.stacked--)
	{
		ft_printf("%d\n", stack.stack_ar[stack.stacked]);
	}
	ft_printf("--------------\n");
}

void	push(t_stack *stack, int value)
{
	stack->stack_ar[stack->stacked++] = value;
}

void	pop(t_stack *stack)
{
	stack->stacked--;
}
