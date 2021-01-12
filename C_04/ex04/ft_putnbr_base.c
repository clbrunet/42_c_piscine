/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 17:51:11 by clbrunet          #+#    #+#             */
/*   Updated: 2020/08/09 20:49:44 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_valid_base(char *base, int base_len)
{
	char	current;
	int		i;
	int		j;

	if (base_len < 2)
		return (0);
	i = 0;
	while (base[i])
	{
		current = base[i];
		if (current == '+' || current == '-')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[j] == current)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long int	long_nbr;
	int			base_len;

	base_len = ft_strlen(base);
	if (!ft_valid_base(base, base_len))
		return ;
	long_nbr = nbr;
	if (long_nbr < 0)
	{
		ft_putchar('-');
		long_nbr *= -1;
	}
	if (long_nbr >= base_len)
		ft_putnbr_base(long_nbr / base_len, base);
	ft_putchar(base[long_nbr % base_len]);
}
