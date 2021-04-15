/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyoule <jaeyoule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 16:20:00 by jaeyoule          #+#    #+#             */
/*   Updated: 2021/03/31 17:04:00 by jaeyoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int i;
	int max_i;
	int temp;

	i = 0;
	max_i = size - 1;
	while (i < size / 2)
	{
		temp = tab[i];
		tab[i] = tab[max_i - i];
		tab[max_i - i] = temp;
		i++;
	}
}
