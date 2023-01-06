#include"fract-ol.h"

int	close_window(t_var *var)
{
	mlx_loop_end(var->mlx);
	return (0);
}

int	mouse_handle(int button, int x, int y, t_var *var)
{
	t_complex	coord;

	if (button == 4 || button == 5)
	{
		clear_image(var->img);
		coord = screen_to_world(x, y, var);
		var->o_x = coord.r;
		var->o_y = coord.i;
		if (button == 4)
			var->scale /= SCALE_FACTOR;
		else
			var->scale *= SCALE_FACTOR;
		draw_mandelbrot(var->img, var);
		mlx_put_image_to_window(var->mlx, var->win, var->img->img, 0, 0);
	}
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
		change_color(var->color_palette, 1);
	else if (keycode == 97)
		change_color(var->color_palette, 0);
	else if (keycode == XK_Right)
		var->o_x += 0.2 * (var->scale * 100);
	else if (keycode == XK_Left)
		var->o_x -= 0.2 * (var->scale * 100);
	else if (keycode == XK_Up)
		var->o_y += 0.2 * (var->scale * 100);
	else if (keycode == XK_Down)
		var->o_y -= 0.2 * (var->scale * 100);
	if ((keycode <= 0xff54 && keycode >= 0xff51) || keycode == 100 || keycode == 97)
	{
		draw_mandelbrot(var->img, var);
		mlx_put_image_to_window(var->mlx, var->win, var->img->img, 0, 0);
	}
	return (0);
}