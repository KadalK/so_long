/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kapinarc <kapinarc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:22:27 by kapinarc          #+#    #+#             */
/*   Updated: 2025/02/03 19:58:17 by kapinarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_border(char **tab)
{
	size_t	x;
	size_t	y;

	y = -1;
	if (check_size(tab))
	{
		ft_putstr_fd("Error\nThe map is too big..\n", 2);
		freeman(tab);
		exit(1);
	}
	while (tab[++y])
	{
		x = ft_strlen(tab[y]);
		if (tab[y][0] != '1' || tab[y][x - 1] != '1')
			return (ft_putstr_fd("Error\nMap ins't delimited.\n", 2), 1);
	}
	x = -1;
	while (tab[0][++x] && tab[get_map_height(tab) - 1][++x])
		if (tab[0][x] != '1' || tab[get_map_height(tab) - 1][x] != '1')
			return (ft_putstr_fd("Error\nWrong format.\n", 2), 1);
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
		ft_putstr_fd("Error\nNeed at least one poop :(\n", 2);
		ft_free(data);
		exit(1);
	}
	if (data->pars.p != 1)
	{
		ft_putstr_fd("Error\nNeed one Isaac :(\n", 2);
		ft_free(data);
		exit(1);
	}
	if (data->pars.e != 1)
	{
		ft_putstr_fd("Error\nNeed one exit :(\n", 2);
		ft_free(data);
		exit(1);
	}
	valid_char(map, data);
}

int	check_ext(char *av)
{
	size_t	i;

	i = ft_strlen(av);
	if (av[i - 4] != '.'
		|| av[i - 3] != 'b'
		|| av[i - 2] != 'e'
		|| av[i - 1] != 'r')
		return (1);
	return (0);
}

int	check_solve(t_data *data)
{
	get_player_pos(data, &data->pars);
	flood_fill(data->pars.player_x, data->pars.player_y, data);
	get_exit_pos(data, &data->pars);
	flood_fill2(data->pars.exit_x, data->pars.exit_y, data);
	if (check_sprite(data->map_check, 'C') != 0
		|| check_sprite(data->map_check, 'K') != 0)
	{
		ft_putstr_fd("Error\nIMPOSSIBLE!\n", 2);
		ft_free(data);
		exit (1);
	}
	return (0);
}
