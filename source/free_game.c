/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirfatt <amirfatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 19:37:54 by amirfatt          #+#    #+#             */
/*   Updated: 2023/12/04 17:25:31 by amirfatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	destroy_graphics(t_data *game)
{
	if (game->images)
	{
		if (game->images->collect != NULL)
			mlx_destroy_image(game->mlx_ptr, game->images->collect);
		if (game->images->player != NULL)
			mlx_destroy_image(game->mlx_ptr, game->images->player);
		if (game->images->exit != NULL)
			mlx_destroy_image(game->mlx_ptr, game->images->exit);
		if (game->images->wall != NULL)
			mlx_destroy_image(game->mlx_ptr, game->images->wall);
		if (game->images->space != NULL)
			mlx_destroy_image(game->mlx_ptr, game->images->space);
	}
	free(game->images);
}

int	destroy_window(t_data *game)
{
	if (game->mlx_ptr != NULL)
	{
		if (game->win_ptr != NULL)
			mlx_destroy_window(game->mlx_ptr, game->win_ptr);
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
	}
	return (0);
}

void	free_map(char **str)
{
	int	i;

	i = 0;
	if (str != NULL)
	{
		while (str[i])
		{
			free(str[i]);
			i++;
		}
		free(str);
	}
}

void	exit_game(t_data *game)
{
	int	i;

	i = 0;
	if (game != NULL)
	{
		if (game->valid != NULL)
			free_map(game->valid);
		if (game->map != NULL)
			free_map(game->map);
		destroy_graphics(game);
		destroy_window(game);
		free(game);
	}
	exit(1);
}
