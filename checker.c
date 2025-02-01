/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kapinarc <kapinarc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:22:27 by kapinarc          #+#    #+#             */
/*   Updated: 2025/01/30 17:22:27 by kapinarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_border(char **tab)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (tab[y])
	{
		x = ft_strlen(tab[y]);
		if (tab[y][0] != '1' || tab[y][x - 1] != '1')
		{
			return (ft_putstr_fd("Error\nMap ins't delimited\n", 1), 1);
		}
		y++;
	}
	x = 0;
	while (tab[0][x] && tab[get_map_height(tab) - 1][x])
	{
		if (tab[0][x] != '1' || tab[get_map_height(tab) - 1][x] != '1')
		{
			return (ft_putstr_fd("Error\nThe map is f*cked up.\n", 1), 1);
		}
		x++;
	}
	return (0);
}

int	check_sprite(char **map, char c)
{
	int	x;
	int	y;
	int	count;

	x = 0;
	count = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == c)
				count++;
			y++;
		}
		x++;
	}
	return (count);
}

void	check_all(char **map, t_data *data)
{
	data->pars.c = check_sprite(map, 'C');
	data->pars.p = check_sprite(map, 'P');
	data->pars.e = check_sprite(map, 'E');
	if (data->pars.c <= 0)
	{
		ft_putstr_fd("Error\nNeed at least one poop :(\n", 1);
		ft_free(data);
		exit(1);
	}
	if (data->pars.p != 1)
	{
		ft_putstr_fd("Error\nNeed one Isaac :(\n", 1);
		ft_free(data);
		exit(1);
	}
	if (data->pars.e != 1)
	{
		ft_putstr_fd("Error\nNeed one exit :(\n", 1);
		ft_free(data);
		exit(1);
	}
}

void	print_map(char **map) {
	for (int i = 0; i < 11; i++) {
		printf("%s\n", map[i]);
	}

}

void	flood_fill(int x, int y, t_data *data)
{
	if (data->map_check[x][y] == 'C' || data->map_check[x][y] == 'P' || data->map_check[x][y] == '0')
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

int	check_solve(t_data *data)
{
	get_player_pos(data, &data->pars);
	flood_fill(data->pars.player_x, data->pars.player_y, data);
	get_exit_pos(data, &data->pars);
	flood_fill2(data->pars.exit_x, data->pars.exit_y, data);
	if (check_sprite(data->map_check, 'C') != 0 || check_sprite(data->map_check, 'K') != 0)
	{
		ft_putstr_fd("Error\nIMPOSSIBLE!\n", 1);
		ft_free(data);
		exit (1);
	}
	return (0);
}
