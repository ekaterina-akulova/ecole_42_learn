/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_norm2_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaderric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 00:35:38 by gaderric          #+#    #+#             */
/*   Updated: 2022/02/02 00:35:40 by gaderric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr_bonus/so_long.h"

void	render_img2(t_game *game)
{
	if (game->f_collect == 0)
		game->f_collect++;
	if (game->is_collect == 0)
	{
		write(1, "You need at least 1 collectible on your map.\n", 46);
		exit(-1);
	}
	if (game->exit == 0)
	{
		write(1, "You need at least 1 exit on your map.\n", 39);
		exit(-1);
	}
}

static void	verify_char3(int line, int col, char c, t_game *game)
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
	else
	{
		write(1, "There should be only P, E, 1, 0, C or D\n", 40);
		exit(-1);
	}
}

void	verify_char2(int line, int col, char c, t_game *game)
{
	if (c == '0')
		mlx_put_image_to_window(game->mlx, game->win, \
		game->foreground->img, col * 32, line * 32);
	else if (c == 'D')
	{
		mlx_put_image_to_window(game->mlx, game->win, \
		game->foreground->img, col * 32, line * 32);
		enemy_moving(col, line, game->frame2 / 100, game);
		game->frame2--;
		if (game->frame2 == 9)
			game->frame2 = 400;
	}
	else if (game->end == 1)
	{
		mlx_put_image_to_window(game->mlx, game->win, \
		game->door_close_img->img, col * 32, line * 32);
	}
	else
		verify_char3(line, col, c, game);
}

void	ft_moves2(t_game *game, int line, int col)
{
	game->player->pos_x = line;
	game->player->pos_y = col;
	game->map->map[line][col] = 'P';
	game->moves++;
	mlx_string_put(game->mlx, game->win, 20, 10, 0xF0F8FF, \
	"Movement: ");
	mlx_string_put(game->mlx, game->win, 100, 10, 0xF0F8FF, \
	ft_itoa(game->moves));
	printf("Movements: %d\n", game->moves);
}
