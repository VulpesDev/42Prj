#include"fract-ol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	x = WIDTH/2 + x;
	y = HEIGHT/2 - y;
	if (x >= WIDTH || x<= 0 || y >= HEIGHT || y <= 0)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
void	my_mlx_pixel_put_d(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x >= WIDTH || x<= 0 || y >= HEIGHT || y <= 0)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_axis(t_var *param)
{
	t_point pc;
	t_point pu;
	t_point pr;

	point_as(&pc, 0, 0);
	point_as(&pu, 0, HEIGHT/2);
	point_as(&pr, WIDTH/2, 0);
	draw_line(param->img, pc, pu, 0xFF0000);
	draw_line(param->img, pc, pr, 0xFF0000);
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
			my_mlx_pixel_put_d(data, x, y, 0);
			x++;
		}
		y++;
	}
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