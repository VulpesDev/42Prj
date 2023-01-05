#include"fract-ol.h"
#include<complex.h>

float scale = 100;

int	color_palette[] = {
	0xbe9b7b,
	0x854442,
	0xfff4e6,
	0x3c2f2f,
	0xbe9b7b
};

int	ORIGIN_X = 0, ORIGIN_Y = 0;

void	mandelbrot(t_data *data, float x, float y)
{
	complex	c;
	complex	z;
	int k = 0;
	float	dist;

	z = 0;
	c = x + y*I;
	while (k < 250 && c != INFINITY)
	{
		z = cpow(z, 2) + c;
		dist = sqrt(creal(z) * creal(z) + cimag(z) * cimag(z));
			if (dist > 2)
			{
				my_mlx_pixel_put(data, ORIGIN_X + crealf(c) * scale, -ORIGIN_Y + cimagf(c) * scale, color_palette[k % 5]);
				return ;
			}
		k++;
	}
	my_mlx_pixel_put(data, ORIGIN_X + crealf(c) * scale, -ORIGIN_Y + cimagf(c) * scale, 0);	
	//printf("%d\n", k);
}

void	draw_mandelbrot(t_data *data, float detail)
{
	float kx = -WIDTH*3 / (scale / 100);
	float ky = -HEIGHT*3 / (scale / 100);
	while (ky < HEIGHT*3)
	{
		kx = -WIDTH*3 / (scale / 100);
		while (kx < WIDTH*3 / (scale / 100))
		{
			//printf("(%lf, %lf)", (float)((float)kx/(float)WIDTH), (float)((float)ky/(float)HEIGHT));
			printf("\r%d%%", (int)(33.33 * ((float)((float)ky/((float)HEIGHT*3)) + 2)));
			mandelbrot(data, (float)((float)kx/(float)WIDTH), (float)((float)ky/(float)HEIGHT));
			kx+= detail / (float)(scale / 100.0);
		}
		ky+= detail / (float)(scale / 100.0);
	}
	printf("\r100%% - ");
	printf("\x1b[32mDONE\x1b[0m\n");
}

int	mouse_event_callback(int button, int x, int y, t_var *param)
{
	scale += 40;
	x = WIDTH/2 - x;
	y = HEIGHT/2 - y;
	printf("(%i, %i)\n", x, y);
	ORIGIN_X = x;
	ORIGIN_Y = y;
	clear_image(param->img);
	draw_mandelbrot(param->img, DETAIL);
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
	paint_image(&img, 0xFFFFFF);
	//draw_axis(&var);
	draw_mandelbrot(&img, DETAIL);
	//mandelbrot(&img, 0.26, 0.48);

	mlx_mouse_hook(var.win, mouse_event_callback, &var);
	mlx_put_image_to_window(var.mlx, var.win, img.img, 0, 0);
	mlx_loop(var.mlx);
	return (0);
}