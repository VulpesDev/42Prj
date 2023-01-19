/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tobinary.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 19:57:55 by tvasilev          #+#    #+#             */
/*   Updated: 2023/01/19 19:57:55 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minitalk.h"

int	str_bin(int ch)
{
	int	binary;
	int	num;
	int	topower;
	int	dec;

	topower = 0;
	dec = 0;
	binary = ch;
	while (binary)
	{
		num = binary % 10;
		num <<= topower;
		dec += num;
		topower++;
		binary /= 10;
	}
	return (dec);
}
