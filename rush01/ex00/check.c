/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhong <mhong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 21:54:09 by dohlim            #+#    #+#             */
/*   Updated: 2021/04/04 22:47:15 by mhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void	val_check(bool *used_val_check, int col_num, int row_num)
{
	int col_idx;
	int row_idx;

	col_idx = 0;
	row_idx = 0;
	while (col_idx <= 4)
		used_val_check[col_idx++] = false;
	col_idx = 0;
	while (col_idx < col_num)
	{
		used_val_check[g_board[row_num][col_idx++].val] = true;
	}
	row_idx = 0;
	while (row_idx < row_num)
	{
		used_val_check[g_board[row_idx++][col_num].val] = true;
	}
}

bool	is_valid_col(int col_num, bool is_top)
{
	int cnt;
	int max_num;
	int row_num;
	int diff;

	cnt = 0;
	max_num = -1;
	row_num = (is_top ? 0 : 3);
	diff = (is_top ? 1 : -1);
	while (0 <= row_num && row_num <= 3)
	{
		if (max_num < g_board[row_num][col_num].val)
		{
			cnt++;
			max_num = g_board[row_num][col_num].val;
		}
		row_num += diff;
	}
	if (cnt == g_col_condition[!is_top][col_num])
		return (true);
	else
		return (false);
}

bool	is_valid_row(int row_num, bool is_left)
{
	int cnt;
	int max_num;
	int col_num;
	int diff;

	cnt = 0;
	max_num = -1;
	col_num = (is_left ? 0 : 3);
	diff = (is_left ? 1 : -1);
	while (0 <= col_num && col_num <= 3)
	{
		if (max_num < g_board[row_num][col_num].val)
		{
			cnt++;
			max_num = g_board[row_num][col_num].val;
		}
		col_num += diff;
	}
	if (cnt == g_row_condition[!is_left][row_num])
		return (true);
	else
		return (false);
}

bool	check_top_bottom_valid(void)
{
	int col_idx;
	int row_idx;

	row_idx = 0;
	col_idx = 0;
	while (col_idx < 4)
	{
		if (!is_valid_col(col_idx, true) || !is_valid_col(col_idx, false))
		{
			return (false);
		}
		col_idx++;
	}
	while (row_idx < 4)
	{
		if (!is_valid_row(row_idx, true) || !is_valid_row(row_idx, false))
		{
			return (false);
		}
		row_idx++;
	}
	print_board();
	return (true);
}

bool	check_condition(void)
{
	int idx;

	idx = 0;
	while (idx < 4)
	{
		if (g_row_condition[0][idx] == 1 && g_row_condition[1][idx] == 1)
			return (false);
		if (g_col_condition[0][idx] == 1 && g_col_condition[1][idx] == 1)
			return (false);
		idx++;
	}
	return (true);
}
