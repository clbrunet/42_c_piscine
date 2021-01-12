/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 10:18:57 by clbrunet          #+#    #+#             */
/*   Updated: 2020/08/27 10:40:46 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"
#include "structs.h"
#include "bsq.h"
#include "check_map.h"
#include "ft.h"

t_file_content	*ft_create_file_content_list(int fd, int *len)
{
	char			buf[1001];
	int				ret;
	t_file_content	*begin;

	ret = read(fd, buf, 1000);
	buf[ret] = 0;
	if (!(begin = ft_create_elem(ft_strdup(buf))))
		return (NULL);
	*len += ret;
	while ((ret = read(fd, buf, 1000)))
	{
		buf[ret] = 0;
		if (!(ft_list_push_back(&begin, ft_strdup(buf))))
			return (NULL);
		*len += ret;
	}
	return (begin);
}

char			*ft_file_content_list_to_str(t_file_content *elem, int len)
{
	char	*str;

	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[0] = 0;
	while (elem)
	{
		ft_strcat(str, elem->str);
		elem = elem->next;
	}
	return (str);
}

void			ft_parse_first_line(char **unparsed_map, t_map_data *map_data)
{
	int		i;

	i = 0;
	while (unparsed_map[0][i])
		i++;
	map_data->full_char = unparsed_map[0][--i];
	map_data->obst_char = unparsed_map[0][--i];
	map_data->empty_char = unparsed_map[0][--i];
	unparsed_map[0][i] = 0;
	map_data->height = ft_atoi(unparsed_map[0]);
}

char			**ft_parse_map(char **unparsed_map, t_map_data *map_data)
{
	char	**map;
	int		i;

	ft_parse_first_line(unparsed_map, map_data);
	if (is_bad_height(unparsed_map, *map_data) || check_chars(*map_data))
	{
		ft_free_map(unparsed_map);
		return (NULL);
	}
	map_data->length = ft_strlen(unparsed_map[1]);
	if (!(map = malloc((map_data->height + 1) * sizeof(char *))))
		return (NULL);
	map[map_data->height] = 0;
	i = 0;
	while (i < map_data->height)
	{
		if (!(map[i] = malloc(map_data->length * sizeof(char))))
			return (NULL);
		ft_strcpy(map[i], unparsed_map[i + 1]);
		i++;
	}
	ft_free_map(unparsed_map);
	return (map);
}

char			**ft_create_map(int fd, t_map_data *map_data)
{
	t_file_content	*file_content_list;
	char			*map_single_str;
	char			**unparsed_map;
	int				len;

	len = 0;
	if (!(file_content_list = ft_create_file_content_list(fd, &len)))
		return (NULL);
	if (!(map_single_str = ft_file_content_list_to_str(file_content_list, len)))
		return (NULL);
	ft_list_clear(file_content_list);
	if (check_map_single_str(map_single_str))
	{
		free(map_single_str);
		return (NULL);
	}
	if (!(unparsed_map = ft_split(map_single_str, "\n")))
		return (NULL);
	free(map_single_str);
	if (check_first_line(unparsed_map[0]))
	{
		ft_free_map(unparsed_map);
		return (NULL);
	}
	return (ft_parse_map(unparsed_map, map_data));
}
