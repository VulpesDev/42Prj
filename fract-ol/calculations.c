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