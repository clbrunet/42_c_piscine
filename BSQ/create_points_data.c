/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_map_struct.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalitt <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 10:26:09 by dalitt            #+#    #+#             */
/*   Updated: 2020/08/27 09:39:45 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"
#include "structs.h"

int				ft_space_up(int y, int x, char **parsed_map, char obst_char)
{
	int	i;
	int	space_up;

	i = y;
	space_up = 0;
	while (i > 0 && parsed_map[i - 1][x] != obst_char)
	{
		space_up++;
		i--;
	}
	return (space_up);
}

int				ft_space_left(int y, int x, char **parsed_map, char obst_char)
{
	int i;
	int space_left;

	i = x;
	space_left = 0;
	while (i > 0 && parsed_map[y][i - 1] != obst_char)
	{
		space_left++;
		i--;
	}
	return (space_left);
}

t_point_data	ft_fill_point_data(int y, int x, char **parsed_map,
		char obst_char)
{
	t_point_data	point_data;

	if (obst_char)
	{
		point_data.type = 0;
		point_data.space_up = ft_space_up(y, x, parsed_map, obst_char);
		point_data.space_left = ft_space_left(y, x, parsed_map, obst_char);
	}
	else
	{
		point_data.type = 1;
		point_data.space_up = 0;
		point_data.space_left = 0;
	}
	return (point_data);
}

t_point_data	**ft_create_points_data(char **parsed_map, t_map_data map_data)
{
	int				y;
	int				x;
	t_point_data	**points_data;

	if (!(points_data = malloc(map_data.height * sizeof(t_point_data *))))
		return (0);
	y = 0;
	while (y < map_data.height)
	{
		if (!(points_data[y] = malloc(map_data.length * sizeof(t_point_data))))
			return (0);
		x = 0;
		while (x < map_data.length)
		{
			if (parsed_map[y][x] == map_data.empty_char)
				points_data[y][x] = ft_fill_point_data(y, x, parsed_map,
						map_data.obst_char);
			else
				points_data[y][x] = ft_fill_point_data(y, x, parsed_map, 0);
			x++;
		}
		y++;
	}
	return (points_data);
}
