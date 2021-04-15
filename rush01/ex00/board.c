/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhong <mhong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 22:01:12 by jaeyoule          #+#    #+#             */
/*   Updated: 2021/04/04 23:13:01 by mhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int		is_space(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int		argv_check(char *av, int i, int count)
{
	int flag;

	flag = 1;
	while (av[i] != '\0')
	{
		if (av[0] == ' ')
			return (0);
		if (is_space(av[i]))
		{
			i++;
			flag = 1;
		}
		if (av[i] >= '1' && av[i] <= '4' && flag == 1)
		{
			flag = 0;
			if (count == 16)
				return (0);
			g_condition_input[count++] = av[i] - '0';
		}
		else
			return (0);
		i++;
	}
	return (1);
}

void	condition(int *condition)
{
	int i;
	int r;
	int c;

	i = 0;
	r = 0;
	c = 0;
	while (r < 2)
	{
		c = 0;
		while (c < 4)
		{
			g_col_condition[r][c] = condition[i];
			g_row_condition[r][c] = condition[i + 8];
			c++;
			i++;
		}
		r++;
	}
}

void	init_board(void)
{
	int i;
	int j;

	g_fixed_cnt = 16;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			g_board[i][j].val = 0;
			g_board[i][j++].is_fixed = 0;
		}
		i++;
	}
}

int		check_fill(int i, int j, int value)
{
	if (g_board[i][j].is_fixed == 0)
	{
		g_fixed_cnt--;
		g_board[i][j].val = value;
		g_board[i][j].is_fixed = 1;
	}
	else if (g_board[i][j].is_fixed == 1)
		if (g_board[i][j].val != value)
			return (0);
	return (1);
}
