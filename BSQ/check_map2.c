/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 08:36:10 by clbrunet          #+#    #+#             */
/*   Updated: 2020/08/27 10:12:02 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"
#include "ft.h"
#include "structs.h"
#include "check_map.h"

int		check_first_line(char *line)
{
	int i;

	i = 0;
	while (line[i] != '\0')
		i++;
	i -= 4;
	if (i >= 0)
	{
		while (line[i] >= '0' && line[i] <= '9' && i >= 0)
			i--;
		if (i == -1)
			return (0);
	}
	ft_putstr_fd(2, "map error\n");
	return (1);
}

int		check_chars(t_map_data map_data)
{
	if (map_data.empty_char == map_data.obst_char
			|| map_data.empty_char == map_data.full_char
			|| map_data.obst_char == map_data.full_char)
	{
		ft_putstr_fd(2, "map error\n");
		return (1);
	}
	return (0);
}

int		check_line_feed(char *map_single_str)
{
	int	count;
	int i;

	count = 0;
	i = 0;
	while (map_single_str[i] != '\0')
	{
		if (map_single_str[i] == '\n')
			count++;
		i++;
	}
	if (count < 2 || map_single_str[i - 1] != '\n')
	{
		ft_putstr_fd(2, "map error\n");
		return (1);
	}
	return (0);
}

int		check_map_single_str(char *map_single_str)
{
	if (is_there_blank_line(map_single_str)
			|| check_printable_chars(map_single_str)
			|| check_line_feed(map_single_str))
		return (1);
	return (0);
}
