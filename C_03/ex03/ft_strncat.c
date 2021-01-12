/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 14:05:56 by clbrunet          #+#    #+#             */
/*   Updated: 2020/08/08 15:43:50 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int				i;
	unsigned int	count;

	i = 0;
	while (dest[i])
		i++;
	count = 0;
	while (*src && count++ < nb)
		dest[i++] = *(src++);
	dest[i] = '\0';
	return (dest);
}
