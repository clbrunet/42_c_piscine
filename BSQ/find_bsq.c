/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_bsq.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalitt <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 14:33:39 by dalitt            #+#    #+#             */
/*   Updated: 2020/08/27 09:50:45 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

void	ft_find_diagonal(t_sq *sq, t_point_data **points_data,
		t_map_data map_data)
{
	int		diag;
	int		y;
	int		x;

	diag = sq->cur_diag + 1;
	y = sq->cur_y;
	x = sq->cur_x;
	if (points_data[y][x].type == 0)
	{
		sq->cur_diag = 0;
		while ((y + diag) < map_data.height
				&& (x + diag) < map_data.length
				&& points_data[y + diag][x + diag].space_up > diag - 1
				&& points_data[y + diag][x + diag].space_left > diag - 1)
			diag++;
		if (diag - 1 > sq->bsq_diag)
		{
			sq->bsq_y = y;
			sq->bsq_x = x;
			sq->bsq_diag = diag - 1;
		}
	}
}

void	ft_find_bsq(t_sq *sq, t_point_data **points_data, t_map_data map_data)
{
	sq->bsq_y = 0;
	sq->bsq_x = 0;
	sq->bsq_diag = -1;
	sq->cur_y = 0;
	sq->cur_x = 0;
	sq->cur_diag = 0;
	while (sq->cur_y < map_data.height
			&& sq->cur_y + sq->bsq_diag < map_data.height)
	{
		sq->cur_x = 0;
		while (sq->cur_x < map_data.length
				&& sq->cur_x + sq->bsq_diag < map_data.length)
		{
			ft_find_diagonal(sq, points_data, map_data);
			sq->cur_x++;
		}
		sq->cur_y++;
	}
}
