/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyoule <jaeyoule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 18:48:54 by jaeyoule          #+#    #+#             */
/*   Updated: 2021/03/28 14:46:07 by jaeyoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int	current_x;
	int	current_y;

	current_x = 0;
	current_y = 0;
	while
		(current_y++ < y)
	{
		while
			(current_x++ < x)
		{
			if
				(current_y == 1 || current_y == y)
				ft_putchar((current_x == 1 || current_x == x) ? 'o' : '-');
			else
				ft_putchar((current_x == 1 || current_x == x) ? '|' : ' ');
		}
		ft_putchar('\n');
		current_x = 0;
	}
}
