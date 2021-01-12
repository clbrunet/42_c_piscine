/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 13:49:27 by clbrunet          #+#    #+#             */
/*   Updated: 2020/08/26 10:43:13 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct	s_file_content
{
	char					*str;
	struct s_file_content	*next;
}				t_file_content;

typedef struct	s_map_data
{
	int		height;
	int		length;
	char	empty_char;
	char	obst_char;
	char	full_char;
}				t_map_data;

typedef struct	s_point_data
{
	int		type;
	int		space_up;
	int		space_left;
}				t_point_data;

typedef struct	s_sq
{
	int		bsq_y;
	int		bsq_x;
	int		bsq_diag;
	int		cur_y;
	int		cur_x;
	int		cur_diag;
}				t_sq;

#endif
