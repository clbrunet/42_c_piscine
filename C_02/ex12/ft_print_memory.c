/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 11:48:17 by clbrunet          #+#    #+#             */
/*   Updated: 2020/08/11 09:33:53 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void			ft_putchar(char c)
{
	write(1, &c, 1);
}

void			ft_putaddr_hex(long long int long_nbr, int pos)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (long_nbr < 0)
	{
		ft_putchar('-');
		long_nbr *= -1;
	}
	if (pos < 15)
		ft_putaddr_hex(long_nbr / 16, pos + 1);
	ft_putchar(hex[long_nbr % 16]);
}

void			ft_print_content_hex(char *str, unsigned int size,
		unsigned int j)
{
	unsigned int	k;
	char			*hex;

	k = 0;
	hex = "0123456789abcdef";
	while (j <= size && k < 16)
	{
		ft_putchar(hex[str[j] / 16]);
		ft_putchar(hex[str[j] % 16]);
		if (k % 2 == 1)
			ft_putchar(' ');
		j++;
		k++;
	}
	while (k < 16)
	{
		ft_putchar(' ');
		ft_putchar(' ');
		if (k % 2 == 1)
			ft_putchar(' ');
		k++;
	}
}

unsigned int	ft_print_content(char *str, unsigned int size, unsigned int i)
{
	unsigned int	k;

	k = 0;
	while (i <= size && k < 16)
	{
		if (!(' ' <= str[i] && str[i] <= '~'))
			ft_putchar('.');
		else
			ft_putchar(str[i]);
		k++;
		i++;
	}
	return (i);
}

void			*ft_print_memory(void *addr, unsigned int size)
{
	long int		long_addr;
	unsigned int	i;
	char			*str;

	if (!size)
		return (addr);
	str = (char *)addr;
	i = 0;
	long_addr = (long int)addr;
	while (i <= size)
	{
		ft_putaddr_hex(long_addr + i, 0);
		ft_putchar(':');
		ft_putchar(' ');
		ft_print_content_hex(str, size, i);
		i = ft_print_content(str, size, i);
		ft_putchar('\n');
	}
	return (addr);
}
