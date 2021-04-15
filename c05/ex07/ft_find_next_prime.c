/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyoule <jaeyoule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 23:11:09 by jaeyoule          #+#    #+#             */
/*   Updated: 2021/04/15 18:27:50 by jaeyoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_prime(int nb)
{
	long long int div;

	if (nb < 2)
		return (0);
	if (nb == 2 || nb == 3)
		return (1);
	div = 2;
	while (div * div <= nb)
	{
		if (nb % div == 0)
			return (0);
		++div;
	}
	return (1);
}

int		ft_find_next_prime(int nb)
{
	if (nb < 2)
		return (2);
	while (ft_is_prime(nb) == 0)
		++nb;
	return (nb);
}
