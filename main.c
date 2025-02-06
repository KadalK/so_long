/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kapinarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:51:11 by kapinarc          #+#    #+#             */
/*   Updated: 2025/02/03 18:19:57 by kapinarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main_loop(t_data *data)
{
	imaginer(data);
	if (!data->img.bg_floor || !data->img.bg_wall)
		return (ft_free(data), 1);
	get_player_pos(data, &data->pars);
	mlx_hook(data->win, 2, 1L << 0, handle_key, data);
	mlx_hook(data->win, 17, 0, close_window, data);
	mlx_loop(data->mlx);
	ft_free(data);
	return (0);
}

int	spliter(t_data *data)
{
	data->map = ft_split(data->line, '\n');
	data->map_check = ft_split(data->line, '\n');
	if (!data->map_check|| !data->map)
		return (ft_free(data), 1);
	return (0);
}

int	winner(t_data *data)
{
	data->win = mlx_new_window(data->mlx, get_map_width(data->map) * TILE,
		get_map_height(data->map) * TILE, "so_long");
	if (!data->win)
		return (ft_putstr_fd("Error\nWindow\n", 2), ft_free(data), 1);
	return (0);
}


int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2 || check_ext(av[1]) == 1)
		return (ft_putstr_fd("Error\nNeed just 1 valid argument\n", 2), 1);
	init(&data);
	ft_bzero(&data, sizeof(data));
	if (read_map(av[1], &data))
		return (ft_putstr_fd("Error\nNo map\n", 2), 1);
	spliter(&data);
	check_solve(&data);
	check_all(data.map, &data);
	if (check_border(data.map) == 1 || is_rectangle(data.map) == 1)
		return (ft_free(&data), 0);
	data.mlx = mlx_init();
	if (!data.mlx)
		return (ft_putstr_fd("Error\nMLX\n", 2), ft_free(&data), 1);
	charge_img(&data);
	winner(&data);
	return (main_loop(&data));
}
