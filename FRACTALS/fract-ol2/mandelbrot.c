#include"fract-ol.h"

void change_color(int palette[], int increase)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		if (increase)
			palette[i] += 32;
		else
			palette[i] -= 32;
		i++;
	}
}

t_complex	screen_to_world(float x, float y, t_var *var)
{
	t_complex	result;
	result.r = var->o_x + (x - WIDTH / 2) * var->scale;
	result.i = var->o_y - (y - HEIGHT / 2) * var->scale;
	return (result);
}

void	mandelbrot(t_data *data, float x, float y, t_var *var)
{
	t_complex	c;
	t_complex	z;
	int	k = 0;

	z.r = 0;
	z.i = 0;
	c = screen_to_world(x, y, var);
	while (z.r*z.r + z.i*z.i <= 2*2 && k < ITERATIONS)
	{
		t_complex	_z;
		_z.r = pow(z.r, 2) - pow(z.i, 2) + c.r;
		_z.i = 2*z.r*z.i + c.i;
		z.r = _z.r;
		z.i = _z.i;
		k++;
	}
	if (k >= ITERATIONS)
		my_mlx_pixel_put_d(data, x, y, 0);
	else
		my_mlx_pixel_put_d(data, x, y, var->color_palette[k%5]);
}

void	draw_mandelbrot(t_data *img, t_var *var)
{
	int kx = 0;
	int ky = 0;
	while (ky < HEIGHT)
	{
		kx = 0;
		while (kx < WIDTH)
		{
			mandelbrot(img, kx, ky, var);
			kx += 1;
		}
		ky += 1;
	}
}

int	main(void)
{
	t_data	img;//necessary in order to create an image
	t_var	var;// contains the pointers to the mlx and the win

	var.mlx = mlx_init();
	if (!var.mlx)
		return (MLX_ERROR);
	var.win = mlx_new_window(var.mlx, WIDTH, HEIGHT, "Fractual");
	if (!var.win)
	{
		free(var.win);
		return (MLX_ERROR);
	}
	img.img = mlx_new_image(var.mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
	&img.line_length, &img.endian);
	var.img = &img;
	var.o_x = 0;
	var.o_y = 0;
	var.scale = 0.01;
	var.color_palette[0] = 0xbe9b7b;
	var.color_palette[1] = 0x854442;
	var.color_palette[2] = 0xfff4e6;
	var.color_palette[3] = 0x3c2f2f;
	var.color_palette[4] = 0xbe9b7b;
	paint_image(var.img, 0xFFFFFF);

	draw_mandelbrot(var.img, &var);

	mlx_mouse_hook(var.win, &mouse_handle, &var);
	mlx_key_hook(var.win, &key_handle, &var);
	mlx_hook(var.win, 17, 0, &close_window, &var);
	mlx_put_image_to_window(var.mlx, var.win, img.img, 0, 0);
	mlx_loop(var.mlx);
	mlx_destroy_image(var.mlx, var.img->img);
	mlx_destroy_display(var.mlx);
	free(var.mlx);
	return (0);
}