/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 15:47:04 by clbrunet          #+#    #+#             */
/*   Updated: 2020/08/08 15:59:17 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	write_first_and_last_line(int x, int y, int x_max, int y_max)
{
	if (y == y_max && (!(x - 1) || x == x_max))
		ft_putchar('A');
	else if (!(y - 1) && (!(x - 1) || x == x_max))
		ft_putchar('C');
	else
		ft_putchar('B');
}

void	write_the_other_lines(int x, int x_max)
{
	if (!(x - 1) || x == x_max)
		ft_putchar('B');
	else
		ft_putchar(' ');
}

void	rush(int x, int y)
{
	int	y_max;
	int	x_max;

	y_max = y;
	x_max = x;
	if (x <= 0 || y <= 0)
		return ;
	while (y)
	{
		while (x)
		{
			if (!(y - 1) || y == y_max)
				write_first_and_last_line(x, y, x_max, y_max);
			else
				write_the_other_lines(x, x_max);
			--x;
		}
		ft_putchar('\n');
		x = x_max;
		--y;
	}
}
