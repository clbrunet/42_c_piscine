/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenmesb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 19:26:44 by mbenmesb          #+#    #+#             */
/*   Updated: 2020/08/09 14:15:18 by mbenmesb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	write_first_and_last_line(int x, int x_max, int y, int y_max)
{
	if ((x == x_max && y == y_max) || (!(x - 1) && x - x_max && y - y_max))
		ft_putchar('/');
	else if ((!(x - 1) && y == y_max) || (!(y - 1) && x == x_max))
		ft_putchar('\\');
	else
		ft_putchar('*');
}

void	write_other_lines(int x, int x_max)
{
	if (!(x - 1) || x == x_max)
		ft_putchar('*');
	else
		ft_putchar(' ');
}

void	rush(int x, int y)
{
	int x_max;
	int y_max;

	x_max = x;
	y_max = y;
	if (x <= 0 || y <= 0)
		return ;
	while (y)
	{
		while (x)
		{
			if (!(y - 1) || y == y_max)
				write_first_and_last_line(x, x_max, y, y_max);
			else
				write_other_lines(x, x_max);
			x--;
		}
		ft_putchar('\n');
		x = x_max;
		y--;
	}
}
