/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirfatt <amirfatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:42:20 by amirfatt          #+#    #+#             */
/*   Updated: 2023/12/04 17:32:26 by amirfatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	valid_move(int y, int x, t_data *game)
{
	if (game->map[y][x] == '1')
		return (0);
	if (game->map[y][x] == '0')
	{
		game->map[y][x] = 'P';
		game->p_pos_y = y;
		game->p_pos_x = x;
		game->moves++;
	}
	else if (game->map[y][x] == 'C')
	{
		game->map[y][x] = 'P';
		game->p_pos_y = y;
		game->p_pos_x = x;
		game->collect--;
		game->moves++;
	}
	else if (game->map[y][x] == 'E')
		win_game(y, x, game->map[y][x], game);
	print_movements(game);
	return (1);
}

int	move_player_up_down(int keycode, t_data *game)
{
	int	i;
	int	j;

	i = game->p_pos_y;
	j = game->p_pos_x;
	if (keycode == KEY_W)
	{
		i--;
		if (valid_move(i, j, game))
			game->map[i + 1][j] = '0';
		else
			return (0);
	}
	else if (keycode == KEY_S)
	{
		i++;
		if (valid_move(i, j, game))
			game->map[i - 1][j] = '0';
		else
			return (0);
	}
	return (1);
}

int	move_payer_left_right(int keycode, t_data *game)
{
	int	i;
	int	j;

	i = game->p_pos_y;
	j = game->p_pos_x;
	if (keycode == KEY_A)
	{
		j--;
		if (valid_move(i, j, game))
			game->map[i][j + 1] = '0';
		else
			return (0);
	}
	else if (keycode == KEY_D)
	{
		j++;
		if (valid_move(i, j, game))
			game->map[i][j - 1] = '0';
		else
			return (0);
	}
	return (1);
}

int	close_window(t_data *game)
{
	ft_printf("\n-----------GAME EXITED-----------\n");
	exit_game(game);
	return (0);
}

int	handle_user_input(int keycode, t_data *game)
{
	if (keycode == KEY_W)
		move_player_up_down(keycode, game);
	if (keycode == KEY_S)
		move_player_up_down(keycode, game);
	if (keycode == KEY_A)
		move_payer_left_right(keycode, game);
	if (keycode == KEY_D)
		move_payer_left_right(keycode, game);
	if (keycode == ESC)
		close_window(game);
	put_update_graphics(game);
	if (keycode != KEY_W && keycode != KEY_A && keycode != KEY_S
		&& keycode != KEY_D && keycode != ESC)
		ft_printf("You pressed the wrong key...\n");
	return (0);
}
