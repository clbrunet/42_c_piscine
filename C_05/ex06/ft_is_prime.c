/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 14:03:56 by clbrunet          #+#    #+#             */
/*   Updated: 2020/08/11 16:43:38 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt(int nb)
{
	int		i;

	if (nb < 1)
		return (0);
	i = 1;
	while (i <= 46340)
	{
		if (nb <= i * i)
			return (i);
		i++;
	}
	return (46341);
}

int		ft_is_prime(int nb)
{
	int		i;
	int		sqrt_nb;

	if (nb <= 1)
		return (0);
	if (nb == 2)
		return (1);
	if (nb % 2 == 0)
		return (0);
	i = 3;
	sqrt_nb = ft_sqrt(nb);
	while (i <= sqrt_nb)
	{
		if (nb % i == 0)
			return (0);
		i += 2;
	}
	return (1);
}
