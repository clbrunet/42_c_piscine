/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 11:44:31 by clbrunet          #+#    #+#             */
/*   Updated: 2020/08/14 14:03:29 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_itoa_base(char *str, long int nb, char *base, int i);
int		ft_calculate_len(long int nb, int base_len, int len);
char	*ft_move_to_nbr(char *nbr, int *sign);
int		ft_calulate_nb(char *nbr, long int *nb, char *base_from);
char	*ft_convert_base(char *nbr, char *base_from, char *base_to);

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_is_base_correct(char *base)
{
	int		base_len;
	int		i;
	int		j;

	base_len = ft_strlen(base);
	if (base_len < 2)
		return (0);
	i = 0;
	while (base[i])
	{
		j = i + 1;
		if (base[i] == ' ' || ('\t' <= base[i] && base[i] <= '\r')
				|| base[i] == '-' || base[i] == '+')
			return (0);
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		ft_is_str_contains(char c, char *str)
{
	while (*str)
	{
		if (c == *str)
			return (1);
		str++;
	}
	return (0);
}
