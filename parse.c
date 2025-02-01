/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kapinarc <kapinarc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:54:42 by kapinarc          #+#    #+#             */
/*   Updated: 2025/01/30 14:28:56 by kapinarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init(t_data *data)
{
	data->mlx = NULL;
	data->win = NULL;
	data->tmp = NULL;
	data->join = NULL;
	data->img.player_img = NULL;
	data->img.bg_wall_img = NULL;
	data->img.pick_up_img = NULL;
	data->img.door_on = NULL;
	data->img.door_off = NULL;
	data->img.bg_floor_img = NULL;
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
			ft_putstr_fd("Error\nThe map isn't a rectangle.\n", 1);
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
	printf("fd: %d\n", data->fd);
	if (data->fd < 0)
		return (close(data->fd), 1);
	data->line = get_next_line(data->fd);
	if (!data->line)
		return (close(data->fd), 1);
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

void	freeman(char **man)
{
	int	x;

	x = 0;
	while (man[x])
	{
		free(man[x]);
		x++;
	}
	free(man);
}
