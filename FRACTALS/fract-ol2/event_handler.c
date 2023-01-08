/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 12:37:51 by tvasilev          #+#    #+#             */
/*   Updated: 2023/01/08 12:15:51 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fractol.h"

int	close_window(t_var *var)
{
	mlx_loop_end(var->mlx);
	return (0);
}

int	mouse_handle(int button, int x, int y, t_var *var)
{
	t_complex	coord;

	coord = screen_to_world(x, y, var);
	if (button == 4 || button == 5)
	{
		var->o_x = coord.r;
		var->o_y = coord.i;
		if (button == 4)
			var->scale /= SCALE_FACTOR;
		else
			var->scale *= SCALE_FACTOR;
		draw_set(var->img, var);
		mlx_put_image_to_window(var->mlx, var->win, var->img->img, 0, 0);
	}
	return (0);
}

int	mouse_move_handle(int x, int y, t_var *var)
{
	t_complex	coord;

	coord = screen_to_world(x, y, var);
	var->cr = coord.r;
	var->ci = coord.i;
	draw_set(var->img, var);
	mlx_put_image_to_window(var->mlx, var->win, var->img->img, 0, 0);
	return (0);
}

int	key_handle(int keycode, t_var *var)
{
	if (keycode == XK_Escape)
	{
		close_window(var);
		return (0);
	}
	else if (keycode == 100)
		change_color(var, 1);
	else if (keycode == 97)
		change_color(var, 0);
	else if (keycode == XK_Right)
		var->o_x += OFFSET_FACTOR * (var->scale * 100);
	else if (keycode == XK_Left)
		var->o_x -= OFFSET_FACTOR * (var->scale * 100);
	else if (keycode == XK_Up)
		var->o_y += OFFSET_FACTOR * (var->scale * 100);
	else if (keycode == XK_Down)
		var->o_y -= OFFSET_FACTOR * (var->scale * 100);
	if ((keycode <= 0xff54 && keycode >= 0xff51)
		|| keycode == 100 || keycode == 97)
	{
		draw_set(var->img, var);
		mlx_put_image_to_window(var->mlx, var->win, var->img->img, 0, 0);
	}
	return (0);
}
