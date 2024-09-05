/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maustel <maustel@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 12:42:46 by maustel           #+#    #+#             */
/*   Updated: 2024/05/30 18:23:12 by maustel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**cpy_2d_arr(t_pos *player, char **map_2d)
{
	char	**map_new;
	int		i;

	i = 0;
	while (map_2d[i])
		i++;
	map_new = malloc (sizeof(char *) * (i + 1));
	if (!map_new)
		return (NULL);
	i = 0;
	while (map_2d[i])
	{
		map_new[i] = ft_strdup(map_2d[i]);
		if (!map_new[i])
		{
			free_2darr(player, map_2d);
			return (NULL);
		}
		i++;
	}
	map_new[i] = NULL;
	return (map_new);
}

void	get_position(t_pos *player, char c)
{
	int		i;
	int		j;

	i = 0;
	while (player->map[i])
	{
		j = 0;
		while (player->map[i][j])
		{
			if (player->map[i][j] == c)
			{
				player->y = i;
				player->x = j;
			}
			j++;
		}
		i++;
	}
}

void	flood_fill(t_pos *player, int x, int y)
{
	if (player->map[y][x] == '1')
		return ;
	player->map[y][x] = '1';
	flood_fill(player, x, y + 1);
	flood_fill(player, x, y - 1);
	flood_fill(player, x + 1, y);
	flood_fill(player, x - 1, y);
}

int	check_path(char **map_2d)
{
	t_pos	*player;
	int		i;

	player = malloc(sizeof(t_pos));
	if (!player)
		return (0);
	player->map = cpy_2d_arr(player, map_2d);
	if (!player->map)
		return (0);
	get_position(player, 'P');
	flood_fill(player, player->x, player->y);
	i = 0;
	while (player->map[i])
	{
		if (ft_strchr(player->map[i], 'C') || (ft_strchr(player->map[i], 'E')))
		{
			free_2darr(player, player->map);
			return (0);
		}
		i++;
	}
	free_2darr(player, player->map);
	return (1);
}

int	check_rect(char **map_2d)
{
	int	height;
	int	width;

	width = ft_strlen(map_2d[0]);
	height = 1;
	while (map_2d[height])
	{
		if (ft_strlen(map_2d[height]) != (size_t) width)
			return (0);
		height++;
	}
	return (height);
}
