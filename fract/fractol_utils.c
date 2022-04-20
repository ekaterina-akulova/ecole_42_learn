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

void	escape(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->window);
	free (vars->mlx);
	exit (0);
}

void	turn_off_mouse_hover(t_vars *vars)
{
	if (vars->imgs->map == 2)
		vars->imgs->map = 3;
	else if (vars->imgs->map == 3)
		vars->imgs->map = 2;
}

int	close(int keycode, t_vars *vars)
{
	if (keycode == 49)
		turn_off_mouse_hover(vars);
	else if (keycode == 0x35)
		escape(vars);
	else if (keycode == 257)
	{
		vars->imgs->shift_factor++;
		if (vars->imgs->shift_factor > 10)
			vars->imgs->shift_factor = 0;
		mlx_clear_window(vars->mlx, vars->window);
		fractal_draw(*(vars)->imgs);
		mlx_put_image_to_window(vars->mlx, vars->window, vars->imgs->img, 0, 0);
	}
	else if (keycode == 256)
	{
		vars->imgs->shift_factor--;
		if (vars->imgs->shift_factor < 0)
			vars->imgs->shift_factor = 10;
		mlx_clear_window(vars->mlx, vars->window);
		fractal_draw(*(vars)->imgs);
		mlx_put_image_to_window(vars->mlx, vars->window, vars->imgs->img, 0, 0);
	}
	return (0);
}

int	mouse_zoom(int keycode, int x, int y, t_vars *vars)
{
	double	zoom;

	if (keycode == 5)
	{
		zoom = vars->imgs->zoom_factor * 1.1;
		vars->imgs->zoom_factor = zoom;
		vars->imgs->x0 = (vars->imgs->x0 + ((vars->imgs->x0 - x) * 0.1));
		vars->imgs->y0 = (vars->imgs->y0 + ((vars->imgs->y0 - y) * 0.1));
		mlx_clear_window(vars->mlx, vars->window);
		fractal_draw(*(vars)->imgs);
		mlx_put_image_to_window(vars->mlx, vars->window, vars->imgs->img, 0, 0);
	}
	else if (keycode == 4)
	{
		zoom = vars->imgs->zoom_factor / 1.1;
		vars->imgs->zoom_factor = zoom;
		vars->imgs->x0 = (vars->imgs->x0 - ((vars->imgs->x0 - x) * 0.09090909));
		vars->imgs->y0 = (vars->imgs->y0 - ((vars->imgs->y0 - y) * 0.09090909));
		mlx_clear_window(vars->mlx, vars->window);
		fractal_draw(*(vars)->imgs);
		mlx_put_image_to_window(vars->mlx, vars->window, vars->imgs->img, 0, 0);
	}
	return (0);
}

int	julia_mouse_hover(int x, int y, t_vars *vars)
{
	if (vars->imgs->map == 3)
	{
		vars->imgs->x1 = (double)(x - vars->imgs->x0) / (SCALE / 2);
		vars->imgs->y1 = (double)(-1)*(y - vars->imgs->y0) / (SCALE / 2);
		mlx_clear_window(vars->mlx, vars->window);
		julia_placeholder(vars->imgs);
		mlx_put_image_to_window(vars->mlx, vars->window, vars->imgs->img, 0, 0);
	}
	return (0);
}
