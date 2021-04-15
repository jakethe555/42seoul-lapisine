/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyoule <jaeyoule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 18:48:54 by jaeyoule          #+#    #+#             */
/*   Updated: 2021/03/28 16:36:25 by jaeyoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int	current_x;
	int	current_y;

	current_x = 0;
	current_y = 0;
	while (current_y++ < y)
	{
		while (current_x++ < x)
		{
			if (current_y == 1 || current_y == y)
			{
				if (current_x != x || x == 1)
					ft_putchar((current_x == 1) ? 'A' : 'B');
				else
					ft_putchar('C');
			}
			else
				ft_putchar((current_x == 1 || current_x == x) ? 'B' : ' ');
		}
		ft_putchar('\n');
		current_x = 0;
	}
}
