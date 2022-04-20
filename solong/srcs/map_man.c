/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_man.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaderric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 00:30:23 by gaderric          #+#    #+#             */
/*   Updated: 2022/02/02 00:30:25 by gaderric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/so_long_man.h"

int	is_there_walls_1(char **map, int index)
{
	int	i;

	i = 0;
	while (map[index][i])
	{
		if (map[index][i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	is_there_walls_2(char **map, int index)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i][index] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_map_letters(char **map)
{
	int	i;
	int	j;
	int	p;

	p = 0;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
			if (map[i][j] == 'P')
				p++;
	}
	if (p == 1)
		return (1);
	return (0);
}

int	check_lines(char **map)
{
	int		i;
	size_t	len;

	len = ft_strlen(map[0]);
	i = 1;
	while (map[i])
	{
		if (ft_strlen(map[i]) != len)
			return (0);
		i++;
	}
	return (1);
}

int	is_map_ok(t_game *game)
{
	if ((!is_there_walls_1(game->map->map, 0)) || \
		(!is_there_walls_1(game->map->map, game->row - 1)) || \
		(!is_there_walls_2(game->map->map, 0)) || \
		(!is_there_walls_2(game->map->map, \
	(int)ft_strlen(game->map->map[0]) - 1)) \
	|| !check_lines(game->map->map))
	{
		write(1, "Surround your map with walls!\n", 31);
		exit(-1);
	}
	return (is_map_ok2(game));
}
