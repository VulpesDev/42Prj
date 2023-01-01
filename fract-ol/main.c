#include <mlx.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define pi 3.14159265359
#define WIDTH 200
#define HEIGHT 200
#define CENTER_X WIDTH / 2
#define CENTER_Y HEIGHT / 2


typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_point{
	float	x;
	float	y;
}				t_point;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

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

	dx = abs(e_point.x - s_point.x);
	dy = abs(e_point.y - s_point.y);
	printf("dx:%i,dy:%i\n", dx, dy);
	len = dx > dy ? dx : dy;
	x_inc = (float)dx / len;
	y_inc = (float)dy / len;
	while (s_point.x < e_point.x || s_point.y < e_point.y)
	{
		my_mlx_pixel_put(data, s_point.x, s_point.y, color);
		s_point.x += x_inc;
		s_point.y += y_inc;
	}
	while (s_point.x > e_point.x || s_point.y > e_point.y)
	{
		my_mlx_pixel_put(data, s_point.x, s_point.y, color);
		s_point.x -= x_inc;
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
	t_point	c;
	point_as(&c, CENTER_X, CENTER_Y);
	while (n--)
	{
		my_mlx_pixel_put(data, points[n].x, points[n].y, color);
		draw_line(data, c, points[n], color);
		printf("p%i-- px:%lf, py:%lf\n", n, points[n].x, points[n].y);
	}
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, HEIGHT, WIDTH, "Hello world!");
	img.img = mlx_new_image(mlx, HEIGHT, WIDTH);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
	&img.line_length, &img.endian);

	t_point p1, p2;
	point_as(&p1, 120, 120);
	point_as(&p2, 140, 20);
	//draw_triangle(&img, 1560, 1012, 0x00FF0000);
	//draw_ngon(&img, 6, 40, 0x00FF0000);
	draw_line(&img, p1, p2, 0x00FF0000);

	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}