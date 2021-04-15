/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyoule <jaeyoule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 22:08:26 by jaeyoule          #+#    #+#             */
/*   Updated: 2021/04/13 22:12:00 by jaeyoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int num;

	num = 1;
	if (nb < 0)
		return (0);
	while (nb > 1)
	{
		num *= nb;
		--nb;
	}
	return (num);
}
