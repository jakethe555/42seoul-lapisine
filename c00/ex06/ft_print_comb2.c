/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyoule <jaeyoule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 13:30:23 by jaeyoule          #+#    #+#             */
/*   Updated: 2021/04/01 15:38:23 by jaeyoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_update_2(char *numb_set)
{
	while (numb_set[3] <= '9')
	{
		while (numb_set[4] <= '9')
		{
			write(1, numb_set, 5);
			if (numb_set[0] != '9' || numb_set[1] != '8')
				write(1, ", ", 2);
			numb_set[4]++;
		}
		numb_set[3]++;
		numb_set[4] = '0';
	}
}

void	ft_print_comb2(void)
{
	char	numb_set[5];

	numb_set[0] = '0';
	numb_set[1] = '0';
	numb_set[2] = ' ';
	numb_set[3] = '0';
	numb_set[4] = '1';
	while (numb_set[0] <= '9')
	{
		while (numb_set[1] <= '9')
		{
			if (numb_set[0] == '9' && numb_set[1] == '9')
				break ;
			print_update_2(&numb_set[0]);
			numb_set[1]++;
			numb_set[4] = (numb_set[1] > '9') ? '0' : numb_set[1] + 1;
			numb_set[3] = (numb_set[1] > '9') ? numb_set[0] + 1 : numb_set[0];
		}
		numb_set[0]++;
		numb_set[1] = '0';
		numb_set[3] = numb_set[0];
		numb_set[4] = numb_set[1] + 1;
	}
}
