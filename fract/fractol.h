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

#ifndef FRACTOL_H
# define FRACTOL_H
# include "mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# define WIDTH 1280
# define HEIGHT 720
# define SCALE 800
# define ITERATIONS 100

typedef struct s_data {
	void		*img;
	void		*img2;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	double		x;
	double		y;
	double		x0;
	double		y0;
	double		v;
	int			map;
	int			n;
	int			k;
	int			l;
	int			max_iterations;
	long double	mx;
	long double	my;
	long double	x_temp;
	double		zoom_factor;
	int			shift_factor;
	double		current_x;
	double		mouse_x;
	double		current_y;
	double		mouse_y;
	double		x1;
	double		y1;
}				t_data;

typedef struct s_vars {
	void	*mlx;
	void	*window;
	t_data	mlx_img;
	t_data	*imgs;
}				t_vars;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		close(int keycode, t_vars *vars);
int		render_next_frame(void *vars);
int		render_square(int x, int y, t_data *img);
void	render_background(t_data *img);
int		mandelbrot_placeholder(t_data *img);
int		julia_placeholder(t_data *img);
int		julia_mouse_hover(int x, int y, t_vars *vars);
int		color_iteration(int n, t_data *img);
int		mouse_zoom(int keycode, int x, int y, t_vars *vars);
void	fractal_draw(t_data img);
void	check_start(int argc, char **argv);
t_data	params(char **argv, t_data img);
void	draw_params(char **argv, t_data *img);
void	escape(t_vars *vars);
void	coloring_orbits_mandelbrot(t_data *img);
void	coloring_orbits_julia(t_data *img);
double	ft_atof(const char *str);
int		ft_start(const char *str, int *j);
double	ft_double_count(const char *str, int i, double k);
int		ft_strcmp(const char *s1, const char *s2);
#endif