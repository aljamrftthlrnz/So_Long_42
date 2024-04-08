/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_graphics.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirfatt <amirfatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:39:22 by amirfatt          #+#    #+#             */
/*   Updated: 2023/12/04 17:25:34 by amirfatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	error_xpm_to_img(t_data *game)
{
	if (game->images->wall == NULL || game->images->space == NULL
		|| game->images->player == NULL || game->images->collect == NULL
		|| game->images->exit == NULL || game->images->pixel == 0)
		error_messages(IMG_PTR, game);
}

void	init_ptr(t_data *game)
{
	int	pixel;

	game->images = malloc(sizeof(t_img));
	if (!game->images)
		error_messages(STRUCT_IMG, game);
	game->images->wall = mlx_xpm_file_to_image(game->mlx_ptr, WALL, &pixel,
			&pixel);
	game->images->space = mlx_xpm_file_to_image(game->mlx_ptr, SPACE, &pixel,
			&pixel);
	game->images->player = mlx_xpm_file_to_image(game->mlx_ptr, PLAYER, &pixel,
			&pixel);
	game->images->collect = mlx_xpm_file_to_image(game->mlx_ptr, COLLECT,
			&pixel, &pixel);
	game->images->exit = mlx_xpm_file_to_image(game->mlx_ptr, EXIT, &pixel,
			&pixel);
	game->images->pixel = pixel;
	error_xpm_to_img(game);
}
