/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_man.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaderric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 00:36:06 by gaderric          #+#    #+#             */
/*   Updated: 2022/02/02 00:36:07 by gaderric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_MAN_H
# define SO_LONG_MAN_H

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include "../my_libft/libft.h"
# include "../get_next_line/get_next_line_bonus.h"
# include <sys/fcntl.h>
# include <stdio.h>

typedef struct s_map
{
	char			**map;
	int				width;
	int				height;
	char			*type;
	char			*orig_type;
	int				position;
	struct s_map	*up;
	struct s_map	*down;
	struct s_map	*left;
	struct s_map	*right;
}				t_map;

typedef struct s_player
{
	t_map	*map;
	int		pos_x;
	int		pos_y;
}				t_player;

typedef struct s_textures
{
	void	*img;
	int		width;
	int		height;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
}				t_textures;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			col;
	int			row;
	t_map		*map;
	t_player	*player;
	int			end;
	int			collect;
	int			exit;
	int			is_collect;
	int			f_collect;
	int			all_collect;
	int			free_space;
	int			moves;
	t_textures	*door_open_img;
	t_textures	*door_close_img;
	t_textures	*wall;
	t_textures	*foreground;
	t_textures	*player1;
	t_textures	*fire;
}				t_game;

void		verify_char(int line, int col, char c, t_game *game);
int			free_all(t_game *game);
int			ft_what_key(int keycode, t_game *game);
void		ft_moves(t_game *game, int line, int col, int keycode);
int			is_there_walls_1(char **map, int index);
int			is_there_walls_2(char **map, int index);
void		ft_init_struct(t_game *game);
int			check_map_letters(char **map);
int			check_lines(char **map);
int			is_map_ok(t_game *game);
int			is_map_ok2(t_game *game);
void		print_map(t_game vars);
int			render_img(t_game *game);
void		render_img2(t_game *game);
void		map_moves(t_game *game, char *path);
t_textures	*ft_new_sprite(void *mlx, char *path);

#endif
