/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 12:31:19 by tvasilev          #+#    #+#             */
/*   Updated: 2023/01/22 15:22:53 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s(t_stack *stack)
{
	int	temp;

	if (stack->stacked <= 1)
		return ;
	temp = stack->stack_ar[stack->stacked - 1];
	stack->stack_ar[stack->stacked - 1] = stack->stack_ar[stack->stacked - 2];
	stack->stack_ar[stack->stacked - 2] = temp;
}

void	p(t_stack *stack, t_stack *stack_receive)
{
	push(stack_receive, stack->stack_ar[stack->stacked - 1]);
	pop(stack);
}

int	main(int argc, char **argv)
{
	int	i;
	t_stack	stack_a;
	t_stack	stack_b;

	i = 0;
	stack_a.stacked = 0;
	stack_b.stacked = 0;
	if (!handle_errors(argc, argv))
		return (0);
	else
	{
		while (--argc >= 1)
		{
			push(&stack_a, ft_atoi(argv[argc]));
		}
		
	}
	return (0);
}
