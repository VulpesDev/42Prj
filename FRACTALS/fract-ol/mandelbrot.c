#include"fract-ol.h"
#include<complex.h>

int scale = 100;

int	color_palette[] = {
	0xbe9b7b,
	0x854442,
	0xfff4e6,
	0x3c2f2f,
	0xbe9b7b
};

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
				my_mlx_pixel_put(data, crealf(c) * scale, cimagf(c) * scale, color_palette[k % 5]);
				return ;
			}
		k++;
	}
	my_mlx_pixel_put(data, crealf(c) * scale, cimagf(c) * scale, 0);
	
	
	//printf("%d\n", k);
}

int	mouse_event_callback(int button, int x, int y, t_var *param)
{
	clear_image(param->img);
	printf("%s\n", "Clicked!");
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
	int kx = -WIDTH*3;
	int ky = -HEIGHT*3;
	while (ky < HEIGHT*3)
	{
		kx = -WIDTH*3;
		while (kx < WIDTH*3)
		{
			//printf("(%lf, %lf)", (float)((float)kx/(float)WIDTH), (float)((float)ky/(float)HEIGHT));
			printf("%d%%\n", (int)(33.33 * ((float)((float)ky/((float)HEIGHT*3)) + 2)));
			mandelbrot(var.img, (float)((float)kx/(float)WIDTH), (float)((float)ky/(float)HEIGHT));
			kx+= 4;
		}
		ky+= 4;
	}
	//mandelbrot(&img, 0.26, 0.48);

	mlx_mouse_hook(var.win, mouse_event_callback, &var);
	mlx_put_image_to_window(var.mlx, var.win, img.img, 0, 0);
	mlx_loop(var.mlx);
	return (0);
}