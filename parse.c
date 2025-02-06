/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kapinarc <kapinarc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:54:42 by kapinarc          #+#    #+#             */
/*   Updated: 2025/02/04 15:52:35 by kapinarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init(t_data *data)
{
	data->mlx = NULL;
	data->win = NULL;
	data->tmp = NULL;
	data->join = NULL;
	data->img.player = NULL;
	data->img.bg_wall = NULL;
	data->img.pick_up = NULL;
	data->img.door_on = NULL;
	data->img.door_off = NULL;
	data->img.bg_floor = NULL;
	data->line = NULL;
	data->map = NULL;
	data->map_check = NULL;
}

int	is_rectangle(char **map)
{
	int	y;

	if (!map || !map[0])
		return (0);
	y = 0;
	while (map[y])
	{
		if (ft_strlen(map[0]) != ft_strlen(map[y]))
		{
			ft_putstr_fd("Error\nThe map isn't a rectangle.\n", 2);
			return (1);
		}
		y++;
	}
	return (0);
}

int	read_map(char *file, t_data *data)
{
	data->tmp = ft_strdup("");
	data->fd = open(file, O_RDONLY);
	if (data->fd < 0)
		return (close(data->fd), 1);
	data->line = get_next_line(data->fd);
	if (!data->line)
		return (free(data->tmp), close(data->fd), 1);
	while (data->line)
	{
		data->join = ft_strjoin(data->tmp, data->line);
		if (!data->join)
			return (close(data->fd), 1);
		free (data->tmp);
		free (data->line);
		data->tmp = ft_strdup(data->join);
		if (!data->tmp)
			return (close(data->fd), 1);
		free(data->join);
		data->line = get_next_line(data->fd);
	}
	close(data->fd);
	free (data->line);
	data->line = data->tmp;
	return (0);
}

void	valid_char(char **map, t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (!check_char(map[x][y]))
			{
				ft_putstr_fd("Error\nInvalid charactere\n", 2);
				ft_free(data);
				exit(1);
			}
			y++;
		}
		x++;
	}
}
