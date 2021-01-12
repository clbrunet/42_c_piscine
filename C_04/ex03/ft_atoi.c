/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 17:03:46 by clbrunet          #+#    #+#             */
/*   Updated: 2020/08/10 15:24:02 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isspace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t'
			|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	else
		return (0);
}

int		ft_atoi(char *str)
{
	long int	nb;
	int			sign;

	while (*str && ft_isspace(*str))
		str++;
	sign = 1;
	while (*str && (*str == '-' || *str == '+'))
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	nb = 0;
	while (*str && ('0' <= *str && *str <= '9'))
	{
		nb *= 10;
		nb += *str - '0';
		str++;
	}
	nb *= sign;
	return (nb);
}
