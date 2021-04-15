/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyoule <jaeyoule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 16:29:09 by jaeyoule          #+#    #+#             */
/*   Updated: 2021/04/13 01:47:18 by jaeyoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		sign_check(char *str, int *i)
{
	int sign;

	sign = 1;
	while (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			sign *= -1;
		*i = *i + 1;
	}
	return (sign);
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
		if (base[i] == '+' || base[i] == '-' ||
				('\t' <= base[i] && base[i] <= '\r') || base[i] == ' ')
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

int		is_c_in_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != c && base[i])
		++i;
	if (base[i] == '\0')
		return (0);
	else
		return (1);
}

int		match_base(char c, char *base)
{
	int i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		++i;
	}
	return (i);
}

int		ft_atoi_base(char *str, char *base)
{
	int			i;
	long int	num;
	int			sign;
	int			base_num;

	num = 0;
	i = 0;
	base_num = 0;
	while (str[i] && (('\t' <= str[i] && str[i] <= '\r') || str[i] == ' '))
		++i;
	sign = sign_check(str, &i);
	while (base[base_num])
		++base_num;
	if (base_num < 2 || check_base(base) == 1)
		return (num);
	while (str[i] && is_c_in_base(str[i], base))
	{
		num = num * base_num + match_base(str[i], base);
		++i;
	}
	return ((int)num * sign);
}
