/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 12:06:31 by tvasilev          #+#    #+#             */
/*   Updated: 2023/02/04 15:16:38 by tvasilev         ###   ########.fr       */
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

void	get_best_move(t_stack *stack, int point)
{
	if (find_small_point(stack, point))
		ra(stack);
	else
		rra(stack);
}
