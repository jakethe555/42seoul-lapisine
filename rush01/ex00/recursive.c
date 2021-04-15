/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhong <mhong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 21:52:53 by mhong             #+#    #+#             */
/*   Updated: 2021/04/04 22:52:44 by mhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

bool	recursive_func(int in_num, int unfix_num, int c_num, int r_num)
{
	int		val_check_idx;
	bool	used_val_check[5];

	if ((in_num == unfix_num) || (r_num == 4 && c_num == 0))
		return (check_top_bottom_valid());
	if (g_board[r_num][c_num].is_fixed)
		return (call_recur(in_num, unfix_num, c_num, r_num));
	else
	{
		val_check(used_val_check, c_num, r_num);
		val_check_idx = 1;
		while (val_check_idx <= 4)
		{
			if (!used_val_check[val_check_idx])
			{
				g_board[r_num][c_num].val = val_check_idx;
				if (call_recur(in_num + 1, unfix_num, c_num, r_num))
					return (true);
				g_board[r_num][c_num].val = 0;
			}
			val_check_idx++;
		}
	}
	return (false);
}

bool	call_recur(int in_num, int unfix_num, int c_num, int r_num)
{
	if (c_num == 3)
		return (recursive_func(in_num, unfix_num, 0, r_num + 1));
	else
		return (recursive_func(in_num, unfix_num, c_num + 1, r_num));
}

int		fix_board_col(void)
{
	int i;
	int j;
	int row_idx;

	i = 0;
	while (i < 2)
	{
		j = 0;
		while (j < 4)
		{
			if (g_col_condition[i][j] == 4)
			{
				check_fill_4(i, j, 1);
			}
			else if (g_col_condition[i][j] == 1)
			{
				row_idx = (i == 0 ? 0 : 3);
				check_fill(row_idx, j, 4);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int		fix_board_row(void)
{
	int i;
	int j;
	int col_idx;

	i = 0;
	while (i < 2)
	{
		j = 0;
		while (j < 4)
		{
			if (g_row_condition[i][j] == 4)
				check_fill_4(i, j, 0);
			else if (g_row_condition[i][j] == 1)
			{
				col_idx = (i == 0 ? 0 : 3);
				check_fill(j, col_idx, 4);
			}
			j++;
		}
		i++;
	}
	return (1);
}

bool	do_recursive(int row_idx, int col_idx)
{
	bool	flag;

	flag = false;
	while (!flag && row_idx < 3)
	{
		col_idx = 0;
		while (!flag && col_idx < 3)
		{
			if (!g_board[row_idx][col_idx].is_fixed)
			{
				flag = true;
				break ;
			}
			col_idx++;
		}
		if (flag)
			break ;
		row_idx++;
	}
	if (!recursive_func(0, g_fixed_cnt, col_idx, row_idx))
	{
		write(1, "Error\n", 6);
		return (false);
	}
	return (true);
}
