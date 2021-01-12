/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 15:44:47 by clbrunet          #+#    #+#             */
/*   Updated: 2020/08/09 16:16:15 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int		i;
	int		j;
	int		k;

	if (!(*to_find))
		return (str);
	i = 0;
	while (str[i])
	{
		j = i;
		k = 0;
		while (str[j] == to_find[k] || !(to_find[k]))
		{
			if (!(to_find[k]))
				return (str + j - k);
			k++;
			j++;
		}
		i++;
	}
	return (0);
}
