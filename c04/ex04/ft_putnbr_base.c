/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyoule <jaeyoule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 16:29:09 by jaeyoule          #+#    #+#             */
/*   Updated: 2021/04/12 23:18:17 by jaeyoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		convert(long int nbr, int base_num, long int *c_nbr, int digit)
{
	*c_nbr = *c_nbr + (nbr % base_num) * digit;
	if (nbr / base_num == 0)
		return (digit);
	digit = convert(nbr / base_num, base_num, c_nbr, digit * 10);
	return (digit);
}

void	print(long int c_nbr, int digit, char *base)
{
	int i;

	if (digit == 0)
		return ;
	i = c_nbr / digit;
	c_nbr -= i * digit;
	write(1, &base[i], 1);
	print(c_nbr, digit / 10, base);
}

int		check_base(char *base)
{
	int i;
	int check_idx;
	int error;

	i = 0;
	check_idx = 0;
	error = 0;
	while (base[i])
	{
		check_idx = 0;
		if (base[i] == '+' || base[i] == '-')
			error = 1;
		while (base[check_idx])
		{
			if (base[check_idx] == base[i] && i != check_idx)
				error = 1;
			++check_idx;
		}
		++i;
	}
	return (error);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int			base_num;
	long int	c_nbr;
	int			digit;
	long int	storage;

	storage = nbr;
	base_num = 0;
	while (base[base_num])
		++base_num;
	if (check_base(base) == 1)
		return ;
	c_nbr = 0;
	if (base_num < 2)
		return ;
	if (nbr < 0)
	{
		storage *= -1;
		write(1, "-", 1);
	}
	digit = convert(storage, base_num, &c_nbr, 1);
	print(c_nbr, digit, base);
}
