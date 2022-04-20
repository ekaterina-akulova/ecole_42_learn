/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_norm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaderric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 00:31:11 by gaderric          #+#    #+#             */
/*   Updated: 2022/02/02 00:31:13 by gaderric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/so_long_man.h"

int	is_map_ok2(t_game *game)
{
	int	line;
	int	col;
	int	size;

	line = 0;
	size = (int)ft_strlen(game->map->map[0]);
	if (check_map_letters(game->map->map) == 0)
	{
		write(1, "The map should have 1 player\n", 42);
		exit(-1);
	}
	while (game->map->map[line] == 0)
	{
		col = (int)ft_strlen(game->map->map[line]);
		if (col != size)
		{
			write(1, "Your map is not rectangular!\n", 30);
			return (-1);
		}
		line++;
	}
	return (1);
}

void	ft_init_struct(t_game *game)
{
	game->end = 0;
	game->f_collect = 0;
	game->is_collect = 0;
	game->row = 0;
	game->col = 0;
	game->all_collect = 0;
	game->collect = 0;
	game->exit = 0;
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
