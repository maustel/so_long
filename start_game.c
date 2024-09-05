/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maustel <maustel@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 13:03:35 by maustel           #+#    #+#             */
/*   Updated: 2024/05/30 18:46:53 by maustel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_for_coins(t_setup *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->player->map[i])
	{
		j = 0;
		while (game->player->map[i][j])
		{
			if (game->player->map[i][j] == 'C')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	change_position(t_setup *game, int x, int y)
{
	if (x > 0 && y > 0 && game->player->map[y][x] != '1')
	{
		img_to_window(game, game->img->f, game->player->x, game->player->y);
		if (game->player->map[game->player->y][game->player->x] == 'E')
			img_to_window(game, game->img->e, game->player->x, game->player->y);
		game->player->x = x;
		game->player->y = y;
		if (game->player->map[y][x] == 'C')
		{
			game->player->map[y][x] = '0';
			if (!check_for_coins(game))
			{
				game->ex->open = 1;
				img_to_window(game, game->img->e_o, game->ex->x, game->ex->y);
			}
			img_to_window(game, game->img->f, game->player->x, game->player->y);
		}
		img_to_window(game, game->img->p, game->player->x, game->player->y);
		ft_printf("Number of movements: %d\n", ++game->player->moves);
		if (game->player->map[game->player->y][game->player->x] == 'E')
		{
			if (game->ex->open)
				free_exit(game, 0);
		}
	}
}

void	move_player(t_setup *game, int direction)
{
	if (direction == UP)
		change_position(game, game->player->x, game->player->y - 1);
	if (direction == RIGHT)
		change_position(game, game->player->x + 1, game->player->y);
	if (direction == DOWN)
		change_position(game, game->player->x, game->player->y + 1);
	if (direction == LEFT)
		change_position(game, game->player->x - 1, game->player->y);
}

void	my_keyhook(mlx_key_data_t keydata, void *game)
{
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		free_exit(game, 0);
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		move_player(game, DOWN);
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		move_player(game, UP);
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		move_player(game, RIGHT);
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		move_player(game, LEFT);
}
