/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 17:19:27 by clbrunet          #+#    #+#             */
/*   Updated: 2020/08/26 10:54:12 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "structs.h"

t_file_content	*ft_create_elem(char *str)
{
	t_file_content	*list;

	if (!(list = malloc(sizeof(t_file_content))))
		return (NULL);
	list->str = str;
	list->next = NULL;
	return (list);
}
