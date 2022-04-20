/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaderric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 00:35:02 by gaderric          #+#    #+#             */
/*   Updated: 2022/02/02 00:35:03 by gaderric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by Gail Derrick on 1/20/22.
//

#include "../hdr_bonus/so_long.h"

void	verify_char(int line, int col, char c, t_game *game)
{
	if (c == '1')
	{
		mlx_put_image_to_window(game->mlx, game->win, \
		game->foreground->img, col * 32, line * 32);
		mlx_put_image_to_window(game->mlx, game->win, \
		game->wall->img, col * 32, line * 32);
	}
	else if (c == 'P')
	{
		mlx_put_image_to_window(game->mlx, game->win, \
		game->foreground->img, col * 32, line * 32);
		circle_player(line, col, game->frame / 10, game);
		game->frame--;
		if (game->frame == 9)
			game->frame = 40;
		if (game->end == 1)
		{
			mlx_put_image_to_window(game->mlx, game->win, \
			game->door_close_img->img, col * 32, line * 32);
		}
		game->player->pos_y = col;
		game->player->pos_x = line;
	}
	else
		verify_char2(line, col, c, game);
}

int	render_img(t_game *game)
{
	int		line;
	int		col;
	char	*move;

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
	move = ft_itoa(game->moves);
	mlx_string_put(game->mlx, game->win, 20, 10, 0xF0F8FF, \
	"Movement: ");
	mlx_string_put(game->mlx, game->win, 100, 10, 0xF0F8FF, move);
	free(move);
	return (0);
}

void	print_map(t_game vars)
{
	vars.win = mlx_new_window(vars.mlx, 32 * vars.col, \
	32 * vars.row, "so long");
	vars.foreground = ft_new_sprite(vars.mlx, \
	"./images/foreground.xpm");
	vars.wall = ft_new_sprite(vars.mlx, "./images/wall.xpm");
	vars.player1 = ft_new_sprite(vars.mlx, "./images/player1.xpm");
	vars.player2 = ft_new_sprite(vars.mlx, "./images/player2.xpm");
	vars.player3 = ft_new_sprite(vars.mlx, "./images/player3.xpm");
	vars.player4 = ft_new_sprite(vars.mlx, "./images/player4.xpm");
	vars.enemy = ft_new_sprite(vars.mlx, "./images/enemy.xpm");
	vars.fire = ft_new_sprite(vars.mlx, "./images/fire.xpm");
	vars.door_open_img = ft_new_sprite(vars.mlx, \
	"./images/door_open.xpm");
	vars.door_close_img = ft_new_sprite(vars.mlx, \
	"./images/door_closed.xpm");
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
		free(line);
		game->row++;
	}
	game->map->map = ft_split(temp, '\n');
	game->col = (int)ft_strlen(game->map->map[0]);
	close(fd);
	free(temp);
	free(line);
}
