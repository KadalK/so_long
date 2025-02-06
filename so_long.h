/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kapinarc <kapinarc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:12:21 by kapinarc          #+#    #+#             */
/*   Updated: 2025/02/03 19:58:08 by kapinarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx_linux/mlx.h"
# include "libft/libft.h"
# include "libft/get_next_line.h"

# include <stdlib.h>
# include <unistd.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdbool.h>


# define BUFFER_SIZE 100
# define TILE 75

typedef struct s_pars
{
	int	step;
	int	exit_x;
	int	exit_y;
	int	player_x;
	int	player_y;
	int	c;
	int	e;
	int	p;
}	t_pars;

typedef struct s_img
{
	void	*player;
	void	*bg_wall;
	void	*bg_floor;
	void	*pick_up;
	void	*door_off;
	void	*door_on;
}	t_img;

typedef struct s_data
{
	int		fd;
	char	*line;
	char	*join;
	char	*tmp;
	void	*mlx;
	void	*win;
	char	**map;
	char	**map_check;
	t_img	img;
	t_pars	pars;
}	t_data;

//checker.c
int		check_border(char **tab);
int		check_sprite(char **map, char c);
void	check_all(char **map, t_data *data);
int		check_ext(char *av);
int		check_solve(t_data *data);

//checker2.c
int		check_size(char **map);
int		check_char(char c);

//flood_fill.c
void	flood_fill(int x, int y, t_data *data);
void	flood_fill2(int x, int y, t_data *data);

//free.c
void	freeman(char **man);
void	ft_free(t_data *data);

//getter.c
int		get_map_height(char **map);
int		get_map_width(char **map);
void	get_player_pos(t_data *data, t_pars *pars);
void	get_exit_pos(t_data *data, t_pars *pars);

//image.c
int		close_window(t_data *data);
void	charge_img(t_data *data);
void	imaginer(t_data *data);
void	add_image(t_data *data, int x, int y);

//move.c
void	w_key(int keycode, t_data *data);
void	a_key(int keycode, t_data *data);
void	s_key(int keycode, t_data *data);
void	d_key(int keycode, t_data *data);
int		handle_key(int keycode, t_data *data);

//parse.c
void	init(t_data *data);
int		is_rectangle(char **map);
int		read_map(char *file, t_data *data);
void	valid_char(char **map, t_data *data);

//main.c
int		main_loop(t_data *data);
int	spliter(t_data *data);
int		winner(t_data *data);

#endif
