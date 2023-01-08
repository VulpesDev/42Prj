/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 10:44:50 by tvasilev          #+#    #+#             */
/*   Updated: 2023/01/08 12:50:47 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <mlx.h>
# include <X11/keysym.h>
# include <stdlib.h>
# include <math.h>
# include "ft_printf/ft_printf.h"
# define MLX_ERROR 1
# define WIDTH 500
# define HEIGHT 500
# define ITERATIONS 250
# define SCALE_FACTOR 1.25
# define OFFSET_FACTOR 0.2
# define COLOR_FACTOR 7

typedef struct s_data {
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

typedef struct s_rgb{
	int	r;
	int	g;
	int	b;
}				t_rgb;

typedef struct s_var{
	void	*mlx;
	void	*win;
	t_data	*img;
	float	scale;
	float	o_x;
	float	o_y;
	t_rgb	rgb;
	char	set;
	float	cr;
	float	ci;
}				t_var;

typedef struct s_complex{
	float	r;
	float	i;
}			t_complex;

t_complex	screen_to_world(float x, float y, t_var *var);

void		my_mlx_pixel_put_d(t_data *data, int x, int y, int color);

void		clear_image(t_data *data);

int			mouse_handle(int button, int x, int y, t_var *var);

int			key_handle(int keycode, t_var *var);

void		mandelbrot(t_data *data, float x, float y, t_var *var);

void		draw_set(t_data *img, t_var *var);

void		change_color(t_var *var, int inc);

int			close_window(t_var *var);

void		julia(t_data *data, float x, float y, t_var *var);

int			mouse_move_handle(int x, int y, t_var *var);

int			print_warning(void);

t_rgb		new_rgb(int r, int g, int b);

int			ft_atoi(const char *nptr);
#endif