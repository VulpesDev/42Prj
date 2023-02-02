/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 12:31:19 by tvasilev          #+#    #+#             */
/*   Updated: 2023/02/02 18:12:06 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_magic_num(int len)
{
	if (len < 60)
		return (2);
	else if (len < 250)
		return (4);
	else
		return (8);
}

int	get_big_of_two(t_stack *stack, int number)
{
	if (number < find_num(stack, 1))
		return (find_num(stack, 1));
	else
		return (number);
}

void	choose_best_move(t_stack *stack, int point)
{
	if (find_small_point(stack, point))
		ra(stack);
	else
		rra(stack);
}

int	a_2_b_help(t_stacks stacks, int number, int ratio, int point)
{
	if (sorted(stacks.stack_a))
		return (1);
	if (stacks.stack_a->stack_ar[stacks.stack_a->stacked - 1]
		> stacks.stack_a->stack_ar[0]
		&& stacks.stack_a->stack_ar[stacks.stack_a->stacked - 1]
		!= number)
		choose_best_move(stacks.stack_a, point);
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
		choose_best_move(stacks.stack_a, point);
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
			if ((stack_a->stack_ar[0]
					< stack_a->stack_ar[stack_a->stacked - 1])
				&& ((stack_a->stack_ar[0]
						- stack_a->stack_ar[stack_a->stacked - 1])
					> (num[0] - stack_a->stack_ar[stack_a->stacked - 1])))
				rra(stack_a);
			if (stack_a->stack_ar[stack_a->stacked - 1]
				== find_num(stack_a, 0)
				&& stack_a->stack_ar[stack_a->stacked - 1] < smalln)
				ra(stack_a);
		}
	}
}

void	push_b_2_a(t_stack *stack_a, t_stack *stack_b, int *at_back)
{
	int	big_of_two;
	int	number;
	int	number_i;

	number = find_num(stack_b, 1);
	while (stack_b->stacked)
	{
		while (stack_b->stack_ar[stack_b->stacked - 1] < number)
		{
			number = find_num(stack_b, 1);
			big_of_two = get_big_of_two(stack_a, number);
			number_i = find_num_i(stack_b, 1);
			if ((big_of_two == stack_a->stack_ar[0]
					|| stack_b->stack_ar[stack_b->stacked - 1]
					> stack_a->stack_ar[0])
				&& stack_b->stack_ar[stack_b->stacked - 1] != number)
			{
				at_back[0] = at_back[0] + 1;
				pa(stack_a, stack_b);
				ra(stack_a);
			}
			if (stack_b->stacked > 1)
			{
				if (stack_b->stack_ar[stack_b->stacked - 2] == number)
					sb(stack_b);
				else if (number_i >= stack_b->stacked / 2)
					rb(stack_b);
				else
					rrb(stack_b);
			}
		}
		pa(stack_a, stack_b);
		check_back(stack_a, stack_b, at_back, &number);
	}
}

void	sort(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	number;
	int	number_i;
	int	at_back;

	if (sorted(stack_a))
		return ;
	number_i = find_num_i(stack_a, 0);
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
		stack_a = convert_to_seq(stack_a);
		sort(&stack_a, &stack_b);
	}
	return (0);
}
