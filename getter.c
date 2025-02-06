/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kapinarc <kapinarc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:49:07 by kapinarc          #+#    #+#             */
/*   Updated: 2025/01/30 17:50:01 by kapinarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_map_height(char **map)
{
	int	x;

	x = 0;
	while (map[x])
		x++;
	return (x);
}

int	get_map_width(char **map)
{
	int	y;

	y = 0;
	while (map[0][y])
		y++;
	return (y);
}

void	get_player_pos(t_data *data, t_pars *pars)
{
	int	x;
	int	y;

	x = 0;
	while (data->map[x])
	{
		y = 0;
		while (data->map[x][y])
		{
			if (data->map[x][y] == 'P')
			{
				pars->player_x = x;
				pars->player_y = y;
			}
			y++;
		}
		x++;
	}
}

void	get_exit_pos(t_data *data, t_pars *pars)
{
	int	x;
	int	y;

	x = 0;
	while (data->map[x])
	{
		y = 0;
		while (data->map[x][y])
		{
			if (data->map[x][y] == 'E')
			{
				pars->exit_x = x;
				pars->exit_y = y;
			}
			y++;
		}
		x++;
	}
}
