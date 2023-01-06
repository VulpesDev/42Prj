#ifndef FRACTOL_H
# define FRACTOL_H
# include <mlx.h>
# include <X11/keysym.h>
# include <stdlib.h>
# include <math.h>

# define MLX_ERROR 1
# ifndef WIDTH
#  define WIDTH 500
# endif
# ifndef HEIGHT
#  define HEIGHT 500
# endif
# ifndef ITERATIONS
#  define ITERATIONS 250
# endif
# ifndef SCALE_FACTOR
#  define SCALE_FACTOR 1.25
# endif
#endif

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
	float	scale;
	float	o_x;
	float	o_y;
	int	color_palette[5];
}				t_var;

typedef struct s_complex{
	float	r;
	float	i;
}			t_complex;


void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

void	my_mlx_pixel_put_d(t_data *data, int x, int y, int color);

void	paint_image(t_data *data, int color);

void	point_as(t_point *p, float x, float y);

void	draw_line(t_data *data, t_point s_point, t_point e_point, int color);

void	clear_image(t_data *data);

void	draw_axis(t_var *param);

int	mouse_handle(int button, int x, int y, t_var *var);

int	key_handle(int keycode, t_var *var);

t_complex	screen_to_world(float x, float y, t_var *var);

void	mandelbrot(t_data *data, float x, float y, t_var *var);

void	draw_mandelbrot(t_data *img, t_var *var);

void change_color(int palette[], int increase);

int	close_window(t_var *var);