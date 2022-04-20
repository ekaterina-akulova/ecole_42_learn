/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaderric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 00:34:22 by gaderric          #+#    #+#             */
/*   Updated: 2022/02/02 00:34:24 by gaderric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by Gail Derrick on 1/26/22.
//
#include "../hdr_bonus/so_long.h"

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->row)
		free(game->map->map[i++]);
	free(game->map->map[i]);
}

int	free_all(t_game *game)
{
	ft_init_struct(game);
	mlx_destroy_image(game->mlx, game->foreground->img);
	mlx_destroy_image(game->mlx, game->player1->img);
	mlx_destroy_image(game->mlx, game->player2->img);
	mlx_destroy_image(game->mlx, game->player3->img);
	mlx_destroy_image(game->mlx, game->player4->img);
	mlx_destroy_image(game->mlx, game->enemy->img);
	mlx_destroy_image(game->mlx, game->wall->img);
	mlx_destroy_image(game->mlx, game->door_open_img->img);
	mlx_destroy_image(game->mlx, game->door_close_img->img);
	mlx_destroy_window(game->mlx, game->win);
	free_map(game);
	free(game->mlx);
	exit(-1);
	return (0);
}
