/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 10:09:55 by clbrunet          #+#    #+#             */
/*   Updated: 2020/08/13 11:07:28 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_is_last(int combn[9], int n)
{
	int		i;

	i = n - 2;
	if (combn[n - 1] != 9)
		return (0);
	while (i >= 0)
	{
		if (combn[i] != combn[i + 1] - 1)
			return (0);
		i--;
	}
	return (1);
}

void	ft_print_combn_tab(int combn[9], int n)
{
	int		i;
	char	c;

	i = 0;
	while (i < n)
	{
		c = combn[i] + '0';
		write(1, &c, 1);
		i++;
	}
	if (!ft_is_last(combn, n))
		write(1, ", ", 2);
}

int		ft_is_combn_correct(int combn[9], int n)
{
	int		i;
	int		j;
	int		current;

	i = 0;
	while (i < n)
	{
		current = combn[i];
		j = i + 1;
		while (j < n)
		{
			if (combn[j] != -1 && (current == combn[j] || current > combn[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_backtrack_print_combn(int combn[9], int n, int pos)
{
	int		i;

	if (pos == n)
	{
		ft_print_combn_tab(combn, n);
		return ;
	}
	i = 0;
	while (i < 10)
	{
		combn[pos] = i;
		if (ft_is_combn_correct(combn, n))
			ft_backtrack_print_combn(combn, n, pos + 1);
		i++;
	}
	combn[pos] = -1;
}

void	ft_print_combn(int n)
{
	int		combn[9];
	int		i;

	if (n < 1 || 9 < n)
		return ;
	i = 0;
	while (i < 9)
	{
		combn[i] = -1;
		i++;
	}
	ft_backtrack_print_combn(combn, n, 0);
}
