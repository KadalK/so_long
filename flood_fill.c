/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kapinarc <kapinarc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:21:33 by kapinarc          #+#    #+#             */
/*   Updated: 2025/02/03 18:21:33 by kapinarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(int x, int y, t_data *data)
{
	if (data->map_check[x][y] == 'C'
		|| data->map_check[x][y] == 'P' || data->map_check[x][y] == '0')
	{
		data->map_check[x][y] = 'K';
		flood_fill(x + 1, y, data);
		flood_fill(x - 1, y, data);
		flood_fill(x, y + 1, data);
		flood_fill(x, y - 1, data);
	}
}

void	flood_fill2(int x, int y, t_data *data)
{
	if (data->map_check[x][y] == 'E' || data->map_check[x][y] == 'K')
	{
		data->map_check[x][y] = 'V';
		flood_fill2(x + 1, y, data);
		flood_fill2(x - 1, y, data);
		flood_fill2(x, y + 1, data);
		flood_fill2(x, y - 1, data);
	}
}
