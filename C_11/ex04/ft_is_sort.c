/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 18:48:28 by clbrunet          #+#    #+#             */
/*   Updated: 2020/08/19 12:14:03 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int		i;
	int		is_ascending_sort;
	int		is_descending_sort;

	is_ascending_sort = 1;
	is_descending_sort = 1;
	i = 1;
	while (i < length)
	{
		if ((*f)(tab[i - 1], tab[i]) > 0)
			is_ascending_sort = 0;
		if ((*f)(tab[i - 1], tab[i]) < 0)
			is_descending_sort = 0;
		i++;
	}
	if (is_descending_sort || is_ascending_sort)
		return (1);
	return (0);
}
