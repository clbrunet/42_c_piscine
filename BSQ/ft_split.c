/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 20:52:50 by clbrunet          #+#    #+#             */
/*   Updated: 2020/08/26 14:41:54 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_is_str_contains(char *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

int		ft_count_strs(char *str, char *charset)
{
	int		count;
	int		i;
	int		is_first;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && ft_is_str_contains(charset, str[i]))
			i++;
		is_first = 1;
		while (str[i] && !ft_is_str_contains(charset, str[i]))
		{
			if (is_first)
			{
				count++;
				is_first = 0;
			}
			i++;
		}
	}
	return (count);
}

int		ft_malloc_strs(char **strs, char *str, char *charset, int count)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	while (str[i] && k < count)
	{
		while (str[i] && ft_is_str_contains(charset, str[i]))
			i++;
		j = i;
		while (str[j] && !ft_is_str_contains(charset, str[j]))
			j++;
		if (!(strs[k] = malloc(sizeof(char) * (j - i + 1))))
			return (0);
		k++;
		i = j;
	}
	return (1);
}

void	ft_fill_strs(char **strs, char *str, char *charset, int count)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	while (str[i] && j < count)
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
		strs[j][k] = 0;
		j++;
	}
}

char	**ft_split(char *str, char *charset)
{
	char	**strs;
	int		count;

	count = ft_count_strs(str, charset);
	if (!(strs = malloc(sizeof(char *) * (count + 1))))
		return (NULL);
	strs[count] = NULL;
	if (!ft_malloc_strs(strs, str, charset, count))
		return (NULL);
	ft_fill_strs(strs, str, charset, count);
	return (strs);
}
