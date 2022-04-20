/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_man.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaderric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 19:20:21 by gaderric          #+#    #+#             */
/*   Updated: 2022/02/02 00:37:02 by gaderric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/so_long_man.h"

static void	norma_inits_and_exits(t_game vars)
{
	if (is_map_ok(&vars) == 1)
	{
		vars.mlx = mlx_init();
		print_map(vars);
		free_all(&vars);
	}
	else if (is_map_ok(&vars) == 0)
	{
		write(1, "Error\n", 7);
		exit(-1);
	}
}

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
	norma_inits_and_exits(vars);
	return (0);
}
