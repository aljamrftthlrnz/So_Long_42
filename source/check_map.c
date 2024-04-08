/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirfatt <amirfatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:17:53 by amirfatt          #+#    #+#             */
/*   Updated: 2023/12/11 17:01:22 by amirfatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	element_helper(char c, int i, int j, t_data *game)
{
	if (c == 'P')
	{
		game->player++;
		game->p_pos_x = j;
		game->p_pos_y = i;
	}
	else if (c == 'E')
	{
		game->exit++;
		game->old_exit_x = j;
		game->old_exit_y = i;
	}
}

void	verify_elements(t_data *game)
{
	if (game->player != 1 || game->collect < 1 || game->exit != 1)
		error_messages(ELEMENTS, game);
	if (game->elements_flag > 0)
		error_messages(WHITESPACES, game);
}

void	whitespaces_unknown_char(int i, int j, t_data *game)
{
	if (game->map[i][j] != 'P' && game->map[i][j] != 'E'
		&& game->map[i][j] != 'C' && game->map[i][j] != '0'
		&& game->map[i][j] != '1')
		game->elements_flag++;
	else if (game->map[i][j] == '\n' || game->map[i][j] == ' '
		|| game->map[i][j] == '\t')
		game->elements_flag++;
}

void	check_elements(t_data *game)
{
	int	i;
	int	j;
	int	flag;

	i = -1;
	flag = 0;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == 'P')
				element_helper(game->map[i][j], i, j, game);
			else if (game->map[i][j] == 'E')
				element_helper(game->map[i][j], i, j, game);
			else if (game->map[i][j] == 'C')
				game->collect++;
			whitespaces_unknown_char(i, j, game);
		}
	}
	verify_elements(game);
}

void	check_rectangle(t_data *game)
{
	int	x_check;
	int	i;

	if (!game || !game->map)
		error_messages(NULL_PTR, game);
	i = 0;
	x_check = ft_strlen(game->map[0]);
	if (x_check == 0)
		error_messages(NULL_PTR, game);
	while (i < game->y)
	{
		if (!game->map[i]
			|| (ft_strlen(game->map[i]) != (unsigned long)x_check))
			error_messages(RECT, game);
		i++;
	}
	game->x = x_check;
}
