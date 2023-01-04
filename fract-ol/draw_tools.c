void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x >= WIDTH || x < 0 || y >= HEIGHT || y < 0)
		return;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
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