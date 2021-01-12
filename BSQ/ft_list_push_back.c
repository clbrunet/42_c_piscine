/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 18:08:32 by clbrunet          #+#    #+#             */
/*   Updated: 2020/08/26 10:56:21 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "ft.h"

int		ft_list_push_back(t_file_content **begin_list, char *str)
{
	t_file_content	*elem;

	elem = *begin_list;
	while (elem->next)
		elem = elem->next;
	if (!(elem->next = ft_create_elem(str)))
		return (0);
	return (1);
}
