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

void	coloring_orbits_mandelbrot(t_data *img)
{
	img->x_temp = (long double)((img->mx * img->mx
	- img->my * img->my) + ((img->x
					- img->x0) / img->zoom_factor));
	img->my = (long double)2 * img->mx * img->my
		+ ((img->y - img->y0) / img->zoom_factor);
	img->mx = img->x_temp;
	if (((img->mx * img->mx) + (img->my * img->my)) > 1000)
	{
		img->v = log((img->mx * img->mx + img->my
					* img->my)) / pow(2, img->n);
		my_mlx_pixel_put(img, img->x, img->y,
			color_iteration(img->n, img));
		img->k++;
	}
	else
		img->n++;
}

void	coloring_orbits_julia(t_data *img)
{
	img->x_temp = (long double)((img->mx * img->mx
				- img->my * img->my) + img->x1);
	img->my = (long double)2 * img->mx * img->my + img->y1;
	img->mx = img->x_temp;
	if ((img->mx * img->mx + img->my * img->my) > 4)
	{
		img->v = (double)log((img->mx * img->mx
					+ img->my * img->my)) / pow(2, img->n);
		my_mlx_pixel_put(img, img->x, img->y,
			color_iteration(img->n, img));
		img->k++;
	}
	else
		img->n++;
}
