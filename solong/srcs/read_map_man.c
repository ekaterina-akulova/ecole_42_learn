/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_man.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaderric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 00:39:11 by gaderric          #+#    #+#             */
/*   Updated: 2022/02/02 00:43:32 by gaderric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/so_long_man.h"

static void	verify_char2(int line, int col, char c, t_game *game)
{
	if (c == 'E')
	{
		game->exit++;
		mlx_put_image_to_window(game->mlx, game->win, \
		game->foreground->img, col * 32, line * 32);
		mlx_put_image_to_window(game->mlx, game->win, \
		game->door_open_img->img, col * 32, line * 32);
	}
	else if (c == 'C')
	{
		game->is_collect++;
		mlx_put_image_to_window(game->mlx, game->win, \
		game->foreground->img, col * 32, line * 32);
		mlx_put_image_to_window(game->mlx, game->win, \
		game->fire->img, col * 32, line * 32);
	}
	else if (c != 'C' && c != 'E' && c != 'P' && c != '0' && c != '1')
	{
		write(1, "Wrong symbol on your map\n", 26);
		exit(-1);
	}
}

void	verify_char(int line, int col, char c, t_game *game)
{
	if (c == '1')
	{
		mlx_put_image_to_window(game->mlx, game->win, \
		game->foreground->img, col * 32, line * 32);
		mlx_put_image_to_window(game->mlx, game->win, \
		game->wall->img, col * 32, line * 32);
	}
	else if (c == '0')
		mlx_put_image_to_window(game->mlx, game->win, \
		game->foreground->img, col * 32, line * 32);
	else if (c == 'P')
	{
		mlx_put_image_to_window(game->mlx, game->win, \
		game->foreground->img, col * 32, line * 32);
		mlx_put_image_to_window(game->mlx, game->win, \
		game->player1->img, col * 32, line * 32);
		if (game->end == 1)
			mlx_put_image_to_window(game->mlx, game->win, \
			game->door_close_img->img, col * 32, line * 32);
		game->player->pos_y = col;
		game->player->pos_x = line;
	}
	verify_char2(line, col, c, game);
}

int	render_img(t_game *game)
{
	int	line;
	int	col;

	col = 0;
	while (game->map->map[col])
	{
		line = 0;
		while (game->map->map[col][line])
		{
			if (game->f_collect == 0 && game->map->map[col][line] == 'C')
				game->all_collect++;
			verify_char(col, line, game->map->map[col][line], game);
			line++;
		}
		col++;
	}
	render_img2(game);
	return (0);
}

void	print_map(t_game vars)
{
	vars.win = mlx_new_window(vars.mlx, 32 * vars.col, \
		32 * vars.row, "so long");
	vars.foreground = ft_new_sprite(vars.mlx, \
		"./images/foreground.xpm");
	vars.wall = ft_new_sprite(vars.mlx, "./images/wall.xpm");
	vars.player1 = ft_new_sprite(vars.mlx, "./images/enemy.xpm");
	vars.fire = ft_new_sprite(vars.mlx, "./images/fire.xpm");
	vars.door_open_img = ft_new_sprite(vars.mlx, "./images/door_open.xpm");
	vars.door_close_img = ft_new_sprite(vars.mlx, "./images/door_closed.xpm");
	mlx_loop_hook(vars.mlx, render_img, &vars);
	mlx_hook(vars.win, 17, 1, free_all, &vars);
	mlx_key_hook(vars.win, ft_what_key, &vars);
	mlx_loop(vars.mlx);
	free_all(&vars);
	if (vars.end == 1)
	{
		render_img(&vars);
		free_all(&vars);
	}
}

void	map_moves(t_game *game, char *path)
{
	int		fd;
	char	*line;
	char	*temp;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		write(2, "Open failed on input file\n", 26);
		exit(-10);
	}
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		temp = ft_strjoin(temp, line);
		game->row++;
		free(line);
	}
	game->map->map = ft_split(temp, '\n');
	game->col = ((int)ft_strlen(game->map->map[0]));
	close(fd);
	free(temp);
	free(line);
}
