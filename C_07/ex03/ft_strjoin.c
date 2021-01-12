/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 12:00:20 by clbrunet          #+#    #+#             */
/*   Updated: 2020/08/13 15:05:17 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int		i;
	int		j;

	i = 0;
	while (dest[i])
		i++;
	j = 0;
	while (src[j])
		dest[i++] = src[j++];
	dest[i] = 0;
	return (dest);
}

char	*ft_is_size_null(void)
{
	char	*str;

	if (!(str = malloc(sizeof(*str) * 1)))
		return (NULL);
	str[0] = 0;
	return (str);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str;
	int		len;
	int		i;

	if (size == 0)
		return (ft_is_size_null());
	len = 0;
	i = 0;
	while (i < size)
		len += ft_strlen(strs[i++]);
	len += ft_strlen(sep) * (size - 1);
	if (!(str = malloc(sizeof(*str) * (len + 1))))
		return (NULL);
	str[0] = 0;
	i = 0;
	while (i < size)
	{
		ft_strcat(str, strs[i++]);
		if (i != size)
			ft_strcat(str, sep);
	}
	return (str);
}
