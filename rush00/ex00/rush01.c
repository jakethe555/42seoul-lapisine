/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyoule <jaeyoule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 18:20:49 by jaeyoule          #+#    #+#             */
/*   Updated: 2021/03/28 18:28:01 by jaeyoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int in_x;
	int in_y;

	in_x = 0;
	in_y = 0;
	while (in_y++ < y)
	{
		while (in_x++ < x)
		{
			if (in_y == 1 || in_y == y)
			{
				if ((in_x == 1 && in_y == 1) || (in_x == x && in_y == y))
					ft_putchar('/');
				else if ((in_x == x && in_y == 1) || (in_x == 1 && in_y == y))
					ft_putchar('\\');
				else
					ft_putchar('*');
			}
			else
				ft_putchar((in_x == 1 || in_x == x) ? '*' : ' ');
		}
		ft_putchar('\n');
		in_x = 0;
	}
}
