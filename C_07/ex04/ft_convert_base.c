/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 15:12:56 by clbrunet          #+#    #+#             */
/*   Updated: 2020/08/18 11:50:49 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str);
int		ft_is_base_correct(char *base);
int		ft_is_str_contains(char c, char *str);

void	ft_itoa_base(char *str, long int nb, char *base, int i)
{
	int		base_len;

	base_len = ft_strlen(base);
	if (nb >= base_len)
		ft_itoa_base(str, nb / base_len, base, i - 1);
	str[i] = base[nb % base_len];
}

int		ft_calculate_len(long int nb, int base_len, int len)
{
	if (nb >= base_len)
		return (ft_calculate_len(nb / base_len, base_len, len + 1));
	return (len);
}

char	*ft_move_to_nbr(char *nbr, int *sign)
{
	while (*nbr == ' ' || ('\t' <= *nbr && *nbr <= '\r'))
		nbr++;
	*sign = 1;
	while (*nbr == '-' || *nbr == '+')
	{
		if (*nbr == '-')
			*sign *= -1;
		nbr++;
	}
	return (nbr);
}

void	ft_calulate_nb(char *nbr, long int *nb, char *base_from)
{
	int		i;

	*nb = 0;
	while (*nbr && ft_is_str_contains(*nbr, base_from))
	{
		i = 0;
		while (*nbr != base_from[i])
			i++;
		*nb = *nb * ft_strlen(base_from) + i;
		nbr++;
	}
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char		*str;
	long int	nb;
	int			i;
	int			sign;

	if (!ft_is_base_correct(base_from) || !ft_is_base_correct(base_to))
		return (NULL);
	nbr = ft_move_to_nbr(nbr, &sign);
	ft_calulate_nb(nbr, &nb, base_from);
	if (nb == 0)
		sign = 1;
	i = ft_calculate_len(nb, ft_strlen(base_to), ((sign == 1) ? 1 : 2));
	if (!(str = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[0] = ((sign == 1) ? '+' : '-');
	ft_itoa_base(str, nb, base_to, i - 1);
	str[i] = 0;
	return (str);
}
