/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirfatt <amirfatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 10:48:08 by amirfatt          #+#    #+#             */
/*   Updated: 2023/12/11 16:02:11 by amirfatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	map_checker(t_data *game)
{
	if (game->map == NULL)
	{
		error_messages(MAP_ERR, game);
	}
	check_rectangle(game);
	check_border(game);
	check_elements(game);
	check_valid_path(game);
}

void	check_file_extension(t_data *game, char *argv)
{
	if (ft_strlen(argv) <= 4 || ft_strncmp(argv + ft_strlen(argv) - 4, ".ber",
			4) != 0)
		error_messages(BER, game);
}

void	init_win_ptr(t_data *game)
{
	int		size_x;
	int		size_y;
	void	*mlx;

	mlx = game->mlx_ptr;
	size_x = game->images->pixel * game->x;
	size_y = game->images->pixel * game->y;
	game->win_ptr = mlx_new_window(mlx, size_x, size_y, "KEYS TO NOTHING");
	if (!game->win_ptr)
		error_messages(WIN_PTR, game);
}

void	creation_map(t_data *game, char *argv)
{
	get_count_map(game, argv);
	create_map(game, argv);
	map_checker(game);
}

int	main(int argc, char **argv)
{
	t_data	*game;

	if (argc == 2)
	{
		check_file_extension(NULL, argv[1]);
		game = malloc(sizeof(t_data));
		if (!game)
			error_messages(STRUCT, game);
		ft_memset(game, 0, sizeof(t_data));
		creation_map(game, argv[1]);
		game->mlx_ptr = mlx_init();
		if (!game->mlx_ptr)
			error_messages(MLX_ERR, game);
		init_ptr(game);
		init_win_ptr(game);
		put_update_graphics(game);
		mlx_hook(game->win_ptr, KeyPress, KeyPressMask, handle_user_input,
			game);
		mlx_hook(game->win_ptr, DestroyNotify, NoEventMask, close_window, game);
		mlx_loop(game->mlx_ptr);
	}
	else
		ft_printf("Usage: ./program .ber-file");
	return (0);
}
