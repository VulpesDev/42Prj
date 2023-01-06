#include <mlx.h>
#include <X11/keysym.h>
#include <stdio.h>
#include <math.h>

#define WIDTH 500
#define HEIGHT 500

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

typedef struct	s_var{
	void	*mlx;
	void	*win;
	t_data	*img;
}				t_var;


void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

void	my_mlx_pixel_put_d(t_data *data, int x, int y, int color);

void	paint_image(t_data *data, int color);

void	point_as(t_point *p, float x, float y);

void	draw_line(t_data *data, t_point s_point, t_point e_point, int color);

void	clear_image(t_data *data);

void	draw_axis(t_var *param);