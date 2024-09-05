/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maustel <maustel@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:31:34 by maustel           #+#    #+#             */
/*   Updated: 2024/06/06 15:45:59 by maustel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// # include "malloc.h"
# include <stdio.h>
# include "libft.h"
# include "get_next_line.h"
# include "./MLX42/include/MLX42/MLX42.h"

# define BITS	32

# define FLOOR	"./textures/grass2.png"
# define WALL	"./textures/tree.png"
# define COIN	"./textures/sun.png"
# define PLAYER	"./textures/pv.png"
# define EXIT	"./textures/grid.png"
# define EXIT_O	"./textures/current.png"

# define UP		1
# define RIGHT	2
# define DOWN	3
# define LEFT	4

typedef struct s_pos
{
	int		x;
	int		y;
	int		moves;
	char	**map;
	bool	open;
}				t_pos;

typedef struct s_txt
{
	mlx_texture_t	*p;
	mlx_texture_t	*e;
	mlx_texture_t	*e_o;
	mlx_texture_t	*c;
	mlx_texture_t	*w;
	mlx_texture_t	*f;
}				t_txt;

typedef struct s_img
{
	mlx_image_t		*p;
	mlx_image_t		*e;
	mlx_image_t		*e_o;
	mlx_image_t		*c;
	mlx_image_t		*w;
	mlx_image_t		*f;
}				t_img;

typedef struct s_setup
{
	mlx_t	*mlx;
	t_txt	*texture;
	t_img	*img;
	char	*map;
	t_pos	*player;
	t_pos	*ex;
}				t_setup;

void	parsing(char *map_name, t_setup *game);

char	*check_map(t_setup *game);
int		check_path(char **map_2d);
int		check_rect(char **map_2d);
void	get_position(t_pos *player, char c);

void	print_map(char **map);

void	init(t_setup *game);
int		get_size_map(t_pos *mapy);
void	init_window(t_setup *game);
void	img_to_window(t_setup *game, mlx_image_t *img, int x, int y);

void	my_keyhook(mlx_key_data_t keydata, void *game);

void	free_2darr(t_pos *player, char **str);
void	free_exit(t_setup *game, bool error);

#endif