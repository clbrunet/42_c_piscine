/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenmesb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 18:31:31 by mbenmesb          #+#    #+#             */
/*   Updated: 2020/08/08 19:05:05 by mbenmesb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	write_first_and_last_line(int x, int x_max)
{
	if ((x == x_max) || (!(x - 1)))
		ft_putchar('o');
	else
		ft_putchar('-');
}

void	write_other_lines(int x, int x_max)
{
	if (!(x - 1) || x == x_max)
		ft_putchar('|');
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
				write_first_and_last_line(x, x_max);
			else
				write_other_lines(x, x_max);
			x--;
		}
		ft_putchar('\n');
		x = x_max;
		y--;
	}
}
