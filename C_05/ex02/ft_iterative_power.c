/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 12:16:58 by clbrunet          #+#    #+#             */
/*   Updated: 2020/08/11 12:39:34 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_power(int nb, int power)
{
	int		backup_nb;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	backup_nb = nb;
	while (--power)
		nb *= backup_nb;
	return (nb);
}
