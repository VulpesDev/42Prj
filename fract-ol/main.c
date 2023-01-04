#include "fract-ol.h"
#include <time.h>
#include <stdlib.h>

int	handle_no_event(void *data)
{
	/* This function needs to exist, but it is useless for the moment */
	return (0);
}

int point_in_triangle(t_point pp, t_point p1, t_point p2, t_point p3)
{
	float alpha, beta, gamma;
	alpha = ((p2.y - p3.y)*(pp.x - p3.x) + (p3.x - p2.x)*(pp.y - p3.y)) / ((p2.y - p3.y)*(p1.x - p3.x) + (p3.x - p2.x)*(p1.y - p3.y));
	beta = ((p3.y - p1.y)*(pp.x - p3.x) + (p1.x - p3.x)*(pp.y - p3.y)) / ((p2.y - p3.y)*(p1.x - p3.x) + (p3.x - p2.x)*(p1.y - p3.y));
	gamma = 1 - alpha - beta;
	
	if (alpha >= 0 && beta >= 0 && gamma >= 0)
		return 1;
	else
		return 0;
}

void	fill_triangle(t_data *data, t_point p1, t_point p2, t_point p3, int color)
{
	t_point pp;
	point_as(&pp, 0, 0);
	while (pp.y < HEIGHT)
	{
		pp.x = 0;
		while (pp.x < WIDTH)
		{
			if (point_in_triangle(pp, p1, p2, p3))
				my_mlx_pixel_put(data, pp.x, pp.y, color);
			pp.x++;
		}
		pp.y++;
	}
}

void	clear_image(t_data *data)
{
	int	y = 0;
	int	x = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			my_mlx_pixel_put(data, x, y, 0);
			x++;
		}
		y++;
	}
}

int	do_fill = 0;
float	scale = 1;

void	put_triangle(t_data *data, t_point p1, t_point p2, t_point p3, int color)
{
	draw_line(data, p1, p2, color);
	draw_line(data, p2, p3, color);
	draw_line(data, p1, p3, color);
	if (do_fill)
		fill_triangle(data, p1, p2, p3, color);
}

int do_color = 0;

void	sierpinski(t_data *data, t_point p1, t_point p2, t_point p3, int color, int limit)
{
	if (!limit) return;
	put_triangle(data, p1, p2, p3, color);
	t_point pA, pB, pC;
	point_as(&pA, (p1.x + p2.x) / 2, (p1.y + p2.y) / 2);
	point_as(&pB, (p2.x + p3.x) / 2, (p2.y + p3.y) / 2);
	point_as(&pC, (p3.x + p1.x) / 2, (p3.y + p1.y) / 2);
	put_triangle(data, pA, pB, pC, color);
	if (do_color)
		color -= rand();
	sierpinski(data, p1, pA, pC, color, limit - 1);
	sierpinski(data, pA, p2, pB, color, limit - 1);
	sierpinski(data, pC, pB, p3, color, limit - 1);
}

int	i = 0;

t_point point(float x, float y)
{
	t_point	result;

	result.x = x;
	result.y = y;
	return (result);
}

int	x_offset = 0;
int	y_offset = 0;
int tri_limit = 0;

int	handle_input(int keysym, t_var *var)
{
	tri_limit = 3 + scale/3;
	while (i < tri_limit)
		i++;
	printf("%d\n", tri_limit);
	if (keysym == XK_Escape)
		mlx_destroy_window(var->mlx, var->win);
	else if (keysym == 112)
	{
		if (i + 1 < tri_limit)
			i++;
		clear_image(var->img);
		sierpinski(var->img, point((var->p1.x + x_offset) * scale, (var->p1.y + y_offset) * scale),
		 point((var->p2.x + x_offset) * scale, (var->p2.y + y_offset) * scale),
		  point((var->p3.x + x_offset) * scale, (var->p3.y + y_offset) * scale), 0xFFFFFF, i);
		 mlx_put_image_to_window(var->mlx, var->win, var->img->img, 0, 0);
	}
	else if (keysym == 111)
	{
		if (i - 1 > -1)
			i--;
		clear_image(var->img);
		sierpinski(var->img, point((var->p1.x + x_offset) * scale, (var->p1.y + y_offset) * scale),
		 point((var->p2.x + x_offset) * scale, (var->p2.y + y_offset) * scale),
		  point((var->p3.x + x_offset) * scale, (var->p3.y + y_offset) * scale), 0xFFFFFF, i);
		 mlx_put_image_to_window(var->mlx, var->win, var->img->img, 0, 0);
	}
	else if (keysym == 99)
	{
		if (do_color)
			do_color = 0;
		else
			do_color = 1;
		clear_image(var->img);
		sierpinski(var->img, point((var->p1.x + x_offset) * scale, (var->p1.y + y_offset) * scale),
		 point((var->p2.x + x_offset) * scale, (var->p2.y + y_offset) * scale),
		  point((var->p3.x + x_offset) * scale, (var->p3.y + y_offset) * scale), 0xFFFFFF, i);
		mlx_put_image_to_window(var->mlx, var->win, var->img->img, 0, 0);
	}
	else if (keysym == 102)
	{
		if (do_fill)
			do_fill = 0;
		else
			do_fill = 1;
		clear_image(var->img);
		sierpinski(var->img, point((var->p1.x + x_offset) * scale, (var->p1.y + y_offset) * scale),
		 point((var->p2.x + x_offset) * scale, (var->p2.y + y_offset) * scale),
		  point((var->p3.x + x_offset) * scale, (var->p3.y + y_offset) * scale), 0xFFFFFF, i);
		mlx_put_image_to_window(var->mlx, var->win, var->img->img, 0, 0);
	}
	else if (keysym == 61)
	{
		scale += 0.5;
		clear_image(var->img);
		sierpinski(var->img, point((var->p1.x + x_offset) * scale, (var->p1.y + y_offset) * scale),
		 point((var->p2.x + x_offset) * scale, (var->p2.y + y_offset) * scale),
		  point((var->p3.x + x_offset) * scale, (var->p3.y + y_offset) * scale), 0xFFFFFF, i);
		mlx_put_image_to_window(var->mlx, var->win, var->img->img, 0, 0);
	}
	else if (keysym == 45)
	{
		scale -= 0.5;
		clear_image(var->img);
		sierpinski(var->img, point((var->p1.x + x_offset) * scale, (var->p1.y + y_offset) * scale),
		 point((var->p2.x + x_offset) * scale, (var->p2.y + y_offset) * scale),
		  point((var->p3.x + x_offset) * scale, (var->p3.y + y_offset) * scale), 0xFFFFFF, i);
		mlx_put_image_to_window(var->mlx, var->win, var->img->img, 0, 0);
	}
	else if (keysym == XK_Up)
	{
		y_offset -= 10;
		clear_image(var->img);
		sierpinski(var->img, point((var->p1.x + x_offset) * scale, (var->p1.y + y_offset) * scale),
		 point((var->p2.x + x_offset) * scale, (var->p2.y + y_offset) * scale),
		  point((var->p3.x + x_offset) * scale, (var->p3.y + y_offset) * scale), 0xFFFFFF, i);
		mlx_put_image_to_window(var->mlx, var->win, var->img->img, 0, 0);
	}
	else if (keysym == XK_Left)
	{
		x_offset -= 10;
		clear_image(var->img);
		sierpinski(var->img, point((var->p1.x + x_offset) * scale, (var->p1.y + y_offset) * scale),
		 point((var->p2.x + x_offset) * scale, (var->p2.y + y_offset) * scale),
		  point((var->p3.x + x_offset) * scale, (var->p3.y + y_offset) * scale), 0xFFFFFF, i);
		mlx_put_image_to_window(var->mlx, var->win, var->img->img, 0, 0);
	}
	else if (keysym == XK_Down)
	{
		y_offset += 10;
		clear_image(var->img);
		sierpinski(var->img, point((var->p1.x + x_offset) * scale, (var->p1.y + y_offset) * scale),
		 point((var->p2.x + x_offset) * scale, (var->p2.y + y_offset) * scale),
		  point((var->p3.x + x_offset) * scale, (var->p3.y + y_offset) * scale), 0xFFFFFF, i);
		mlx_put_image_to_window(var->mlx, var->win, var->img->img, 0, 0);
	}
	else if (keysym == XK_Right)
	{
		x_offset += 10;
		clear_image(var->img);
		sierpinski(var->img, point((var->p1.x + x_offset) * scale, (var->p1.y + y_offset) * scale),
		 point((var->p2.x + x_offset) * scale, (var->p2.y + y_offset) * scale),
		  point((var->p3.x + x_offset) * scale, (var->p3.y + y_offset) * scale), 0xFFFFFF, i);
		mlx_put_image_to_window(var->mlx, var->win, var->img->img, 0, 0);
	}
	return (0);
}

int	main(void)
{
	srand(time(NULL));
	t_data	img;//necessary in order to create an image
	t_var	var;// contains the pointers to the mlx and the win

	var.mlx = mlx_init();
	var.win = mlx_new_window(var.mlx, WIDTH, HEIGHT, "Hello world!");
	img.img = mlx_new_image(var.mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
	&img.line_length, &img.endian);
	var.img = &img;

	mlx_loop_hook(var.mlx, &handle_no_event, &var);
	mlx_key_hook(var.win, &handle_input, &var);

	t_point p1, p2, p3;

	point_as(&p1, WIDTH/3, HEIGHT - HEIGHT/3);
	point_as(&p2, WIDTH/2, HEIGHT/3);
	point_as(&p3, WIDTH - WIDTH/3, HEIGHT - HEIGHT/3);
	var.p1 = p1;
	var.p2 = p2;
	var.p3 = p3;
	//put_triangle(&img, p1, p2, p3, 0xFFFFFF);
	//sierpinski(&img, p1, p2, p3, 0xFFFFFF, 6);

	mlx_put_image_to_window(var.mlx, var.win, img.img, 0, 0);
	mlx_loop(var.mlx);
	return (0);
}