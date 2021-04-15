/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyoule <jaeyoule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 12:50:11 by jaeyoule          #+#    #+#             */
/*   Updated: 2021/04/01 15:33:22 by jaeyoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void)
{
	char numb_set[3];

	numb_set[0] = '0';
	numb_set[1] = '1';
	numb_set[2] = '2';
	while (numb_set[0] <= '7')
	{
		write(1, &numb_set, 3);
		if (numb_set[0] != '7')
			write(1, ", ", 2);
		numb_set[2]++;
		if (numb_set[2] > '9')
		{
			numb_set[1]++;
			numb_set[2] = numb_set[1] + 1;
			if (numb_set[1] > '8')
			{
				numb_set[0]++;
				numb_set[1] = numb_set[0] + 1;
				numb_set[2] = numb_set[1] + 1;
			}
		}
	}
}
