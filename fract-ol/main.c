#include <mlx.h>
#include <X11/keysym.h>

#define WIDTH 1920
#define HEIGHT 1080

typedef struct	s_var{
	void	*mlx_ptr;
	void	*win_ptr;
}				t_var;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

int	handle_input(int keysym, t_var *var)
{
	if (keysym == XK_Escape)
		mlx_destroy_window(var->mlx_ptr, var->win_ptr);
	return (0);
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	t_var	var;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, "Hello world!");
	img.img = mlx_new_image(mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
	&img.line_length, &img.endian);

	var.mlx_ptr = mlx;
	var.win_ptr = mlx_win;
	mlx_key_hook(mlx_win, &handle_input, &var);

	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}