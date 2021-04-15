/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyoule <jaeyoule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 21:10:32 by jaeyoule          #+#    #+#             */
/*   Updated: 2021/04/06 22:12:28 by jaeyoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		power_ten(int n)
{
	int i;
	int x;

	i = 0;
	x = 1;
	while (i++ < n)
		x *= 10;
	return (x);
}

void	ft_putnbr(int nb, char *str, int n, int i)
{
	int div;

	if (i == n)
		return ;
	div = power_ten(n - 1 - i);
	str[i] = '0' + (nb / div) % 10;
	ft_putnbr(nb, str, n, ++i);
}

int		filter_num(int n, char *num)
{
	int i;
	int print;

	print = 1;
	i = 0;
	while (i < n - 1)
	{
		print = num[i] < num[i + 1];
		if (print == 0)
			return (print);
		i++;
	}
	return (print);
}

void	ft_print_combn_valid(int n)
{
	char	num[n];
	int		nb;
	int		print;
	int		print_comma;
	int		max;

	nb = 0;
	max = power_ten(n);
	print = 0;
	while (nb < max)
	{
		ft_putnbr(nb, &num[0], n, 0);
		print = filter_num(n, &num[0]);
		if (print == 1)
		{
			if (print_comma == 1)
				write(1, ", ", 2);
			write(1, &num, n);
			print_comma = 1;
		}
		nb = (nb == 23456789) ? nb + 100000000 : nb + 1;
		if (nb == 123456790)
			break ;
	}
}

void	ft_print_combn(int n)
{
	if (n >= 10 || n <= 0)
		write(1, "not valid input", 15);
	else
	{
		ft_print_combn_valid(n);
	}
}
