/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyoule <jaeyoule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 17:39:35 by jaeyoule          #+#    #+#             */
/*   Updated: 2021/04/07 14:00:34 by jaeyoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(char *s1, char *s2)
{
	int i;
	int diff;
	int loop_out;

	i = 0;
	loop_out = 0;
	while (loop_out == 0)
	{
		diff = s1[i] - s2[i];
		if (diff != 0)
			loop_out = 1;
		if (s1[i] == '\0')
		{
			diff = 0 - s2[i];
			loop_out = 1;
		}
		if (s2[i] == '\0')
		{
			diff = s1[i] - 0;
			loop_out = 1;
		}
		++i;
	}
	return (diff);
}
