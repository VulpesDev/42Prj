#include "fract-ol.h"
#define pi 3.14159265359
#define CENTER_X WIDTH / 2
#define CENTER_Y HEIGHT / 2

void	point_as(t_point *p, float x, float y)
{
	p->x = x;
	p->y = y;
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