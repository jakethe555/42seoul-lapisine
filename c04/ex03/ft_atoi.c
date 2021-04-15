/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyoule <jaeyoule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 17:37:40 by jaeyoule          #+#    #+#             */
/*   Updated: 2021/04/12 16:29:39 by jaeyoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		space_check(char *str, int i)
{
	while (str[i])
	{
		if (('\t' <= str[i] && str[i] <= '\r') || str[i] == ' ')
			i++;
		else
			return (i);
	}
	return (i);
}

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

int		ft_atoi(char *str)
{
	int			i;
	long int	num;
	int			sign;

	num = 0;
	i = space_check(str, 0);
	sign = sign_check(str, &i);
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		++i;
	}
	return ((int)num * sign);
}
