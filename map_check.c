/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maustel <maustel@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:31:04 by maustel           #+#    #+#             */
/*   Updated: 2024/09/05 11:14:42 by maustel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_walls(char **map_2d)
{
	int	i;
	int	j;
	int	width;

	i = 0;
	width = ft_strlen(map_2d[i]);
	while (map_2d[i])
	{
		j = 0;
		while (map_2d[i][j])
		{
			if (i == 0 || i == check_rect(map_2d) - 1)
			{
				if (map_2d[i][j] != '1')
					return (0);
			}
			if ((j == 0 || j == width - 1) && map_2d[i][j] != '1')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_epc(char *mapy)
{
	int	i;
	int	e;
	int	p;
	int	c;

	i = 0;
	e = 0;
	p = 0;
	c = 0;
	while (mapy[i])
	{
		if (mapy[i] == 'E')
			e++;
		if (mapy[i] == 'P')
			p++;
		if (mapy[i] == 'C')
			c++;
		i++;
	}
	if (e != 1 || p != 1 || c < 1)
		return (0);
	return (1);
}

int	check_char(char *mapy)
{
	int	i;

	i = 0;
	while (mapy[i])
	{
		if ((mapy[i] == '\n' && mapy[i + 1] == '\n') || (mapy[0] == '\n'))
			return (0);
		if (mapy[i] == '0' || mapy[i] == '1' || mapy[i] == 'C'
			|| mapy[i] == 'E' || mapy[i] == 'P' || mapy[i] == '\n')
			i++;
		else
			return (0);
	}
	return (1);
}

int	check_size(char **map_2d)
{
	int	i;
	int	j;

	i = 0;
	while (map_2d[i])
	{
		j = 0;
		while (map_2d[i][j])
			j++;
		i++;
	}
	if (i > 40 || j > 100)
		return (0);
	return (1);
}

char	*check_map(t_setup *game)
{
	if (game->map[0] == '\0')
		return ("\033[31;1mEmpty file!\033[0m\n");
	if (!check_rect(game->player->map))
		return ("\033[31;1mNot rectangular!\033[0m\n");
	if (!check_char(game->map))
		return ("\033[31;1mForbidden characters!\033[0m\n");
	if (!check_epc(game->map))
		return ("\033[31;1mWrong amount of 'E', 'P' or 'C'\033[0m\n");
	if (!check_walls(game->player->map))
		return ("\033[31;1mNot surrounded by walls!\033[0m\n");
	if (!check_path(game->player->map))
		return ("\033[31;1mInvalid Path!\033[0m\n");
	if (!check_size(game->player->map))
		return ("\033[31;1mMap too big!\033[0m\n");
	return (NULL);
}
