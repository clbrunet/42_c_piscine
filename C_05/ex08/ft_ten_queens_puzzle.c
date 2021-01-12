/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 16:47:14 by clbrunet          #+#    #+#             */
/*   Updated: 2020/08/12 10:32:37 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_ten_queens_puzzle(int solution[10])
{
	int	i;

	i = 0;
	while (i < 10)
	{
		ft_putchar(solution[i] + '0');
		i++;
	}
	ft_putchar('\n');
}

int		ft_are_there_any_errors(int solution[10])
{
	int		current;
	int		i;
	int		j;
	int		k;

	i = 0;
	while (i < 10)
	{
		current = solution[i];
		j = i + 1;
		k = 1;
		while (j < 10)
		{
			if (current != -1 && solution[j] != -1 && (current == solution[j]
					|| current + k == solution[j]
					|| current - k == solution[j]))
				return (1);
			j++;
			k++;
		}
		i++;
	}
	return (0);
}

void	ft_recursive_ten_queens_puzzle(int solution[10], int *ret, int col)
{
	int		i;

	if (col == 10)
	{
		ft_print_ten_queens_puzzle(solution);
		(*ret)++;
		return ;
	}
	i = 0;
	while (i < 10)
	{
		solution[col] = i;
		if (!ft_are_there_any_errors(solution))
			ft_recursive_ten_queens_puzzle(solution, ret, col + 1);
		i++;
	}
	solution[col] = -1;
}

int		ft_ten_queens_puzzle(void)
{
	int		solution[10];
	int		ret;
	int		i;

	i = 0;
	while (i < 10)
	{
		solution[i] = -1;
		i++;
	}
	ret = 0;
	ft_recursive_ten_queens_puzzle(solution, &ret, 0);
	return (ret);
}
