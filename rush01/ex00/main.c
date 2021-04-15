/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhong <mhong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 22:14:08 by jaeyoule          #+#    #+#             */
/*   Updated: 2021/04/04 23:16:45 by mhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void	print_board(void)
{
	int		row;
	int		col;
	char	c;

	row = 0;
	col = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			c = g_board[row][col].val + '0';
			write(1, &c, 1);
			if (col != 3)
				write(1, " ", 1);
			col++;
		}
		write(1, "\n", 1);
		row++;
	}
}

void	check_fill_4(int i, int j, int is_row)
{
	int row_idx;
	int col_idx;
	int diff;
	int val;

	val = 0;
	diff = (i == 0 ? 1 : -1);
	if (is_row)
	{
		row_idx = (i == 0 ? 0 : 3);
		while (0 <= row_idx && row_idx <= 4)
		{
			check_fill(row_idx, j, ++val);
			row_idx += diff;
		}
	}
	else
	{
		col_idx = (i == 0 ? 0 : 3);
		while (0 <= col_idx && col_idx <= 4)
		{
			check_fill(j, col_idx, ++val);
			col_idx += diff;
		}
	}
}

int		main(int argc, char **argv)
{
	int str_check;

	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	init_board();
	str_check = argv_check(argv[1], 0, 0);
	condition(&g_condition_input[0]);
	if (str_check == 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	fix_board_col();
	fix_board_row();
	if (!check_condition())
	{
		write(1, "Error\n", 6);
		return (0);
	}
	do_recursive(0, 0);
	return (1);
}
