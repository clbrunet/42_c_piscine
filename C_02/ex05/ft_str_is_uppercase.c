/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 12:47:26 by clbrunet          #+#    #+#             */
/*   Updated: 2020/08/07 14:57:20 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_is_uppercase(char *str)
{
	while (*str)
	{
		if (!('A' <= *str && *str <= 'Z'))
			return (0);
		str++;
	}
	return (1);
}