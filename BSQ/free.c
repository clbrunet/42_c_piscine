/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 12:11:28 by clbrunet          #+#    #+#             */
/*   Updated: 2020/08/27 09:57:06 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"
#include "structs.h"

void	ft_list_clear(t_file_content *begin_list)
{
	t_file_content	*elem;

	while (begin_list->next)
	{
		elem = begin_list;
		while (elem->next && elem->next->next)
		{
			elem = elem->next;
		}
		free(elem->next->str);
		free(elem->next);
		elem->next = 0;
	}
	free(begin_list->str);
	free(begin_list);
}

void	ft_free_points_data(t_point_data **points_data, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		free(points_data[i]);
		i++;
	}
	free(points_data);
}

void	ft_free_map(char **map)
{
	int		i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
