/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/* 2darr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maustel <maustel@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 10:51:25 by maustel           #+#    #+#             */
/*   Updated: 2024/05/30 10:53:58 by maustel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_2darr(t_pos *player, char **str)
{
	int	n;

	n = 0;
	if (str)
	{
		while (str[n])
		{
			free(str[n]);
			n++;
		}
		free (str);
	}
	if (player)
		free (player);
}

void	delete_textures(t_setup *game)
{
	if (game->texture->p)
		mlx_delete_texture(game->texture->p);
	if (game->texture->e)
		mlx_delete_texture(game->texture->e);
	if (game->texture->e_o)
		mlx_delete_texture(game->texture->e_o);
	if (game->texture->c)
		mlx_delete_texture(game->texture->c);
	if (game->texture->w)
		mlx_delete_texture(game->texture->w);
	if (game->texture->f)
		mlx_delete_texture(game->texture->f);
	free(game->texture);
}

void	delete_imgs(t_setup *game)
{
	if (game->img->p)
		mlx_delete_image(game->mlx, game->img->p);
	if (game->img->e)
		mlx_delete_image(game->mlx, game->img->e);
	if (game->img->e_o)
		mlx_delete_image(game->mlx, game->img->e_o);
	if (game->img->c)
		mlx_delete_image(game->mlx, game->img->c);
	if (game->img->w)
		mlx_delete_image(game->mlx, game->img->w);
	if (game->img->f)
		mlx_delete_image(game->mlx, game->img->f);
	free(game->img);
}

void	free_exit(t_setup *game, bool error)
{
	if (game)
	{
		if (game->map)
			free(game->map);
		if (game->texture)
			delete_textures(game);
		if (game->img)
			delete_imgs(game);
		if (game->mlx)
			mlx_terminate(game->mlx);
		if (game->player)
		{
			if (game->player->map)
				free_2darr(NULL, game->player->map);
			free(game->player);
		}
		if (game->ex)
			free(game->ex);
		free (game);
	}
	exit (error);
}
