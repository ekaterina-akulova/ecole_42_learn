/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaderric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 00:34:47 by gaderric          #+#    #+#             */
/*   Updated: 2022/02/02 00:34:50 by gaderric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr_bonus/so_long.h"

void	enemy_looking(t_game *game, int row, int col)
{
	if (game->map->map[row + 1][col] == 'P')
	{
		game->map->map[row][col] = '0';
		game->map->map[row + 1][col] = 'D';
	}
	else if (game->map->map[row - 1][col] == 'P')
	{
		game->map->map[row][col] = '0';
		game->map->map[row - 1][col] = 'D';
	}
	else if (game->map->map[row][col + 1] == 'P')
	{
		game->map->map[row][col] = '0';
		game->map->map[row][col + 1] = 'D';
	}
	else if (game->map->map[row][col - 1] == 'P')
	{
		game->map->map[row][col] = '0';
		game->map->map[row][col - 1] = 'D';
	}
}

static int	ft_is_move_ok2(t_game *game, int row, int col)
{
	if ((game->map->map[row - 1][col] == 'D') || \
			(game->map->map[row + 1][col] == 'D') || \
			(game->map->map[row][col - 1] == 'D') || \
			(game->map->map[row][col + 1] == 'D'))
	{
		if (game->map->map[row - 1][col] == 'D')
		{
			game->map->map[row - 1][col] = '0';
			verify_char(row - 1, col, game->map->map[row - 1][col], game);
		}
		if (game->map->map[row + 1][col] == 'D')
		{
			game->map->map[row + 1][col] = '0';
			verify_char(row + 1, col, game->map->map[row + 1][col], game);
		}
		if (game->map->map[row][col - 1] == 'D')
			game->map->map[row][col - 1] = '0';
		if (game->map->map[row][col + 1] == 'D')
			game->map->map[row][col + 1] = '0';
		return (2);
	}
	return (0);
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
	else if (game->map->map[row][col] == 'E' && game->all_collect == 0)
	{
		game->end = 1;
		return (3);
	}
	else if (game->map->map[row][col] == 'E')
	{
		write(2, "You didn't collect all the collectibles\n", 41);
		return (-1);
	}
	else if (ft_is_move_ok2(game, row, col) == 2)
		return (2);
	if (keycode != 13 && keycode != 0 && keycode != 1 && keycode != 2)
		return (-1);
	return (1);
}

void	ft_moves(t_game *game, int line, int col, int keycode)
{
	int		valid;
	int		height;
	int		width;

	height = game->player->pos_x;
	width = game->player->pos_y;
	valid = ft_is_move_ok(game, line, col, keycode);
	if (valid != -1)
	{
		game->map->map[height][width] = '0';
		ft_moves2(game, line, col);
	}
	if (valid == 2)
	{
		enemy_looking(game, height, width);
		write(1, "YOU LOSE! The enemy ate you.\n: ", 29);
		free_all(game);
	}
	if (valid == 3)
	{
		game->map->map[height][width] = '0';
		verify_char(line, col, game->map->map[line][col], game);
		printf("YOU WIN! Your movement's count: %d\n", game->moves);
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
