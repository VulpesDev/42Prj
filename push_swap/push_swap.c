/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 12:31:19 by tvasilev          #+#    #+#             */
/*   Updated: 2023/01/28 15:46:40 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_small(t_stack *stack)
{
	int	i;
	int	result;

	i = 0;
	result = stack->stack_ar[stack->stacked - 1];
	while (i < stack->stacked - 1)
	{
		if (stack->stack_ar[i] < result)
			result = stack->stack_ar[i];
		i++;
	}
	return (result);
}

int	find_small_i(t_stack *stack)
{
	int	i;
	int	small_i;

	i = 0;
	small_i = stack->stacked - 1;
	while (i < stack->stacked - 1)
	{
		if (stack->stack_ar[i] < stack->stack_ar[small_i])
			small_i = i;
		i++;
	}
	return (small_i);
}

int	find_big(t_stack *stack)
{
	int	i;
	int	result;

	i = 0;
	result = stack->stack_ar[stack->stacked - 1];
	while (i < stack->stacked)
	{
		if (stack->stack_ar[i] > result)
			result = stack->stack_ar[i];
		i++;
	}
	return (result);
}

int	find_big_i(t_stack *stack)
{
	int	i;
	int	big_i;

	i = 0;
	big_i = stack->stacked - 1;
	while (i < stack->stacked)
	{
		if (stack->stack_ar[i] > stack->stack_ar[big_i])
			big_i = i;
		i++;
	}
	return (big_i);
}

int	sorted(t_stack *stack)
{
	int	i;

	i = -1;
	while (++i < stack->stacked - 1)
		if (stack->stack_ar[i] < stack->stack_ar[i + 1])
			return (0);
	return (1);
}

int	find_total(t_stack *stack)
{
	int	i;

	i = -1;
	while (++i < stack->stacked)
		;
	return (i);
}

void	sort(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	big_of_two;
	int	number;
	int	number_i;
	int	smalln;
	int	at_back;
	int	len;

	number = find_big(stack_a);
	number_i = find_big_i(stack_a);
	len = find_total(stack_a);
	if (!sorted(stack_a) && stack_a->stack_ar[0] == number)
		ra(stack_a);
	while (stack_a->stacked)
	{
		//ft_printf("sorted:%d\n", sorted(stack_a));
		at_back = stack_a->stacked;
		if (sorted(stack_a))
			break ;
		if (stack_a->stack_ar[stack_a->stacked - 1] > stack_a->stack_ar[0] && stack_a->stack_ar[stack_a->stacked - 1] != number)
			if (number_i  > len / 2)
				ra(stack_a);
			else
				rra(stack_a);
		pb(stack_b, stack_a);
	}
/////* Sort from b to a
/////!when last one in stack a is the number
//!When the biggest is at the bottom of the at_back it doesnt sort
	number = find_big(stack_b);
	if (number < find_big(stack_a))
		big_of_two = find_big(stack_a);
	else
		big_of_two = number;
	if (!sorted(stack_a) && stack_a->stack_ar[0] == big_of_two)
		rra(stack_a);
	i = 0;
	while (i < at_back)
	{
		if (stack_a->stack_ar[0] > number)
			rra(stack_a);
		i++;
	}
	
	while (stack_b->stacked)
	{
		number = find_big(stack_b);
		number_i = find_big_i(stack_b);
		while (stack_b->stack_ar[stack_b->stacked - 1] < number)
		{
			if (stack_b->stack_ar[stack_b->stacked - 2] == number)
				sb(stack_b);
			else if (number_i >= stack_b->stacked / 2)
				rb(stack_b);
			else
				rrb(stack_b);
		}
		pa(stack_a, stack_b);
		i = 0;
		while (i < at_back)
		{
			if (stack_b->stacked)
				smalln = find_small(stack_b);
			else
				smalln = -2147483648;
			number = find_big(stack_b);
			//ft_printf("arr0: %d\nnumber: %d\n (stacked-1): %d\n", stack_a->stack_ar[0], number, stack_a->stack_ar[stack_a->stacked - 1]);
			if ((stack_a->stack_ar[0] < stack_a->stack_ar[stack_a->stacked - 1]
				&& stack_a->stack_ar[0] - stack_a->stack_ar[stack_a->stacked - 1] > number - stack_a->stack_ar[stack_a->stacked - 1]))
				rra(stack_a);
			// if (stack_a->stack_ar[stack_a->stacked - 1] > stack_a->stack_ar[stack_a->stacked - 2])
			// 	sa(stack_a);
			if (stack_a->stack_ar[stack_a->stacked - 1] == find_small(stack_a) && stack_a->stack_ar[stack_a->stacked - 1] < smalln)
				ra(stack_a);
			i++;
		}
	}
	i = 0;
	while (i < at_back)
	{
		if (stack_a->stack_ar[0] < stack_a->stack_ar[stack_a->stacked - 1] && !stack_b->stacked)
				rra(stack_a);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		i;
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
		sort(&stack_a, &stack_b);
	}
	return (0);
}
