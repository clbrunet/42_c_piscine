/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 15:22:16 by clbrunet          #+#    #+#             */
/*   Updated: 2020/08/27 11:03:06 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "ft.h"
#include "bsq.h"

int		is_there_blank_line(char *map_single_str)
{
	int		i;

	i = 1;
	while (map_single_str[i])
	{
		if (map_single_str[i - 1] == '\n' && map_single_str[i] == '\n')
		{
			ft_putstr_fd(2, "map error\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int		is_bad_height(char **unparsed_map, t_map_data map_data)
{
	int		i;

	i = 1;
	while (unparsed_map[i])
		i++;
	if (map_data.height != i - 1)
	{
		ft_putstr_fd(2, "map error\n");
		return (1);
	}
	return (0);
}

int		check_length_map(char **parsed_map)
{
	int i;

	if (!(parsed_map[0]))
	{
		ft_putstr_fd(2, "map error\n");
		return (1);
	}
	i = 1;
	while (parsed_map[i])
	{
		if (ft_strlen(parsed_map[i - 1]) != ft_strlen(parsed_map[i]))
		{
			ft_putstr_fd(2, "map error\n");
			ft_free_map(parsed_map);
			return (1);
		}
		i++;
	}
	return (0);
}

int		is_only_map_data_chars(t_map_data map_data, char **parsed_map)
{
	int		i;
	int		j;

	i = 0;
	while (parsed_map[i])
	{
		j = 0;
		while (parsed_map[i][j])
		{
			if (parsed_map[i][j] != map_data.empty_char
						&& parsed_map[i][j] != map_data.obst_char)
			{
				ft_putstr_fd(2, "map error\n");
				ft_free_map(parsed_map);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int		check_printable_chars(char *map_single_str)
{
	int i;

	i = 0;
	while (map_single_str[i] != '\n' && map_single_str[i] != '\0')
	{
		if (map_single_str[i] < 32 || map_single_str[i] > 126)
		{
			ft_putstr_fd(2, "map error\n");
			return (1);
		}
		i++;
	}
	return (0);
}
