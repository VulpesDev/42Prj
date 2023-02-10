/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 12:31:19 by tvasilev          #+#    #+#             */
/*   Updated: 2023/02/10 14:21:23 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	number;
	int	at_back;

	if (sorted(stack_a))
		return ;
	if (!sorted(stack_a) && stack_a->stack_ar[0] == find_num(stack_a, 1))
		ra(stack_a);
	push_a_2_b(stack_a, stack_b);
	at_back = stack_a->stacked;
	number = find_num(stack_b, 1);
	i = -1;
	while (++i < at_back)
		if (stack_a->stack_ar[0] > number)
			rra(stack_a);
	push_b_2_a(stack_a, stack_b, &at_back);
	i = -1;
	while (++i < at_back && !sorted(stack_a))
		if (stack_a->stack_ar[0] < stack_a->stack_ar[stack_a->stacked - 1]
			&& !stack_b->stacked)
			rra(stack_a);
	to_print(" ");
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;

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
		stack_a = convert_to_seq(stack_a);
		if (stack_a.stacked != 3 && stack_a.stacked > 5)
			sort(&stack_a, &stack_b);
		else
			small_sort(&stack_a, &stack_b);
	}
	return (0);
}
