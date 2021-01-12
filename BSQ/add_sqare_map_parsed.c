/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_square_map_parsed.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalitt <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 15:07:50 by dalitt            #+#    #+#             */
/*   Updated: 2020/08/27 09:37:05 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

void	ft_add_square_map_parsed(t_sq sq, char **map_parsed,
		t_map_data map_data)
{
	int i;
	int j;

	i = 0;
	while (i < sq.bsq_diag + 1)
	{
		j = 0;
		while (j < sq.bsq_diag + 1)
		{
			map_parsed[sq.bsq_y + i][sq.bsq_x + j] = map_data.full_char;
			j++;
		}
		i++;
	}
}
