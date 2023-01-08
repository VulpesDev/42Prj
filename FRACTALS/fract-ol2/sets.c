/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 14:18:21 by tvasilev          #+#    #+#             */
/*   Updated: 2023/01/08 12:31:12 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fractol.h"

void	mandelbrot(t_data *data, float x, float y, t_var *var)
{
	t_complex	c;
	t_complex	z;
	t_complex	z_sq;
	int			k;

	k = 0;
	z.r = 0;
	z.i = 0;
	z_sq.r = z.r * z.r;
	z_sq.i = z.i * z.i;
	c = screen_to_world(x, y, var);
	while (z_sq.r + z_sq.i <= 4 && k++ < ITERATIONS)
	{
		z.i = z.r * z.i;
		z.i += z.i + c.i;
		z.r = z_sq.r - z_sq.i + c.r;
		z_sq.r = z.r * z.r;
		z_sq.i = z.i * z.i;
	}
	if (k >= ITERATIONS)
		my_mlx_pixel_put_d(data, x, y, 0);
	else
		my_mlx_pixel_put_d(data, x, y,
			((k << var->rgb.r) + (k << var->rgb.g) + (k * var->rgb.b + k)));
}

void	julia(t_data *data, float x, float y, t_var *var)
{
	t_complex	c;
	t_complex	z;
	t_complex	z_sq;
	int			k;

	k = 0;
	z = screen_to_world(x, y, var);
	c.r = var->cr;
	c.i = var->ci;
	z_sq.r = z.r * z.r;
	z_sq.i = z.i * z.i;
	while (z_sq.r + z_sq.i <= 4 && k++ < ITERATIONS)
	{
		z.i = z.r * z.i;
		z.i += z.i + c.i;
		z.r = z_sq.r - z_sq.i + c.r;
		z_sq.r = z.r * z.r;
		z_sq.i = z.i * z.i;
	}
	if (k >= ITERATIONS)
		my_mlx_pixel_put_d(data, x, y, 0);
	else
		my_mlx_pixel_put_d(data, x, y,
			((k << var->rgb.r) + (k << var->rgb.g) + (k * var->rgb.b + k)));
}

void	tricorn(t_data *data, float x, float y, t_var *var)
{
	t_complex	c;
	t_complex	z;
	t_complex	z_sq;
	int			k;

	k = 0;
	z.r = 0;
	z.i = 0;
	z_sq.r = z.r * z.r;
	z_sq.i = z.i * z.i;
	c = screen_to_world(x, y, var);
	while (z_sq.r + z_sq.i <= 4 && k++ < ITERATIONS)
	{
		z.i = z.r * z.i * -1;
		z.i += z.i + c.i;
		z.r = z_sq.r - z_sq.i + c.r;
		z_sq.r = z.r * z.r;
		z_sq.i = z.i * z.i;
	}
	if (k >= ITERATIONS)
		my_mlx_pixel_put_d(data, x, y, 0);
	else
		my_mlx_pixel_put_d(data, x, y,
			((k << var->rgb.r) + (k << var->rgb.g) + (k * var->rgb.b + k)));
}

void	draw_set(t_data *img, t_var *var)
{
	int	kx;
	int	ky;

	kx = -1;
	ky = -1;
	while (++ky < HEIGHT)
	{
		kx = -1;
		while (++kx < WIDTH)
			if (var->set == 'm')
				mandelbrot(img, kx, ky, var);
		else if (var->set == 'j')
			julia(img, kx, ky, var);
		else if (var->set == 't')
			tricorn(img, kx, ky, var);
	}
}
