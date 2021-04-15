/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyoule <jaeyoule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 17:02:30 by jaeyoule          #+#    #+#             */
/*   Updated: 2021/04/06 22:34:32 by jaeyoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_non_printable(char *str)
{
	int		i;
	int		hex_1;
	int		hex_2;

	i = 0;
	while (str[i])
	{
		if (str[i] < 32 || str[i] >= 127)
		{
			hex_1 = str[i] / 16;
			hex_2 = str[i] % 16;
			write(1, "\\", 1);
			write(1, &"0123456789abcdef"[hex_1], 1);
			write(1, &"0123456789abcdef"[hex_2], 1);
		}
		else
			write(1, &str[i], 1);
		i++;
	}
}
