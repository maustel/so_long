/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maustel <maustel@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:00:46 by maustel           #+#    #+#             */
/*   Updated: 2024/06/06 17:28:39 by maustel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_txt_null(t_setup *game)
{
	game->texture->p = NULL;
	game->texture->e = NULL;
	game->texture->e_o = NULL;
	game->texture->c = NULL;
	game->texture->w = NULL;
	game->texture->f = NULL;
}

void	init_textures(t_setup *game)
{
	game->texture = malloc (sizeof(t_txt));
	if (!game->texture)
		free_exit(game, 1);
	set_txt_null(game);
	game->texture->p = mlx_load_png(PLAYER);
	if (!game->texture->p)
		free_exit(game, 1);
	game->texture->e = mlx_load_png(EXIT);
	if (!game->texture->e)
		free_exit(game, 1);
	game->texture->e_o = mlx_load_png(EXIT_O);
	if (!game->texture->e_o)
		free_exit(game, 1);
	game->texture->c = mlx_load_png(COIN);
	if (!game->texture->c)
		free_exit(game, 1);
	game->texture->w = mlx_load_png(WALL);
	if (!game->texture->w)
		free_exit(game, 1);
	game->texture->f = mlx_load_png(FLOOR);
	if (!game->texture->f)
		free_exit(game, 1);
}

void	set_img_null(t_setup *game)
{
	game->img->p = NULL;
	game->img->e = NULL;
	game->img->e_o = NULL;
	game->img->c = NULL;
	game->img->w = NULL;
	game->img->f = NULL;
}

int	init_imgs(t_setup *game)
{
	game->img = malloc (sizeof(t_img));
	if (!game->img)
		free_exit(game, 1);
	set_img_null(game);
	game->img->p = mlx_texture_to_image(game->mlx, game->texture->p);
	if (!game->img->p)
		free_exit(game, 1);
	game->img->e = mlx_texture_to_image(game->mlx, game->texture->e);
	if (!game->img->e)
		free_exit(game, 1);
	game->img->e_o = mlx_texture_to_image(game->mlx, game->texture->e_o);
	if (!game->img->e_o)
		free_exit(game, 1);
	game->img->c = mlx_texture_to_image(game->mlx, game->texture->c);
	if (!game->img->c)
		free_exit(game, 1);
	game->img->w = mlx_texture_to_image(game->mlx, game->texture->w);
	if (!game->img->w)
		free_exit(game, 1);
	game->img->f = mlx_texture_to_image(game->mlx, game->texture->f);
	if (!game->img->f)
		free_exit(game, 1);
	return (1);
}

void	init(t_setup *game)
{
	int		x;
	int		y;

	game->player->moves = 0;
	game->ex = malloc(sizeof(t_pos));
	if (!game->ex)
		free_exit(game, 1);
	game->ex->map = game->player->map;
	get_position(game->ex, 'E');
	game->ex->open = 0;
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	get_size_map(game->player);
	x = game->player->x;
	y = game->player->y;
	game->mlx = mlx_init(x * BITS, y * BITS, "so_long", true);
	if (!game->mlx)
		free_exit(game, 1);
	init_textures(game);
	init_imgs(game);
	get_position(game->player, 'P');
}
