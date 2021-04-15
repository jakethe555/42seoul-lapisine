/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ext_extra.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwon <ekwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 23:25:01 by ekwon             #+#    #+#             */
/*   Updated: 2021/04/11 17:13:35 by jaeyoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void	fstr_check_front(char *fstr, int *idx, int *k)
{
	while (fstr[*idx] != ' ' && fstr[*idx] != ':' && fstr[*idx] != '\0')
	{
		if (fstr[*idx] < '0' || fstr[*idx] > '9')
			g_error = 0;
		*idx = *idx + 1;
		*k = *k + 1;
	}
}

void	fstr_check_middle(char *fstr, int *idx)
{
	int check_point;

	check_point = 0;
	while (fstr[*idx] == ' ' || fstr[*idx] == ':')
	{
		if (fstr[*idx] == ':')
			check_point = 1;
		*idx = *idx + 1;
	}
	if (check_point == 0)
		g_error = 0;
}

void	fstr_check_back(char *fstr, int *idx)
{
	if (fstr[*idx] < 32 || fstr[*idx] > 126)
		g_error = 0;
	while (fstr[*idx] == ' ' && fstr[*idx - 1] == ' ')
		++*idx;
}

void	delete_space_b(char **value_set, int i)
{
	int idx;
	int max;

	max = null_return(value_set[i]);
	idx = max;
	while (idx > 0 && value_set[i][idx - 1] == ' ')
		--idx;
	value_set[i][idx] = '\0';
}
