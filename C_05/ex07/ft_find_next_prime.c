/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 14:51:56 by clbrunet          #+#    #+#             */
/*   Updated: 2020/08/11 16:33:12 by clbrunet         ###   ########.fr       */
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

int		ft_find_next_prime(int nb)
{
	int		i;
	int		sqrt_nb;

	if (nb <= 1 || nb == 2)
		return (2);
	if (nb % 2 == 0)
		return (ft_find_next_prime(nb + 1));
	sqrt_nb = ft_sqrt(nb);
	i = 3;
	while (i <= sqrt_nb)
	{
		if (nb % i == 0)
			break ;
		i += 2;
	}
	if (nb % i == 0)
		return (ft_find_next_prime(nb + 2));
	return (nb);
}
