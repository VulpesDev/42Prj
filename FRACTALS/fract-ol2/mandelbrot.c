#include"fract-ol.h"
#define ITERATIONS 250
#define SCALE_FACTOR 1.25

int	color_palette[] = {
	0xbe9b7b,
	0x854442,
	0xfff4e6,
	0x3c2f2f,
	0xbe9b7b
};

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

typedef struct s_complex{
	float	r;
	float	i;
}			t_complex;

float scale = 0.01;
float ORIGIN_X = 0, ORIGIN_Y = 0;

t_complex	screen_to_world(float x, float y)
{
	t_complex	result;
	result.r = ORIGIN_X + (x - WIDTH / 2) * scale;
	result.i = ORIGIN_Y - (y - HEIGHT / 2) * scale;
	return (result);
}

void	mandelbrot(t_data *data, float x, float y)
{
	t_complex	c;
	t_complex	z;
	int	k = 0;

	z.r = 0;
	z.i = 0;
	c = screen_to_world(x, y);
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
		my_mlx_pixel_put_d(data, x, y, color_palette[k%5]);
}

void	draw_mandelbrot(t_data *img)
{
	int kx = 0;
	int ky = 0;
	while (ky < HEIGHT)
	{
		kx = 0;
		while (kx < WIDTH)
		{
			mandelbrot(img, kx, ky);
			kx += 1;
		}
		printf("\r%i%%", (int)(ky / 5));
		ky += 1;
	}
	printf("\r100%% - ");
	printf("\x1b[32mDONE\x1b[0m\n"); // switch with ft_printf
}

int	mouse(int button, int x, int y, t_var *var)
{
	t_complex	coord;

	if (button == 4){
	clear_image(var->img);
	coord = screen_to_world(x, y);
	ORIGIN_X = coord.r;
	ORIGIN_Y = coord.i;
	scale /= SCALE_FACTOR;
	draw_mandelbrot(var->img);
	mlx_put_image_to_window(var->mlx, var->win, var->img->img, 0, 0);
	}
	else if (button == 5)
	{
		clear_image(var->img);
	coord = screen_to_world(x, y);
	ORIGIN_X = coord.r;
	ORIGIN_Y = coord.i;
	scale *= SCALE_FACTOR;
	draw_mandelbrot(var->img);
	mlx_put_image_to_window(var->mlx, var->win, var->img->img, 0, 0);
	}
	return (0);
}

int	key(int keycode, t_var *var)
{
	if (keycode == XK_Escape)
		mlx_destroy_window(var->mlx, var->win);
	else if (keycode == 100)
	{
		change_color(color_palette, 1);
		draw_mandelbrot(var->img);
		mlx_put_image_to_window(var->mlx, var->win, var->img->img, 0, 0);
	}
	else if (keycode == 97)
	{
		change_color(color_palette, 0);
		draw_mandelbrot(var->img);
		mlx_put_image_to_window(var->mlx, var->win, var->img->img, 0, 0);
	}
	else if (keycode == XK_Right)
	{
		ORIGIN_X += 0.2 * (scale * 100);
		draw_mandelbrot(var->img);
		mlx_put_image_to_window(var->mlx, var->win, var->img->img, 0, 0);
	}
	else if (keycode == XK_Left)
	{
		ORIGIN_X -= 0.2 * (scale * 100);
		draw_mandelbrot(var->img);
		mlx_put_image_to_window(var->mlx, var->win, var->img->img, 0, 0);
	}
	else if (keycode == XK_Up)
	{
		ORIGIN_Y += 0.2 * (scale * 100);
		draw_mandelbrot(var->img);
		mlx_put_image_to_window(var->mlx, var->win, var->img->img, 0, 0);
	}
	else if (keycode == XK_Down)
	{
		ORIGIN_Y -= 0.2 * (scale * 100);
		draw_mandelbrot(var->img);
		mlx_put_image_to_window(var->mlx, var->win, var->img->img, 0, 0);
	}
	printf("%d\n", keycode);
	return (0);
}

int	main(void)
{
	t_data	img;//necessary in order to create an image
	t_var	var;// contains the pointers to the mlx and the win

	var.mlx = mlx_init();
	var.win = mlx_new_window(var.mlx, WIDTH, HEIGHT, "Fractual");
	img.img = mlx_new_image(var.mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
	&img.line_length, &img.endian);
	var.img = &img;
	paint_image(&img, 0xFFFFFF);

	draw_mandelbrot(&img);

	mlx_mouse_hook(var.win, &mouse, &var);
	mlx_key_hook(var.win, &key, &var);
	mlx_put_image_to_window(var.mlx, var.win, img.img, 0, 0);
	mlx_loop(var.mlx);
	return (0);
}