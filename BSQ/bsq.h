/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 14:07:44 by clbrunet          #+#    #+#             */
/*   Updated: 2020/08/27 09:11:43 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include "structs.h"

char			**ft_create_map(int fd, t_map_data *map_data);
t_point_data	**ft_create_points_data(char **parsed_map, t_map_data map_data);
void			ft_find_bsq(t_sq *sq, t_point_data **map, t_map_data map_data);
void			ft_add_square_map_parsed(t_sq sq, char **map_parsed,
		t_map_data map_data);
void			ft_free_map(char **map);
void			ft_free_points_data(t_point_data **points_data, int size);

#endif
