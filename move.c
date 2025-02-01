/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kapinarc <kapinarc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:46:02 by kapinarc          #+#    #+#             */
/*   Updated: 2025/01/30 12:47:08 by kapinarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	d_key(int keycode, t_data *data)
{
	if ((keycode == XK_d || keycode == XK_Right)
		&& data->map[data->pars.player_x][data->pars.player_y + 1] != '1'
		&& (data->map[data->pars.player_x][data->pars.player_y + 1] != 'E'
		|| check_sprite(data->map, 'C') == 0))
	{
		data->map[data->pars.player_x][data->pars.player_y] = '0';
		data->map[data->pars.player_x][data->pars.player_y + 1] = 'P';
	}
}

void	w_key(int keycode, t_data *data)
{
	if ((keycode == XK_w || keycode == XK_Up)
		&& data->map[data->pars.player_x - 1][data->pars.player_y] != '1'
		&& (data->map[data->pars.player_x - 1][data->pars.player_y] != 'E'
		|| check_sprite(data->map, 'C') == 0))
	{
		data->map[data->pars.player_x][data->pars.player_y] = '0';
		data->map[data->pars.player_x - 1][data->pars.player_y] = 'P';
	}
}

void	s_key(int keycode, t_data *data)
{
	if ((keycode == XK_s || keycode == XK_Down)
		&& data->map[data->pars.player_x +1][data->pars.player_y] != '1'
		&& (data->map[data->pars.player_x +1][data->pars.player_y] != 'E'
		|| check_sprite(data->map, 'C') == 0))
	{
		data->map[data->pars.player_x][data->pars.player_y] = '0';
		data->map[data->pars.player_x + 1][data->pars.player_y] = 'P';
	}
}

void	a_key(int keycode, t_data *data)
{
	if ((keycode == XK_a || keycode == XK_Left)
		&& data->map[data->pars.player_x][data->pars.player_y - 1] != '1'
		&& (data->map[data->pars.player_x][data->pars.player_y - 1] != 'E'
		|| check_sprite(data->map, 'C') == 0))
	{
		data->map[data->pars.player_x][data->pars.player_y] = '0';
		data->map[data->pars.player_x][data->pars.player_y - 1] = 'P';
	}
}

int	handle_key(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		close_window(data);
	w_key(keycode, data);
	d_key(keycode, data);
	s_key(keycode, data);
	a_key(keycode, data);
	if (check_sprite(data->map, 'E') == 0)
	{
		ft_putstr_fd("YOU WIN!\n", 1);
		close_window(data);
	}
	get_player_pos(data, &data->pars);
	imaginer(data);
	return (0);
}
