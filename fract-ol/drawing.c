#include "fract-ol.h"
#define pi 3.14159265359
#define CENTER_X WIDTH / 2
#define CENTER_Y HEIGHT / 2

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x > WIDTH || x < 0 || y > HEIGHT || y < 0)
		return;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	point_as(t_point *p, float x, float y)
{
	p->x = x;
	p->y = y;
}

void	draw_line(t_data *data, t_point s_point, t_point e_point, int color)
{
	int	dx, dy, len;
	float	x_inc, y_inc;

	dx = fabs(e_point.x - s_point.x);
	dy = fabs(e_point.y - s_point.y);

	len = dx > dy ? dx : dy;
	x_inc = (float)dx / len;
	y_inc = (float)dy / len;
	while (roundf(s_point.x) != roundf(e_point.x) 
	|| roundf(s_point.y) != roundf(e_point.y))
	{
		my_mlx_pixel_put(data, s_point.x, s_point.y, color);
		if (roundf(s_point.x) < roundf(e_point.x))
			s_point.x += x_inc;
		if (roundf(s_point.y) < roundf(e_point.y))
			s_point.y += y_inc;
		if (roundf(s_point.x) > roundf(e_point.x))
			s_point.x -= x_inc;
		if (roundf(s_point.y) > roundf(e_point.y))
			s_point.y -= y_inc;
	}
}

void	draw_triangle(t_data *data, float a, float b, int color)
{
	t_point p1, p2, p3;
	point_as(&p1, 0, 0);
	point_as(&p2, 0 + a, 0);
	point_as(&p3, 0 + a, 0 + b);
	draw_line(data, p1, p2, color);
	draw_line(data, p2, p3, color);
	draw_line(data, p1, p3, color);
}

void	draw_ngon(t_data *data, int n, float size, int color)
{
	t_point	points[n];
	float r = size/(2*sin(pi/n));
	float theta = 0;
	int	i = 0;
	while (i < n)
	{
		t_point p;
		point_as(&p, size * cos(2*pi*i/n + theta) + CENTER_X,
		size * sin(2*pi*i/n + theta) + CENTER_Y);
		points[i++] = p;
	}
	n--;
	t_point	buff;
	point_as(&buff, points[n].x, points[n].y);
	while (n--)
	{
		my_mlx_pixel_put(data, points[n].x, points[n].y, color);
		draw_line(data, buff, points[n], color);
		buff = points[n];
	}
	draw_line(data, points[0], points[i-1], color);
}

void	draw_circle(t_data *data, float size, int color)
{
	int	n;
	float	k;
	k = 0.55;
	n = round(size * k);
	draw_ngon(data, n, size, color);
}

// int	main(void)
// {
// 	void	*mlx;
// 	void	*mlx_win;
// 	t_data	img;
// 	t_vars vars;

// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, "Hello world!");
// 	img.img = mlx_new_image(mlx, WIDTH, HEIGHT);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
// 	&img.line_length, &img.endian);

// 	vars.mlx = mlx;
// 	vars.win = mlx_win;
// 	//draw_triangle(&img, 10, 150, 0x00FF0000);
// 	//draw_ngon(&img, 4, 50, 0x00FF0000);
// 	draw_circle(&img, 50, 0x00FF0000);

// 	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
// 	mlx_hook(mlx_win, 2, 1L<<0, close, &vars);
// 	mlx_loop(mlx);
// 	return (0);
// }