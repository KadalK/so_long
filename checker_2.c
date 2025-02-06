/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kapinarc <kapinarc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:41:51 by kapinarc          #+#    #+#             */
/*   Updated: 2025/02/04 17:41:51 by kapinarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_size(char **map)
{
	int	x;
	int	y;

	x = get_map_width(map);
	y = get_map_height(map);
	if (x > 51 || y > 28)
		return (1);
	return (0);
}

int	check_char(char c)
{
	if (c == 'C' || c == 'P' || c == 'E' || c == '0' || c == '1')
		return (1);
	return (0);
}

