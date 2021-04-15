/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyoule <jaeyoule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 22:35:14 by jaeyoule          #+#    #+#             */
/*   Updated: 2021/04/13 22:45:46 by jaeyoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_power(int nb, int power)
{
	int num;

	num = 1;
	if (power == 0)
		return (1);
	else if (power < 0)
		return (0);
	while (power >= 1)
	{
		num *= nb;
		--power;
	}
	return (num);
}
