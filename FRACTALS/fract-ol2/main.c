/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:44:06 by tvasilev          #+#    #+#             */
/*   Updated: 2023/01/08 12:47:50 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fractol.h"

int	setup_var(t_var *var, t_data *img)
{
	var->mlx = mlx_init();
	if (!var->mlx)
		return (MLX_ERROR);
	var->win = mlx_new_window(var->mlx, WIDTH, HEIGHT, "Fractual");
	if (!var->win)
		return (MLX_ERROR);
	img->img = mlx_new_image(var->mlx, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	var->img = img;
	var->o_x = 0;
	var->o_y = 0;
	var->scale = 0.01;
	var->rgb = new_rgb(22, 18, 15);
	return (0);
}

int	mlx_manage(t_var *var)
{
	draw_set(var->img, var);
	mlx_mouse_hook(var->win, &mouse_handle, var);
	mlx_key_hook(var->win, &key_handle, var);
	mlx_hook(var->win, 17, 0, &close_window, var);
	mlx_hook(var->win, 06, 1L << 9, &mouse_move_handle, var);
	mlx_put_image_to_window(var->mlx, var->win, var->img->img, 0, 0);
	mlx_loop(var->mlx);
	mlx_destroy_window(var->mlx, var->win);
	mlx_destroy_image(var->mlx, var->img->img);
	mlx_destroy_display(var->mlx);
	free(var->mlx);
	return (0);
}

int	main(int argc, char **argv)
{
	t_var		var;
	t_complex	comp;
	t_data		img;

	setup_var(&var, &img);
	if (argc <= 1)
		return (print_warning());
	else
	{
		if (argv[1][0] == 'm' || argv[1][0] == 'j' || argv[1][0] == 't')
			var.set = argv[1][0];
		else
			return (print_warning());
		if (argc >= 4 && argv[1][0] == 'j')
		{
			if (argv[2][0] == 'r' && argv[3][0] == 'i')
			{
				comp = screen_to_world(ft_atoi(&argv[2][1]),
						ft_atoi(&argv[3][1]), &var);
				var.cr = comp.r;
				var.ci = comp.i;
			}
		}
	}
	return (mlx_manage(&var));
}
