/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 20:52:50 by clbrunet          #+#    #+#             */
/*   Updated: 2020/08/18 20:36:38 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_is_str_contains(char *str, char c)
{
	int		i;

	i = 0;
	while (str[i])
		if (str[i++] == c)
			return (1);
	return (0);
}

int		ft_count_strs(char *str, char *charset)
{
	int		count;
	int		i;
	int		j;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && ft_is_str_contains(charset, str[i]))
			i++;
		j = i;
		while (str[j] && !ft_is_str_contains(charset, str[j]))
		{
			if (j == i)
				count++;
			j++;
		}
		i = (str[j]) ? j : j - 1;
		i++;
	}
	return (count);
}

int		ft_malloc_strs(char **strs, char *str, char *charset)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	while (str[i])
	{
		j = i;
		while (str[j] && ft_is_str_contains(charset, str[j]))
			j++;
		i = j;
		while (str[j] && !ft_is_str_contains(charset, str[j]))
			j++;
		if (j != i)
		{
			if (!(strs[k] = malloc(sizeof(char) * (j - i + 1))))
				return (0);
			k++;
		}
		i = (str[j]) ? j : j - 1;
		i++;
	}
	return (1);
}

int		ft_fill_strs(char **strs, char *str, char *charset)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] && ft_is_str_contains(charset, str[i]))
			i++;
		k = 0;
		while (str[i] && !ft_is_str_contains(charset, str[i]))
		{
			strs[j][k] = str[i];
			i++;
			k++;
		}
		if (k != 0)
			strs[j][k] = 0;
		j += (k == 0) ? 0 : 1;
		i += (str[i]) ? 1 : 0;
	}
	return (1);
}

char	**ft_split(char *str, char *charset)
{
	char	**strs;
	int		count;

	count = ft_count_strs(str, charset);
	if (!(strs = malloc(sizeof(char *) * (count + 1))))
		return (NULL);
	strs[count] = NULL;
	if (!ft_malloc_strs(strs, str, charset))
		return (NULL);
	ft_fill_strs(strs, str, charset);
	return (strs);
}
