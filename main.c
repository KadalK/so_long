/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kapinarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:51:11 by kapinarc          #+#    #+#             */
/*   Updated: 2025/01/29 19:56:51 by kapinarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	ft_free(t_data *data)
{
	if (data->map)
		freeman(data->map);
	if (data->map_check)
		freeman(data->map_check);
	if (data->line)
		free(data->line);
}

int	main_loop(t_data *data)
{
	charge_img(data);
	imaginer(data);
	if (!data->img.bg_floor_img || !data->img.bg_wall_img)
		return (ft_free(data), 1);
	get_player_pos(data, &data->pars);
	mlx_hook(data->win, 2, 1L << 0, handle_key, data);
	mlx_hook(data->win, 17, 0, close_window, data);
	mlx_loop(data->mlx);
	ft_free(data);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (ft_putstr_fd("Error\nNeed just 1 argument\n", 1), 0);
	init(&data);
	ft_bzero(&data, sizeof(data));
	if (read_map(av[1], &data))
		return (ft_putstr_fd("Error\nNo map\n", 1), ft_free(&data), 1);
	data.map = ft_split(data.line, '\n');
	if (data.map == NULL)
		return (free(data.line), 0);
	data.map_check = ft_split(data.line, '\n');
	if (data.map_check == NULL)
		return (ft_free(&data), 0);
	check_solve(&data);
	check_all(data.map, &data);
	if (check_border(data.map) == 1 || is_rectangle(data.map) == 1)
		return (ft_free(&data), 0);
	data.mlx = mlx_init();
	if (!data.mlx)
		return (ft_putstr_fd("Error\nMLX\n", 1), ft_free(&data), 1);
	data.win = mlx_new_window(data.mlx, get_map_width(data.map) * 75,
			get_map_height(data.map) * 75, "so_long");
	if (!data.win)
		return (ft_putstr_fd("Error\nWindow\n", 1), ft_free(&data), 1);
	return (main_loop(&data));
}
