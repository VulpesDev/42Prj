/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 11:31:29 by tvasilev          #+#    #+#             */
/*   Updated: 2023/02/04 11:47:48 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	a_2_b_help(t_stacks stacks, int number, int ratio, int point)
{
	if (sorted(stacks.stack_a))
		return (1);
	if (stacks.stack_a->stack_ar[stacks.stack_a->stacked - 1]
		> stacks.stack_a->stack_ar[0]
		&& stacks.stack_a->stack_ar[stacks.stack_a->stacked - 1]
		!= number)
		get_best_move(stacks.stack_a, point);
	if (stacks.stack_a->stack_ar[stacks.stack_a->stacked - 1]
		<= point)
	{
		pb(stacks.stack_b, stacks.stack_a);
		if (stacks.stack_b->stack_ar[stacks.stack_b->stacked - 1]
			- (point - ratio)
			> (point - (point - ratio)) / 2)
			rb(stacks.stack_b);
	}
	else
		get_best_move(stacks.stack_a, point);
	return (0);
}

void	push_a_2_b(t_stack *stack_a, t_stack *stack_b)
{
	t_stacks	stacks;
	int			len;
	int			ratio;
	int			point;
	int			number;

	number = find_num(stack_a, 1);
	len = stack_a->stacked;
	ratio = number / get_magic_num(len);
	point = ratio;
	stacks.stack_a = stack_a;
	stacks.stack_b = stack_b;
	while (stack_a->stacked)
	{
		if (sorted(stack_a))
			break ;
		while (is_val_under(stack_a, point))
		{
			if (a_2_b_help(stacks, number, ratio, point))
				break ;
		}
		point += ratio;
	}
}

void	check_back(t_stack *stack_a, t_stack *stack_b, int *at_b, int *num)
{
	int	i;
	int	smalln;
	int	stack_zeroth;
	int	stack_last;

	i = -1;
	while (i++ < *at_b && !sorted(stack_a))
	{
		if (stack_b->stacked)
			smalln = find_num(stack_b, 0);
		else
			smalln = -2147483648;
		num[0] = find_num(stack_b, 1);
		if (stack_a->stacked > 0)
		{
			stack_zeroth = stack_a->stack_ar[0];
			stack_last = stack_a->stack_ar[stack_a->stacked - 1];
			if ((stack_zeroth < stack_last)
				&& ((stack_zeroth - stack_last) > (num[0] - stack_last)))
				rra(stack_a);
			if (stack_a->stack_ar[stack_a->stacked - 1] == find_num(stack_a, 0)
				&& stack_a->stack_ar[stack_a->stacked - 1] < smalln)
				ra(stack_a);
		}
	}
}

void	pba_help(t_stack *stack_a, t_stack *stack_b, int *number, int *at_back)
{
	int	big_of_two;
	int	number_i;

	number[0] = find_num(stack_b, 1);
	big_of_two = get_big_of_two(stack_a, number[0]);
	number_i = find_num_i(stack_b, 1);
	if ((big_of_two == stack_a->stack_ar[0]
			|| stack_b->stack_ar[stack_b->stacked - 1]
			> stack_a->stack_ar[0])
		&& stack_b->stack_ar[stack_b->stacked - 1] != number[0])
	{
		at_back[0] = at_back[0] + 1;
		pa(stack_a, stack_b);
		ra(stack_a);
	}
	if (stack_b->stacked > 1)
	{
		if (stack_b->stack_ar[stack_b->stacked - 2] == number[0])
			sb(stack_b);
		else if (number_i >= stack_b->stacked / 2)
			rb(stack_b);
		else
			rrb(stack_b);
	}
}

void	push_b_2_a(t_stack *stack_a, t_stack *stack_b, int *at_back)
{
	int	number;

	number = find_num(stack_b, 1);
	while (stack_b->stacked)
	{
		while (stack_b->stack_ar[stack_b->stacked - 1] < number)
			pba_help(stack_a, stack_b, &number, at_back);
		pa(stack_a, stack_b);
		check_back(stack_a, stack_b, at_back, &number);
	}
}
