/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 11:22:44 by tvasilev          #+#    #+#             */
/*   Updated: 2023/02/01 12:05:33 by tvasilev         ###   ########.fr       */
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
		if (stack->stack_ar[i] < point)
			return (1);
		i++;
	}
	return (0);
}

void	to_print(char *str)
{
	static char	*result;
	static int	skip;

	if(!skip)
	{
		if (result)
		{
			if ((!ft_strncmp(str, "ra", 2) && !ft_strncmp(result, "rb", 2))
			|| (!ft_strncmp(str, "rb", 2) && !ft_strncmp(result, "ra", 2)))
			{
				ft_printf("rr\n");
				skip++;
			}
			else if ((!ft_strncmp(str, "rra", 3) && !ft_strncmp(result, "rrb", 3))
			|| (!ft_strncmp(str, "rrb", 3) && !ft_strncmp(result, "rra", 3)))
			{
				ft_printf("rrr\n");
				skip++;
			}
			else if ((!ft_strncmp(str, "ra", 3) && !ft_strncmp(result, "rra", 3))
			|| (!ft_strncmp(str, "rrb", 3) && !ft_strncmp(result, "rb", 3)))
			{
				skip++;
			}
			else if ((!ft_strncmp(str, "rra", 3) && !ft_strncmp(result, "ra", 3))
			|| (!ft_strncmp(str, "rb", 3) && !ft_strncmp(result, "rrb", 3)))
			{
				skip++;
			}
			else
				ft_printf("%s", result);
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
	int	len;
	int	counter;
	int	small_i;
	
	len = stack.stacked;
	counter = 0;
	small_i = find_num_i(&stack, 0);
	while (counter < len)
	{
		new.stack_ar[small_i] = counter;
		small_i = find_small_i_big_than(&stack, stack.stack_ar[small_i]);
		new.stacked++;
		counter++;
	}
	return (new);
}