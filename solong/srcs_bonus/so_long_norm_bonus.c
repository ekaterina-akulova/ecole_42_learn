/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_norm_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaderric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 00:35:26 by gaderric          #+#    #+#             */
/*   Updated: 2022/02/02 00:35:28 by gaderric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr_bonus/so_long.h"

int	is_map_ok2(t_game *game)
{
	int	col;
	int	line;
	int	size;

	line = 0;
	size = (int)ft_strlen(game->map->map[0]);
	if (check_map_letters(game->map->map) == 0)
	{
		write(1, "The map should have 1 player and enemies\n", 42);
		exit(-1);
	}
	while (game->map->map[line] != 0)
	{
		col = (int)ft_strlen(game->map->map[line]);
		if (col != size)
		{
			write(1, "Your map is not rectangular!\n", 29);
			exit(-1);
		}
		line++;
	}
	return (1);
}

void	ft_init_struct(t_game *game)
{
	game->end = 0;
	game->frame = 40;
	game->frame2 = 400;
	game->f_collect = 0;
	game->exit = 0;
	game->is_collect = 0;
	game->row = 0;
	game->col = 0;
	game->all_collect = 0;
	game->collect = 0;
	game->free_space = 0;
	game->moves = 0;
	game->player = ft_calloc(1, sizeof(t_player));
	game->map = ft_calloc(1, sizeof(t_map));
	game->map->map = ft_calloc(1, sizeof(char **));
}

t_textures	*ft_new_sprite(void *mlx, char *path)
{
	t_textures	*img;

	img = (t_textures *) ft_calloc(1, sizeof(t_textures));
	img->img = mlx_xpm_file_to_image(mlx, path, &img->height, &img->width);
	return (img);
}

void	enemy_moving(int col, int line, int x, t_game *game)
{
	int	q;
	int	y;
	int	z;

	q = col - 1;
	y = line - 1;
	z = col + 1;
	if (x == 3)
		mlx_put_image_to_window(game->mlx, game->win, \
		game->enemy->img, col * 32, line * 32);
	else if (x == 1)
		mlx_put_image_to_window(game->mlx, game->win, \
		game->enemy->img, z * 32, y * 32);
	else if (x == 2)
		mlx_put_image_to_window(game->mlx, game->win, \
		game->enemy->img, q * 32, y * 32);
	else if (x == 0)
		mlx_put_image_to_window(game->mlx, game->win, \
		game->enemy->img, col * 32, line * 32);
}

void	circle_player(int line, int col, int x, t_game *game)
{
	if (x == 4)
		mlx_put_image_to_window(game->mlx, game->win, \
		game->player2->img, col * 32, line * 32);
	else if (x == 3)
		mlx_put_image_to_window(game->mlx, game->win, \
		game->player3->img, col * 32, line * 32);
	else if (x == 2)
		mlx_put_image_to_window(game->mlx, game->win, \
		game->player4->img, col * 32, line * 32);
	else if (x == 1)
		mlx_put_image_to_window(game->mlx, game->win, \
		game->player1->img, col * 32, line * 32);
}
