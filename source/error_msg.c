/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirfatt <amirfatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:46:21 by amirfatt          #+#    #+#             */
/*   Updated: 2023/12/11 16:52:31 by amirfatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	error_messages(int option, t_data *game)
{
	ft_putstr_fd("ERROR...\n", 2);
	if (option == BER)
		ft_putstr_fd(".ber file not provided\n", 2);
	if (option == STRUCT)
		ft_putstr_fd("Failed to allocate game struct\n", 2);
	if (option == FD)
		ft_putstr_fd("Failed to open file descriptor\n", 2);
	if (option == GNL)
		ft_putstr_fd("Failed to read line\n", 2);
	if (option == BUFFER)
		ft_putstr_fd("Failed to allocate memory for buffer\n", 2);
	if (option == MAP_ERR)
		ft_putstr_fd(".....Game Map could not be created\n", 2);
	if (option == RECT)
		ft_putstr_fd("Game Map is not a rectangle\n", 2);
	if (option == WALL_ERR)
		ft_putstr_fd("Game Map top/bottom wall is incorrect\n", 2);
	if (option == WALL_ERR2)
		ft_putstr_fd("Left/Right Wall is incorrect\n", 2);
	if (option == ELEMENTS)
		ft_putstr_fd("Player/Exit/Collectable too much/little/missing\n", 2);
	if (option == WHITESPACES)
		ft_putstr_fd("Whitespace/Unknown characters in map detected\n", 2);
	error_messages_two(option, game);
	exit_game(game);
}

void	error_messages_two(int opt, t_data *game)
{
	if (opt == COPY_ERR)
		ft_putstr_fd("Failed to allocate memory for map **copy\n", 2);
	if (opt == COPY_ERR2)
		ft_putstr_fd("Failed to allocate memory for map copy[i]\n", 2);
	if (opt == COPY_ERR3)
		ft_putstr_fd("Failed to create map copy\n", 2);
	if (opt == INVALID_MAP)
		ft_putstr_fd("Map is not sufficiently playable\n", 2);
	if (opt == MLX_ERR)
		ft_putstr_fd("Failed to initialise mlx_ptr\n", 2);
	if (opt == STRUCT_IMG)
		ft_putstr_fd("Failed to allocate game->images struct\n", 2);
	if (opt == IMG_PTR)
		ft_putstr_fd("Failed to process XPM_TO_IMG\n", 2);
	if (opt == WIN_PTR)
		ft_putstr_fd("Failed to allocate win_ptr\n", 2);
	if (opt == NULL_PTR)
		ft_putstr_fd("Detected a NULL ptr\n", 2);
	exit_game(game);
}

void	win_game(int y, int x, char c, t_data *game)
{
	if (c == 'E')
	{
		if (game->collect == 0)
		{
			ft_printf("\n-----------YOU WON-----------\n");
			exit_game(game);
		}
		else
		{
			game->map[y][x] = 'P';
			game->hidden_exit = true;
			game->p_pos_y = y;
			game->p_pos_x = x;
			game->moves++;
		}
	}
}
