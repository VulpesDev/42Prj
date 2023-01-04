#include"fract-ol.h"
#include<complex.h>
#include<time.h>

int scale = 1;
void	mandelbrot(t_data *data, double x, double y)
{
	complex	c;
	complex	z;
	int k = 0;

	z = 0;
	c = x + y*I;
	while (k < 500 && pow(creal(c), 2) + pow(cimag(c), 2) < 4)
	{
		my_mlx_pixel_put(data, crealf(z) * scale, cimagf(z) * scale, k * k);
		z = cpow(z, 2) + c;
		k++;
	}
	
	//printf("%d\n", k);
}

int	mouse_event_callback(int button, int x, int y, t_var *param)
{
	//if (button == 0)
		
	// clear_image(param->img);
	// draw_axis(param);
	// x = x - WIDTH/2;
	// y = HEIGHT/2 - y;
	clear_image(param->img);
	printf("%s\n", "Clicked!");
	if (button == 1)
	{
		int	t;
		while (1)
		{
			t = clock()/10000;
			printf("%d\n", t);
			if (t % 2 == 0)
			{
				double kx = -1;
				double ky = -1;
				while (ky < 1.0)
				{
					kx = -1;
					while (kx < 1.0)
					{
						mandelbrot(param->img, kx, ky);
						kx+= 0.05;
					}
					ky+= 0.05;
				}
				scale+= 5;
			}
			mlx_put_image_to_window(param->mlx, param->win, param->img->img, 0, 0);
		}
		// printf("%s\n", "Clicked button 1");
		// double kx = -1;
		// double ky = -1;
		// while (ky < 1.0)
		// {
		// 	kx = -1;
		// 	while (kx < 1.0)
		// 	{
		// 		mandelbrot(param->img, kx, ky);
		// 		kx+= 0.04;
		// 	}
		// 	ky+= 0.04;
		// }
		// scale+=1;
	}
	mlx_put_image_to_window(param->mlx, param->win, param->img->img, 0, 0);
	//printf("Mouse position: (%lf, %lf)\n", (double)x, (double)y);
	// mandelbrot(param->img, (double)x, (double)y);
	//mlx_put_image_to_window(param->mlx, param->win, param->img->img, 0, 0);
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
	//draw_axis(&var);
	double kx = -2;
	double ky = -2;
	while (ky < 2.0)
	{
		kx = -2;
		while (kx < 2.0)
		{
			mandelbrot(var.img, kx, ky);
			kx+= 0.01;
		}
		ky+= 0.01;
	}
	//mandelbrot(&img, 0.26, 0.48);

	mlx_mouse_hook(var.win, mouse_event_callback, &var);
	mlx_put_image_to_window(var.mlx, var.win, img.img, 0, 0);
	mlx_loop(var.mlx);
	return (0);
}