/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaderric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 00:35:13 by gaderric          #+#    #+#             */
/*   Updated: 2022/02/02 00:35:14 by gaderric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr_bonus/so_long.h"

int	main(int argc, char **argv)
{
	t_game	vars;

	if (argc != 2)
	{
		printf("Invalid number of arguments.\n");
		exit(-1);
	}
	if (ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])) == 0)
	{
		printf("You must use a '.ber' file.\n");
		exit(-1);
	}
	ft_init_struct(&vars);
	map_moves(&vars, argv[1]);
	if (is_map_ok(&vars) == 1)
	{
		vars.mlx = mlx_init();
		print_map(vars);
		free_all(&vars);
	}
	return (0);
}
