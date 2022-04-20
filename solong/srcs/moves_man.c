/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_man.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaderric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 18:31:06 by gaderric          #+#    #+#             */
/*   Updated: 2022/02/02 00:39:39 by gaderric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by Gail Derrick on 1/31/22.
//

#include "../hdr/so_long_man.h"

static int	ft_norma_checks_exits(t_game *game, int row, int col)
{
	if (game->map->map[row][col] == 'E' && game->all_collect == 0)
	{
		game->end = 1;
		return (3);
	}
	else if (game->map->map[row][col] == 'E')
	{
		write(2, "You didn't collect all the collectibles\n", 41);
		return (-1);
	}
	return (1);
}

static int	ft_is_move_ok(t_game *game, int row, int col, int keycode)
{
	if (game->map->map[row][col] == '1')
	{
		write(2, "You can not move on the walls\n", 31);
		return (-1);
	}
	else if (game->map->map[row][col] == 'C')
	{
		game->collect = game->all_collect - 1;
		game->all_collect--;
	}
	else if ((ft_norma_checks_exits(game, row, col) == -1))
		return (-1);
	else if ((ft_norma_checks_exits(game, row, col) == 3))
		return (3);
	if (game->map->map[row][col] != 'E' && game->map->map[row][col] != 'P' \
	&& game->map->map[row][col] != '0' && game->map->map[row][col] != 'C')
		return (-1);
	if (keycode != 13 && keycode != 0 && keycode != 1 && keycode != 2)
		return (-1);
	else
		return (1);
}

void	ft_moves(t_game *game, int line, int col, int keycode)
{
	int	valid;
	int	height;
	int	width;

	height = game->player->pos_x;
	width = game->player->pos_y;
	valid = ft_is_move_ok(game, line, col, keycode);
	if (valid != -1)
	{
		game->map->map[height][width] = '0';
		game->player->pos_x = line;
		game->player->pos_y = col;
		game->map->map[line][col] = 'P';
		game->moves++;
		printf("Movements: %d\n", game->moves);
	}
	if (valid == 3)
	{
		verify_char(line, col, game->map->map[line][col], game);
		write(1, "YOU WIN! Your movement's count: ", 33);
		ft_putnbr_fd(game->moves, 1);
	}
}

int	ft_what_key(int keycode, t_game *game)
{
	int	line;
	int	width;

	line = game->player->pos_x;
	width = game->player->pos_y;
	if (keycode == 13)
		line--;
	else if (keycode == 0)
		width--;
	else if (keycode == 1)
		line++;
	else if (keycode == 2)
		width++;
	else if (keycode == 53)
		free_all(game);
	else
		return (0);
	if (game->end != 1)
		ft_moves(game, line, width, keycode);
	if (game->end == 1)
	{
		render_img(game);
		free_all(game);
	}
	return (1);
}
