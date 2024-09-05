/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maustel <maustel@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 18:37:10 by maustel           #+#    #+#             */
/*   Updated: 2024/05/30 18:41:52 by maustel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	img_to_window(t_setup *game, mlx_image_t *img, int x, int y)
{
	mlx_resize_image(img, BITS, BITS);
	if (mlx_image_to_window(game->mlx, img, BITS * x, BITS * y) < 0)
		free_exit(game, 1);
}

void	init_window(t_setup *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->player->map[y])
	{
		x = 0;
		while (game->player->map[y][x])
		{
			img_to_window(game, game->img->f, x, y);
			if (game->player->map[y][x] == '1')
				img_to_window(game, game->img->w, x, y);
			if (game->player->map[y][x] == 'C')
				img_to_window(game, game->img->c, x, y);
			if (game->player->map[y][x] == 'P')
				img_to_window(game, game->img->p, x, y);
			if (game->player->map[y][x] == 'E')
				img_to_window(game, game->img->e, x, y);
			x++;
		}
		y++;
	}
}

int	get_size_map(t_pos *item)
{
	int	height;
	int	width;

	height = 0;
	width = ft_strlen(item->map[height]);
	while (item->map[height])
	{
		if (ft_strlen(item->map[height]) != (size_t) width)
			return (0);
		height++;
	}
	item->x = width;
	item->y = height;
	return (height);
}
