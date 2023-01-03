#include "fract-ol.h"
#include <time.h>
#include <stdlib.h>

int	handle_no_event(void *data)
{
	/* This function needs to exist, but it is useless for the moment */
	return (0);
}

int simplify_out(int num)
{
	if (num < 0)
		return (-1);
	else if (num == 0)
		return (0);
	else if (num > 0)
		return (1);
}

t_point point(float x, float y)
{
	t_point	result;
	result.x = x;
	result.y = y;
	return (result);
}

t_point comp_center(t_point pp, t_point center)
{
	t_point result;
	result.x = simplify_out(pp.x - center.x);
	result.y = simplify_out(pp.y - center.y);
	return (result);
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

t_point	point_scale(t_point p, float scale)
{
	p.x *= scale;
	p.y *= scale;
	return (p);
}

int	do_fill = 0;

void	put_triangle(t_data *data, t_triangle *tr)
{
	draw_line(data, tr->p1, tr->p2, tr->color);
	draw_line(data, tr->p2, tr->p3, tr->color);
	draw_line(data, tr->p1, tr->p3, tr->color);
	if (do_fill)
		fill_triangle(data, tr->p1, tr->p2, tr->p3, tr->color);
}

int do_color = 0;

void	sierpinski(t_data *data, t_point p1, t_point p2, t_point p3, int color, int limit)
{
	if (!limit) return;
	t_triangle trtr;
	trtr.p1 = p1;
	trtr.p2 = p2;
	trtr.p3 = p3;
	trtr.color = color;
	put_triangle(data, &trtr);
	t_triangle tr;
	point_as(&tr.p1, (p1.x + p2.x) / 2, (p1.y + p2.y) / 2);
	point_as(&tr.p2, (p2.x + p3.x) / 2, (p2.y + p3.y) / 2);
	point_as(&tr.p3, (p3.x + p1.x) / 2, (p3.y + p1.y) / 2);
	tr.color = color;
	put_triangle(data, &tr);
	if (do_color)
		color -= rand();
	sierpinski(data, p1, tr.p1, tr.p3, color, limit - 1);
	sierpinski(data, tr.p1, p2, tr.p2, color, limit - 1);
	sierpinski(data, tr.p3, tr.p2, p3, color, limit - 1);
}

int	simple_equation(int x)
{
	if (x == 0)
		return (1);
	else
		return (x);
}

int	i = 0;
float	scale = 1;

int	handle_input(int keysym, t_var *var)
{
	if (keysym == XK_Escape)
		mlx_destroy_window(var->mlx, var->win);
	else if (keysym == XK_Up)
	{
		if (i + 1 < 7)
			i++;
		clear_image(var->img);
		sierpinski(var->img, var->tr->p1, var->tr->p2, var->tr->p3, var->tr->color, i);
		 mlx_put_image_to_window(var->mlx, var->win, var->img->img, 0, 0);
	}
	else if (keysym == XK_Down)
	{
		if (i - 1 > -1)
			i--;
		clear_image(var->img);
		sierpinski(var->img, var->tr->p1, var->tr->p2, var->tr->p3, var->tr->color, i);
		mlx_put_image_to_window(var->mlx, var->win, var->img->img, 0, 0);
	}
	else if (keysym == 99)
	{
		if (do_color)
			do_color = 0;
		else
			do_color = 1;
		clear_image(var->img);
		sierpinski(var->img, var->tr->p1, var->tr->p2, var->tr->p3, var->tr->color, i);
		mlx_put_image_to_window(var->mlx, var->win, var->img->img, 0, 0);
	}
	else if (keysym == 102)
	{
		if (do_fill)
			do_fill = 0;
		else
			do_fill = 1;
		clear_image(var->img);
		sierpinski(var->img, var->tr->p1, var->tr->p2, var->tr->p3, var->tr->color, i);
		mlx_put_image_to_window(var->mlx, var->win, var->img->img, 0, 0);
	}
	else if (keysym == XK_Right)
	{
		scale++;
		clear_image(var->img);
		sierpinski(var->img, point(var->tr->p1.x*simple_equation(scale * (comp_center(var->tr->p1, var->tr->center).x)),
		 var->tr->p1.y*simple_equation(scale * comp_center(var->tr->p1, var->tr->center).y)), var->tr->p2, var->tr->p3, var->tr->color, i);
		mlx_put_image_to_window(var->mlx, var->win, var->img->img, 0, 0);
	}
	else if (keysym = XK_Left)
	{
		 
	}
	//printf("%d\n",keysym);
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

	t_triangle tr;
	point_as(&tr.p1, WIDTH/3, HEIGHT - HEIGHT/3);
	point_as(&tr.p2, WIDTH/2, HEIGHT/3);
	point_as(&tr.p3, WIDTH - WIDTH/3, HEIGHT - HEIGHT/3);
	tr.color = 0xFFFFFF;
	var.tr = &tr;
	tr.center.x = (tr.p1.x + tr.p2.x + tr.p3.x)/3;
	tr.center.y = (tr.p1.y + tr.p2.y + tr.p3.y)/3;
	mlx_loop_hook(var.mlx, &handle_no_event, &var);
	mlx_key_hook(var.win, &handle_input, &var);
	
	//put_triangle(&img, &tr);
	//sierpinski(&img, &tr, 2);
	//draw_ngon(&img, 30, 100, 0xFFFFFF);

	mlx_put_image_to_window(var.mlx, var.win, img.img, 0, 0);
	mlx_loop(var.mlx);
	return (0);
}