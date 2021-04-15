/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyoule <jaeyoule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 14:29:09 by jaeyoule          #+#    #+#             */
/*   Updated: 2021/04/11 06:17:44 by ekwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void	one_digit_call(char **key_set, char **value_set, char *num, int i)
{
	char target[2];

	target[0] = num[i];
	target[1] = '\0';
	if (num[i] != '0')
	{
		call_dict(key_set, value_set, &target[0]);
		g_max_digit = 0;
	}
}

void	two_digit_call(char **key_set, char **value_set, char *num, int i)
{
	char target[3];
	char f_target[3];

	target[0] = num[i - 1];
	target[1] = num[i];
	target[2] = '\0';
	f_target[0] = '0';
	f_target[1] = num[i];
	f_target[2] = '\0';
	if (target[1] >= '2')
	{
		call_dict(key_set, value_set, &f_target[0]);
		one_digit_call(key_set, value_set, num, i - 1);
		g_max_digit = 0;
	}
	else if (target[1] == '1')
	{
		call_dict(key_set, value_set, &target[0]);
		g_max_digit = 0;
	}
	else
		one_digit_call(key_set, value_set, num, i - 1);
}

void	three_digit_call(char **key_set, char **value_set, char *num, int i)
{
	if (num[i] != '0')
	{
		one_digit_call(key_set, value_set, num, i);
		call_dict(key_set, value_set, "001");
		g_max_digit = 0;
	}
	two_digit_call(key_set, value_set, num, i - 1);
}

void	four_digit_call(char **key_set, char **value_set, char *num, int i)
{
	int		idx;
	char	int_1000[i + 2];
	int		max;

	max = i;
	idx = 0;
	while (i >= 3)
	{
		idx = 0;
		while (idx < i)
		{
			int_1000[idx] = '0';
			++idx;
		}
		int_1000[idx] = '1';
		int_1000[++idx] = '\0';
		if (num[i] != '0' || g_max_digit == 0)
		{
			call_dict(key_set, value_set, &int_1000[0]);
			g_max_digit = 1;
		}
		three_digit_call(key_set, value_set, num, i - 1);
		i -= 3;
	}
}

void	parsing(char **key_set, char **value_set, char *num, int i)
{
	i = digit_return(num);
	if (i % 3 == 0)
	{
		if (num[i] == '0' && i == 0)
			zero_call(key_set, value_set, num, i);
		else
		{
			one_digit_call(key_set, value_set, num, i);
			if (i != 0)
				four_digit_call(key_set, value_set, num, i);
		}
	}
	else if (i % 3 == 1)
	{
		two_digit_call(key_set, value_set, num, i);
		if (i > 3)
			four_digit_call(key_set, value_set, num, i - 1);
	}
	else if (i % 3 == 2)
	{
		three_digit_call(key_set, value_set, num, i);
		if (i > 3)
			four_digit_call(key_set, value_set, num, i - 2);
	}
}
