/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 12:27:22 by clbrunet          #+#    #+#             */
/*   Updated: 2020/08/19 17:08:00 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		ft_check_errors(char *op_str, int nb2)
{
	if (op_str[1] != 0 || !(op_str[0] == '+' || op_str[0] == '-'
				|| op_str[0] == '/' || op_str[0] == '*' || op_str[0] == '%'))
	{
		ft_putstr("0\n");
		return (1);
	}
	if (nb2 == 0 && (op_str[0] == '/' || op_str[0] == '%'))
	{
		if (op_str[0] == '/')
			ft_putstr("Stop : division by zero\n");
		if (op_str[0] == '%')
			ft_putstr("Stop : modulo by zero\n");
		return (1);
	}
	return (0);
}

void	ft_initialize_op_calc(int (*op_calc[5])(int, int))
{
	op_calc[0] = &addition;
	op_calc[1] = &substraction;
	op_calc[2] = &division;
	op_calc[3] = &multiplication;
	op_calc[4] = &modulo;
}

int		ft_do_op(int (*op_calc[5])(int, int), int nb1, char op, int nb2)
{
	if (op == '+')
		return ((*op_calc[0])(nb1, nb2));
	if (op == '-')
		return ((*op_calc[1])(nb1, nb2));
	if (op == '/')
		return ((*op_calc[2])(nb1, nb2));
	if (op == '*')
		return ((*op_calc[3])(nb1, nb2));
	if (op == '%')
		return ((*op_calc[4])(nb1, nb2));
	return (0);
}

int		main(int ac, char **av)
{
	int		(*op_calc[5])(int, int);
	int		nb1;
	int		nb2;

	if (ac != 4)
		return (1);
	nb1 = ft_atoi(av[1]);
	nb2 = ft_atoi(av[3]);
	if (ft_check_errors(av[2], nb2))
		return (1);
	ft_initialize_op_calc(op_calc);
	ft_putnbr(ft_do_op(op_calc, nb1, av[2][0], nb2));
	ft_putstr("\n");
	return (0);
}
