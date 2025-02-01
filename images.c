/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kapinarc <kapinarc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:43:30 by kapinarc          #+#    #+#             */
/*   Updated: 2025/01/30 14:31:32 by kapinarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_data *data)
{
	ft_free(data);
	mlx_destroy_image(data->mlx, data->img.bg_floor_img);
	mlx_destroy_image(data->mlx, data->img.bg_wall_img);
	mlx_destroy_image(data->mlx, data->img.player_img);
	mlx_destroy_image(data->mlx, data->img.pick_up_img);
	mlx_destroy_image(data->mlx, data->img.door_on);
	mlx_destroy_image(data->mlx, data->img.door_off);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
}

void	charge_img(t_data *data)
{
	int	w;
	int	h;

	data->img.bg_floor_img = mlx_xpm_file_to_image(data->mlx,
			"./textures/parquet.xpm", &w, &h);
	data->img.bg_wall_img = mlx_xpm_file_to_image(data->mlx,
			"./textures/rock.xpm", &w, &h);
	data->img.player_img = mlx_xpm_file_to_image(data->mlx,
			"./textures/isaac.xpm", &w, &h);
	data->img.pick_up_img = mlx_xpm_file_to_image(data->mlx,
			"./textures/collectible.xpm", &w, &h);
	data->img.door_off = mlx_xpm_file_to_image(data->mlx,
			"./textures/door_off.xpm", &w, &h);
	data->img.door_on = mlx_xpm_file_to_image(data->mlx,
			"./textures/door_on.xpm", &w, &h);
}

void	imaginer(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (data->map[x])
	{
		y = 0;
		while (data->map[x][y])
		{
			add_image(data, x, y);
			y++;
		}
		x++;
	}
}

void	add_image(t_data *data, int x, int y)
{
	if (data->map[x][y] == '0')
		mlx_put_image_to_window(data->mlx,
			data->win, data->img.bg_floor_img, y * TILE, x * TILE);
	if (data->map[x][y] == '1')
		mlx_put_image_to_window(data->mlx,
			data->win, data->img.bg_wall_img, y * TILE, x * TILE);
	if (data->map[x][y] == 'C')
		mlx_put_image_to_window(data->mlx,
			data->win, data->img.pick_up_img, y * TILE, x * TILE);
	if (data->map[x][y] == 'P')
		mlx_put_image_to_window(data->mlx,
			data->win, data->img.player_img, y * TILE, x * TILE);
	if (data->map[x][y] == 'E')
	{
		mlx_put_image_to_window(data->mlx, data->win,
			data->img.door_off, y * TILE, x * TILE);
		if (check_sprite(data->map, 'C') == 0)
		{
			mlx_put_image_to_window(data->mlx, data->win,
				data->img.door_on, y * TILE, x * TILE);
		}
	}
}
