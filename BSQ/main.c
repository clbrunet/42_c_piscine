/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 13:44:19 by clbrunet          #+#    #+#             */
/*   Updated: 2020/08/27 11:18:56 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"
#include "ft.h"
#include "structs.h"
#include "bsq.h"
#include "check_map.h"

void	ft_print_map(t_map_data map_data, char **map)
{
	int		i;

	i = -1;
	while (++i < map_data.height)
	{
		ft_putstr_fd(1, map[i]);
		ft_putstr_fd(1, "\n");
	}
}

void	ft_resolve_bsq(t_map_data map_data, char **parsed_map)
{
	t_sq			sq;
	t_point_data	**points_data;

	points_data = ft_create_points_data(parsed_map, map_data);
	ft_find_bsq(&sq, points_data, map_data);
	ft_add_square_map_parsed(sq, parsed_map, map_data);
	ft_print_map(map_data, parsed_map);
	ft_free_map(parsed_map);
	ft_free_points_data(points_data, map_data.height);
}

void	ft_stdin_bsq(void)
{
	t_map_data		map_data;
	char			**parsed_map;

	if (!(parsed_map = ft_create_map(0, &map_data)))
		return ;
	if (check_length_map(parsed_map)
			|| is_only_map_data_chars(map_data, parsed_map))
		return ;
	ft_resolve_bsq(map_data, parsed_map);
}

void	ft_files_bsq(int argc, char **argv)
{
	t_map_data		map_data;
	char			**parsed_map;
	int				fd;
	int				i;
	int				errors;

	i = 0;
	while (++i < argc)
	{
		errors = 0;
		if ((fd = open(argv[i], O_RDONLY)) == -1)
			ft_putstr_fd(2, "map error\n");
		if (fd == -1)
			errors = 1;
		if (!errors && !(parsed_map = ft_create_map(fd, &map_data)))
			errors = 1;
		if (!errors && (check_length_map(parsed_map)
				|| is_only_map_data_chars(map_data, parsed_map)))
			errors = 1;
		if (!errors)
			ft_resolve_bsq(map_data, parsed_map);
		if (i < argc - 1)
			ft_putstr_fd(1, "\n");
		close(fd);
	}
}

int		main(int argc, char **argv)
{
	if (argc == 1)
		ft_stdin_bsq();
	else
		ft_files_bsq(argc, argv);
	return (0);
}
