/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kapinarc <kapinarc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:12:21 by kapinarc          #+#    #+#             */
/*   Updated: 2025/01/28 19:10:31 by kapinarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include "mlx_linux/mlx.h"
# include <unistd.h>
# include "libft/libft.h"
# include "libft/get_next_line.h"
# include <X11/keysym.h>
# include <fcntl.h>

# define BUFFER_SIZE 100
# define TILE 75

typedef struct s_pars
{
	int exit_x;
	int exit_y;
	int	player_x;
	int	player_y;
	int	c;
	int	e;
	int	p;
}	t_pars;

typedef struct s_img
{
	void	*player_img;
	void	*bg_wall_img;
	void	*bg_floor_img;
	void	*pick_up_img;
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
	int		pixel_per_case;
	t_img	img;
	t_pars	pars;
}	t_data;

int		read_map(char *file, t_data *data);
void	add_image(t_data *data, int x, int y);
int		close_window(t_data *data);
int		get_map_width(char **map);
int		get_map_height(char **map);
void	get_player_pos(t_data *data, t_pars *pars);
void	get_exit_pos(t_data *data, t_pars *pars);
void	charge_img(t_data *data);
void	freeman(char **man);
void	ft_free(t_data *data);
int		check_sprite(char **map, char c);
void	check_all(char **map, t_data *data);
int		check_border(char **tab);
void	init(t_data *data);
int		handle_key(int keycode, t_data *data);
void	imaginer(t_data *data);
int		is_rectangle(char **map);
void	flood_fill(int x, int y, t_data *data);
int		check_solve(t_data *data);

#endif
