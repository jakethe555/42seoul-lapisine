/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ext_convert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyoule <jaeyoule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 14:29:09 by jaeyoule          #+#    #+#             */
/*   Updated: 2021/04/11 14:04:28 by jaeyoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int		find_match(char **key_set, char *target)
{
	int i;
	int j;
	int key_i;
	int found;

	key_i = 0;
	found = 0;
	while (key_i <= g_key_num && found == 0)
	{
		j = 0;
		i = 0;
		if (key_set[key_i][j] == target[i])
		{
			found = 1;
			while (target[i++])
			{
				if (key_set[key_i][++j] != target[i])
					found = 0;
			}
		}
		++key_i;
	}
	if (found == 0)
		return (-1);
	return (--key_i);
}

int		null_return(char *target)
{
	int i;

	i = 0;
	while (target[i])
		++i;
	return (i);
}

void	call_dict(char **key_set, char **value_set, char *target)
{
	int key_i;
	int i;
	int null_place;

	i = 0;
	key_i = find_match(key_set, target);
	if (key_i == -1)
	{
		g_error = 0;
		return ;
	}
	null_place = null_return(&g_print[0]);
	while (value_set[key_i][i])
	{
		g_print[null_place] = value_set[key_i][i];
		++null_place;
		++i;
	}
	g_print[null_place] = ' ';
}

int		digit_return(char *str)
{
	int i;

	i = 0;
	while (str[i])
		++i;
	--i;
	return (i);
}

void	zero_call(char **key_set, char **value_set, char *num, int i)
{
	char	target[2];

	target[0] = num[i];
	target[1] = '\0';
	call_dict(key_set, value_set, &target[0]);
}
