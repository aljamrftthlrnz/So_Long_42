/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirfatt <amirfatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 10:44:32 by amirfatt          #+#    #+#             */
/*   Updated: 2023/12/11 16:51:27 by amirfatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <errno.h>
# include <fcntl.h>
# include <mlx.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define ESC 65307

# define WALL "./assets/wall.xpm"
# define SPACE "./assets/space.xpm"
# define PLAYER "./assets/player.xpm"
# define COLLECT "./assets/collect.xpm"
# define EXIT "./assets/exit.xpm"

# define BER 1
# define STRUCT 2
# define FD 3
# define GNL 4
# define BUFFER 5
# define MAP_ERR 6
# define RECT 7
# define WALL_ERR 8
# define WALL_ERR2 9
# define ELEMENTS 10
# define WHITESPACES 11
# define COPY_ERR 12
# define COPY_ERR2 13
# define COPY_ERR3 14
# define INVALID_MAP 15
# define MLX_ERR 16
# define STRUCT_IMG 17
# define IMG_PTR 18
# define WIN_PTR 19
# define WRONG_KEY 20
# define NULL_PTR 21

typedef struct s_img
{
	void	*wall;
	void	*collect;
	void	*player;
	void	*space;
	void	*exit;
	int		pixel;

}			t_img;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;

	char	**map;
	char	**valid;
	int		cvalid;
	int		y;
	int		x;

	int		moves;
	int		collect;
	int		exit;
	int		player;

	int		collect_verify;
	int		exit_verify;
	int		player_verify;
	int		elements_flag;

	int		p_pos_y;
	int		p_pos_x;

	int		old_exit_x;
	int		old_exit_y;

	bool	hidden_exit;
	int		err;
	t_img	*images;

}			t_data;

/*MAIN ENTRY POINT*/
void		map_checker(t_data *game);
void		check_file_extension(t_data *game, char *argv);
void		init_win_ptr(t_data *game);

/*INITIALISING MAP*/
void		get_count_map(t_data *game, char *argv);
void		map_error(char **line, t_data *game);
void		create_map(t_data *game, char *argv);
void		fill(char **copy, int y, int x, t_data *game);
char		**path_validation(t_data *game);
void		check_valid_path(t_data *game);
void		process_line_to_stash(char *line, char *stash, int *j);
void		creation_map(t_data *game, char *argv);

/*MAP CHECKER*/
void		element_helper(char c, int i, int j, t_data *game);
void		verify_elements(t_data *game);
void		whitespaces_unknown_char(int i, int j, t_data *game);
void		check_elements(t_data *game);
void		check_border(t_data *game);
void		check_rectangle(t_data *game);

/*INITIALISING GAME*/
void		error_xpm_to_img(t_data *game);
void		init_ptr(t_data *game);
void		print_movements(t_data *game);
int			put_update_graphics(t_data *game);

/*GAME MANAGEMENT*/
int			handle_user_input(int keycode, t_data *game);
int			valid_move(int y, int x, t_data *game);
int			move_player_up_down(int keycode, t_data *game);
int			move_payer_left_right(int keycode, t_data *game);

/*EXIT GAME*/
int			close_window(t_data *game);
void		win_game(int y, int x, char c, t_data *game);
void		destroy_graphics(t_data *game);
int			destroy_window(t_data *game);
void		exit_game(t_data *game);

/*ERROR HANDLING*/
void		error_messages(int option, t_data *game);
void		error_messages_two(int opt, t_data *game);
void		free_map(char **str);
void		valid_map_error(char **copy, t_data *game);

#endif
