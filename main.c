/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maustel <maustel@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 10:52:22 by maustel           #+#    #+#             */
/*   Updated: 2024/06/06 17:28:47 by maustel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	leaks(void) //remove
// {
// 	// system("leaks so_long");
// 	print_leaks();
// 	// show_alloc_mem_ex();
// }
// 	atexit(leaks); // remove

int	error_msg_input(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_printf("\033[31;1mWrong amount of arguments!\033[0m\n");
		return (0);
	}
	if (ft_strlen(argv[1]) <= 4)
	{
		ft_printf("\033[31;1mWrong input!\033[0m\n");
		return (0);
	}
	if (!ft_strnstr(&argv[1][ft_strlen(argv[1]) - 4], ".ber", 4))
	{
		ft_printf("\033[31;1mInputfile not ending with .ber\033[0m\n");
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_setup	*game;

	game = NULL;
	if (!error_msg_input(argc, argv))
		return (1);
	game = malloc (sizeof(t_setup));
	if (!game)
		free_exit(game, 1);
	game->mlx = NULL;
	game->texture = NULL;
	game->img = NULL;
	game->ex = NULL;
	parsing(argv[1], game);
	init(game);
	init_window(game);
	mlx_key_hook(game->mlx, &my_keyhook, game);
	mlx_loop(game->mlx);
	free_exit(game, 0);
	return (0);
}
