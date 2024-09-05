/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maustel <maustel@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 12:53:20 by maustel           #+#    #+#             */
/*   Updated: 2024/05/30 18:34:43 by maustel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		ft_printf("%s\n", map[i]);
		i++;
	}
	write(1, "\n", 1);
}

int	read_file(char *map_name, t_setup *game)
{
	int		fd;
	char	*line;
	char	*temp;

	line = NULL;
	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		return (0);
	game->map = ft_strdup("");
	if (!game->map)
		return (0);
	line = get_next_line(fd);
	while (line)
	{
		temp = game->map;
		game->map = ft_strjoin(temp, line);
		free(temp);
		free(line);
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	if (close(fd) == -1)
		return (0);
	return (1);
}

void	parsing(char *map_name, t_setup *game)
{
	char	*errmsg;

	errmsg = NULL;
	game->map = NULL;
	game->player = NULL;
	if (!read_file(map_name, game))
	{
		ft_printf("\033[31;1mError\nFile not found!\033[0m");
		free_exit(game, 1);
	}
	game->player = malloc(sizeof(t_pos));
	if (!game->player)
		free_exit(game, 1);
	game->player->map = ft_split(game->map, '\n');
	if (!game->player->map)
		free_exit(game, 1);
	errmsg = check_map(game);
	if (errmsg)
	{
		ft_printf("\033[31;1mError\033[0m\n%s", errmsg);
		free_exit(game, 1);
	}
}
