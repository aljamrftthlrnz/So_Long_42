/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirfatt <amirfatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:29:26 by amirfatt          #+#    #+#             */
/*   Updated: 2023/12/05 17:24:38 by amirfatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	valid_map_error(char **copy, t_data *game)
{
	free(copy);
	error_messages(COPY_ERR2, game);
}

char	**path_validation(t_data *game)
{
	char	**copy;
	int		i;
	int		j;

	i = 0;
	copy = (char **)malloc(sizeof(char *) * (game->y + 1));
	if (!copy)
		error_messages(COPY_ERR, game);
	while (i < game->y)
	{
		copy[i] = (char *)malloc(game->x + 1);
		if (!copy[i])
			valid_map_error(copy, game);
		j = 0;
		while (j < game->x)
		{
			copy[i][j] = game->map[i][j];
			j++;
		}
		copy[i][game->x] = '\0';
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

void	fill(char **copy, int y, int x, t_data *game)
{
	if (y < 0 || x < 0 || y >= game->y || x >= game->x || copy[y][x] == '1'
		|| copy[y][x] == 'X')
		return ;
	if (copy[y][x] == 'C')
		game->collect_verify++;
	else if (copy[y][x] == 'E')
		game->exit_verify++;
	copy[y][x] = 'X';
	fill(copy, y + 1, x, game);
	fill(copy, y - 1, x, game);
	fill(copy, y, x + 1, game);
	fill(copy, y, x - 1, game);
}

void	check_valid_path(t_data *game)
{
	int	y;
	int	x;

	y = game->p_pos_y;
	x = game->p_pos_x;
	game->valid = path_validation(game);
	if (!game->valid)
		error_messages(COPY_ERR3, game);
	fill(game->valid, y, x, game);
	if (game->collect != game->collect_verify || game->exit_verify != 1)
		error_messages(INVALID_MAP, game);
}
