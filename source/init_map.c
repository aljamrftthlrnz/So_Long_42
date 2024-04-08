/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirfatt <amirfatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:19:24 by amirfatt          #+#    #+#             */
/*   Updated: 2023/12/11 17:02:17 by amirfatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	get_count_map(t_data *game, char *argv)
{
	int		fd;
	char	*line;
	int		count;

	fd = open(argv, O_RDONLY);
	count = 0;
	if (fd < 0)
		error_messages(FD, game);
	line = get_next_line(fd);
	if (!line)
		return ;
	game->x = ft_strlen(line);
	if (game->x < 3)
	{
		free(line);
		error_messages(MAP_ERR, game);
	}
	while (line != NULL)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	game->y = count;
	close(fd);
}

void	map_error(char **line, t_data *game)
{
	if (*line != NULL)
		free(*line);
	error_messages(BUFFER, game);
}

void	process_line_to_stash(char *line, char *stash, int *j)
{
	int	i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		stash[(*j)++] = line[i++];
	if (line[i] == '\n')
		stash[(*j)++] = '\n';
}

void	create_map(t_data *game, char *argv)
{
	char	*stash;
	char	*line;
	int		j;
	int		fd;

	j = 0;
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		error_messages(FD, game);
	line = get_next_line(fd);
	stash = (char *)malloc((ft_strlen(line) * game->y) + 1);
	if (!stash)
		map_error(&line, game);
	while (line)
	{
		process_line_to_stash(line, stash, &j);
		free(line);
		line = get_next_line(fd);
	}
	stash[j] = '\0';
	close(fd);
	game->map = ft_split(stash, '\n');
	free(stash);
}

void	check_border(t_data *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (game->map[i][j])
	{
		while (j < game->x - 1)
		{
			if (game->map[0][j] != '1' || game->map[game->y - 1][j] != '1')
				error_messages(WALL_ERR, game);
			j++;
		}
		while (i < game->y)
		{
			if (game->map[i][0] != '1' || game->map[i][game->x - 1] != '1')
				error_messages(WALL_ERR2, game);
			i++;
		}
	}
}
