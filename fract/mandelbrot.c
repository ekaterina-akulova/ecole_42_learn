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

int	color_iteration(int n, t_data *img)
{
	int	color;

	if (img->shift_factor < 7)
		color = (double)((1000 + (n * 1500))
				* (1 + (img->shift_factor * 2000)));
	else
	{
		color = (double)(((1000 + (n * 1500))
					+ ((1 + (img->shift_factor - 7) * 500000000))));
		color = sqrt((color * ((1 + cos(2 * 3.1415 * (log(img->v)
									/ log(2))))) / 2));
	}
	return (color);
}

void	fractal_draw(t_data img)
{
	if (img.map == 1)
		mandelbrot_placeholder(&img);
	else if (img.map == 2 || img.map == 3)
		julia_placeholder(&img);
}

int	mandelbrot_placeholder(t_data *img)
{
	img->n = 0;
	img->x = 0;
	img->y = 0;
	while (img->y < HEIGHT)
	{
		while (img->x < WIDTH)
		{
			img->mx = 0;
			img->my = 0;
			img->k = 0;
			img->n = 0;
			while (img->n < img->max_iterations && img->k == 0)
			{
				coloring_orbits_mandelbrot(img);
			}
			if (img->n == img->max_iterations)
				my_mlx_pixel_put(img, img->x, img->y, 0x551A335F);
			img->x++;
		}
		img->x = 0;
		img->y++;
	}
	return (0);
}

int	julia_placeholder(t_data *img)
{
	img->n = 0;
	img->x = 0;
	img->y = 0;
	while (img->y < HEIGHT)
	{
		while (img->x < WIDTH)
		{
			img->mx = (long double)(img->x - img->x0)
				/ (SCALE / 2) / (img->zoom_factor / SCALE);
			img->my = (long double)(-1)*(img->y - img->y0)
				/ (SCALE / 2) / (img->zoom_factor / SCALE);
			img->k = 0;
			img->n = 0;
			while (img->n < img->max_iterations && img->k == 0)
			{
				coloring_orbits_julia(img);
			}
			if (img->n == img->max_iterations)
				my_mlx_pixel_put(img, img->x, img->y, 0x551A335F);
			img->x++;
		}
		img->x = 0;
		img->y++;
	}
	return (0);
}
