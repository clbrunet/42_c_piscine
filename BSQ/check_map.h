/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 15:44:22 by clbrunet          #+#    #+#             */
/*   Updated: 2020/08/27 10:01:22 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_MAP_H
# define CHECK_MAP_H

int		is_there_blank_line(char *map_single_str);
int		is_bad_height(char **unparsed_map, t_map_data map_data);
int		check_length_map(char **parsed_map);
int		is_only_map_data_chars(t_map_data map_data, char **parsed_map);
int		check_printable_chars(char *map_single_str);

int		check_first_line(char *line);
int		check_chars(t_map_data map_data);
int		check_last_return(char *map_single_str);
int		check_map_single_str(char *map_single_str);

#endif
