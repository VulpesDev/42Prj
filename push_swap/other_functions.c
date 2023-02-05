/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 11:22:44 by tvasilev          #+#    #+#             */
/*   Updated: 2023/02/05 12:36:36 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorted(t_stack *stack)
{
	int	i;

	i = -1;
	while (++i < stack->stacked - 1)
		if (stack->stack_ar[i] < stack->stack_ar[i + 1])
			return (0);
	return (1);
}

int	is_val_under(t_stack *stack, int point)
{
	int	i;

	i = 0;
	while (i < stack->stacked)
	{
		if (stack->stack_ar[i] <= point)
			return (1);
		i++;
	}
	return (0);
}

void	conditions_for_to_print(char **str, char **result, int *skip)
{
	if ((!ft_strncmp(*str, "ra", 2) && !ft_strncmp(*result, "rb", 2))
		|| (!ft_strncmp(*str, "rb", 2) && !ft_strncmp(*result, "ra", 2)))
	{
		ft_printf("rr\n");
		skip[0]++;
	}
	else if (((!ft_strncmp(*str, "rra", 3)
				&& !ft_strncmp(*result, "rrb", 3))
			|| (!ft_strncmp(*str, "rrb", 3)
				&& !ft_strncmp(*result, "rra", 3))))
	{
		ft_printf("rrr\n");
		skip[0]++;
	}
	else if (((!ft_strncmp(*str, "ra", 3)
				&& !ft_strncmp(*result, "rra", 3))
			|| (!ft_strncmp(*str, "rrb", 3)
				&& !ft_strncmp(*result, "rb", 3)))
		|| ((!ft_strncmp(*str, "rra", 3)
				&& !ft_strncmp(*result, "ra", 3))
			|| (!ft_strncmp(*str, "rb", 3)
				&& !ft_strncmp(*result, "rrb", 3))))
		skip[0]++;
	else
		ft_printf("%s", *result);
}

void	to_print(char *str)
{
	static char	*result;
	static int	skip;

	if (!skip)
	{
		if (result)
		{
			conditions_for_to_print(&str, &result, &skip);
			free(result);
		}
	}
	else
	{
		skip++;
		if (skip > 1)
			skip = 0;
		free(result);
	}
	result = ft_strdup(str);
	if (*result == ' ')
		free(result);
}

t_stack	convert_to_seq(t_stack stack)
{
	t_stack	new;
	int		len;
	int		counter;
	int		small_i;

	len = stack.stacked;
	counter = 0;
	new.stacked = 0;
	small_i = -1;
	while (++small_i < len)
		new.stack_ar[small_i] = -1;
	small_i = find_num_i(&stack, 0);
	while (counter < len - 1)
	{
		new.stack_ar[small_i] = counter;
		new.stacked++;
		counter++;
		small_i = find_small_i_big_than(&stack, stack.stack_ar[small_i]);
	}
	new.stacked++;
	small_i = -1;
	while (++small_i < len)
		if (new.stack_ar[small_i] < 0)
			new.stack_ar[small_i] = counter;
	return (new);
}
