/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirfatt <amirfatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 11:03:43 by amirfatt          #+#    #+#             */
/*   Updated: 2023/12/04 17:25:45 by amirfatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	put_images(char c, int i, int j, t_data *game)
{
	if (c == '0')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->images->space, j * game->images->pixel, i
			* game->images->pixel);
	if (c == '1')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->images->wall, j * game->images->pixel, i
			* game->images->pixel);
	if (c == 'P')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->images->player, j * game->images->pixel, i
			* game->images->pixel);
	if (c == 'C')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->images->collect, j * game->images->pixel, i
			* game->images->pixel);
	if (c == 'E')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->images->exit, j * game->images->pixel, i
			* game->images->pixel);
}

int	put_update_graphics(t_data *game)
{
	int	i;
	int	j;

	i = 0;
	if (game->hidden_exit == true && (game->p_pos_x != game->old_exit_x
			|| game->p_pos_y != game->old_exit_y))
	{
		game->map[game->old_exit_y][game->old_exit_x] = 'E';
		game->hidden_exit = false;
	}
	while (i < game->y)
	{
		j = 0;
		while (j < game->x)
		{
			put_images(game->map[i][j], i, j, game);
			j++;
		}
		i++;
	}
	return (0);
}

void	print_movements(t_data *game)
{
	ft_printf("\nMoves made: %d\n", game->moves);
}
