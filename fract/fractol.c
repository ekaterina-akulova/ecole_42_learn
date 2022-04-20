/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qabderus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 12:25:23 by qabderus          #+#    #+#             */
/*   Updated: 2021/12/09 12:35:11 by qabderus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	check_start(int argc, char **argv)
{
	if (argc < 2 && argv[0])
	{
		printf("Please add a set you want to spectate:\n1. Mandelbrot\n2. Julia");
		exit(0);
	}
	else if (ft_strcmp(argv[1], "Mandelbrot") != 0
		&& ft_strcmp(argv[1], "Julia") != 0)
	{
		printf("Please add a set you want to spectate:\n1. Mandelbrot\n2. Julia");
		exit(0);
	}
}

t_data	params(char **argv, t_data img)
{
	img.shift_factor = 0;
	img.zoom_factor = SCALE;
	img.x0 = WIDTH / 2;
	img.y0 = HEIGHT / 2;
	img.max_iterations = ITERATIONS;
	if (argv[2] && argv[3])
	{
		img.x1 = ft_atof(argv[2]);
		img.y1 = ft_atof(argv[3]);
	}
	else
	{
		img.x1 = -0.30176;
		img.y1 = -0.7842;
	}
	if (img.x1 > 1 || img.x1 < -1 || img.y1 > 1 || img.y1 < -1)
	{
		printf("Please enter proper values for julia set");
		exit (1);
	}
	return (img);
}

void	draw_params(char **argv, t_data *img)
{
	if (ft_strcmp(argv[1], "Mandelbrot") == 0)
	{
		img->map = 1;
		fractal_draw(*img);
	}
	else if (ft_strcmp(argv[1], "Julia") == 0)
	{
		img->map = 2;
		fractal_draw(*img);
	}
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	main(int argc, char **argv)
{
	static t_data	img;
	t_vars			vars;

	check_start(argc, argv);
	vars.mlx = mlx_init();
	if (vars.mlx == NULL)
		return (1);
	vars.window = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "Fract'ol");
	if (vars.window == NULL)
		return (1);
	img.img = mlx_new_image(vars.mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	img = params(argv, img);
	vars.imgs = &img;
	draw_params(argv, &img);
	mlx_put_image_to_window(vars.mlx, vars.window, img.img, 0, 0);
	mlx_hook(vars.window, 6, 1L << 6, julia_mouse_hover, &vars);
	mlx_mouse_hook(vars.window, mouse_zoom, &vars);
	mlx_hook(vars.window, 2, 1L << 0, close, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
