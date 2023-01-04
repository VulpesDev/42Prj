#include"fract-ol.h"
#include<complex.h>

void	mandelbrot(t_data *data, double x, double y)
{
	complex	c;
	complex	z;
	int k = 0;


	z = 0;
	c = x + y*I;
	while (k < 500 && z != INFINITY)
	{
		z = cpow(z, 2) + c;
		my_mlx_pixel_put(data, crealf(z) * 100, cimagf(z) * 100, 0xFFFFFF);
		k++;
	}
}

int	mouse_event_callback(int button, int x, int y, t_var *param)
{
	clear_image(param->img);
	draw_axis(param);
	x = x - WIDTH/2;
	y = HEIGHT/2 - y;
	printf("Mouse position: (%lf, %lf)\n", (double)x/300, (double)y/300);
	mandelbrot(param->img, (double)x/300, (double)y/300);
	mlx_put_image_to_window(param->mlx, param->win, param->img->img, 0, 0);
	return (0);
}

int	main(void)
{
	t_data	img;//necessary in order to create an image
	t_var	var;// contains the pointers to the mlx and the win

	var.mlx = mlx_init();
	var.win = mlx_new_window(var.mlx, WIDTH, HEIGHT, "Hello world!");
	img.img = mlx_new_image(var.mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
	&img.line_length, &img.endian);
	var.img = &img;
	draw_axis(&var);

	//mandelbrot(&img, 0.26, 0.48);

	mlx_mouse_hook(var.win, mouse_event_callback, &var);
	mlx_put_image_to_window(var.mlx, var.win, img.img, 0, 0);
	mlx_loop(var.mlx);
	return (0);
}