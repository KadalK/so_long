/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kapinarc <kapinarc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:20:29 by kapinarc          #+#    #+#             */
/*   Updated: 2025/02/04 17:20:29 by kapinarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	ft_free(t_data *data)
{
	if  (!data)
		return ;
//	if (data->img.bg_floor_img)
//		free(data->img.bg_floor_img);
//	if (data->img.bg_floor_img)
//		free(data->img.bg_wall_img);
//	if (data->img.player_img)
//		free(data->img.player_img);
//	if (data->img.pick_up_img )
//		free(data->img.pick_up_img);
//	if (data->img.door_off)
//		free (data->img.door_off);
//	if (data->img.door_on)
//		free (data->img.door_on);
	if (data->map)
		freeman(data->map);
	if (data->map_check)
		freeman(data->map_check);
	if (data->line)
		free(data->line);
}
