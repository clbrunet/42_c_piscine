/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaczmar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 14:47:24 by hkaczmar          #+#    #+#             */
/*   Updated: 2020/08/08 14:52:35 by hkaczmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	write_first_and_last_line(int x, int x_max)
{
	if (x == x_max)
		ft_putchar('A');
	else if (!(x - 1))
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
				write_first_and_last_line(x, x_max);
			else
				write_the_other_lines(x, x_max);
			--x;
		}
		ft_putchar('\n');
		x = x_max;
		--y;
	}
}
