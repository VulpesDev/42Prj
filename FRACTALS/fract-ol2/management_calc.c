/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   management_calc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 12:35:55 by tvasilev          #+#    #+#             */
/*   Updated: 2023/01/08 11:52:34 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fractol.h"

void	change_color(t_var *var, int inc)
{
	if (inc)
	{
		var->rgb.r += COLOR_FACTOR;
		var->rgb.g += COLOR_FACTOR;
		var->rgb.b += COLOR_FACTOR;
	}
	else
	{
		var->rgb.r -= COLOR_FACTOR;
		var->rgb.g -= COLOR_FACTOR;
		var->rgb.b -= COLOR_FACTOR;
	}
}

t_complex	screen_to_world(float x, float y, t_var *var)
{
	t_complex	result;

	result.r = var->o_x + (x - WIDTH / 2) * var->scale;
	result.i = var->o_y - (y - HEIGHT / 2) * var->scale;
	return (result);
}

void	my_mlx_pixel_put_d(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x >= WIDTH || x <= 0 || y >= HEIGHT || y <= 0)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

t_rgb	new_rgb(int r, int g, int b)
{
	t_rgb	result;

	result.r = r;
	result.g = g;
	result.b = b;
	return (result);
}
