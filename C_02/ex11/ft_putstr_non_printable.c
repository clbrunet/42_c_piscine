/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 10:59:30 by clbrunet          #+#    #+#             */
/*   Updated: 2020/08/09 09:58:27 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_non_printable(char *str)
{
	unsigned char	c;
	char			*hex;

	hex = "0123456789abcdef";
	while (*str)
	{
		c = (unsigned char)*str;
		if (' ' <= c && c <= '~')
			write(1, &c, 1);
		else
		{
			write(1, "\\", 1);
			write(1, &(hex[c / 16]), 1);
			write(1, &(hex[c % 16]), 1);
		}
		str++;
	}
}
