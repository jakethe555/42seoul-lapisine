/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjul <seungjul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 15:56:47 by seungjul          #+#    #+#             */
/*   Updated: 2021/03/28 18:09:19 by seungjul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int current_x;
	int current_y;

	current_x = 0;
	current_y = 0;
	while
		(current_y++ < y)
	{
		while
			(current_x++ < x)
		{
			if
				(current_y == 1)
				ft_putchar((current_x == 1 || current_x == x) ? 'A' : 'B');
			else if
				(current_y == y)
				ft_putchar((current_x == 1 || current_x == x) ? 'C' : 'B');
			else
				ft_putchar((current_x == 1 || current_x == x) ? 'B' : ' ');
		}
		ft_putchar('\n');
		current_x = 0;
	}
}
