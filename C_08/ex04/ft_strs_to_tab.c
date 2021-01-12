/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 11:54:21 by clbrunet          #+#    #+#             */
/*   Updated: 2020/08/16 16:59:08 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int					ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char				*ft_strdup_w_len(char *src, int len)
{
	char	*dup;
	int		i;

	if (!(dup = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (src[i])
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = 0;
	return (dup);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	struct s_stock_str	*stock_str;
	int					i;

	if (!(stock_str = malloc(sizeof(t_stock_str) * (ac + 1))))
		return (NULL);
	stock_str[ac].str = NULL;
	i = 0;
	while (i < ac)
	{
		stock_str[i].size = ft_strlen(av[i]);
		stock_str[i].str = av[i];
		if (!(stock_str[i].copy = ft_strdup_w_len(av[i], stock_str[i].size)))
			return (NULL);
		i++;
	}
	return (stock_str);
}
