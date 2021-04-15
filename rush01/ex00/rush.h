/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhong <mhong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 22:29:30 by mhong             #+#    #+#             */
/*   Updated: 2021/04/04 23:12:47 by mhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_H
# define RUSH_H

# include <unistd.h>
# include <stdbool.h>

typedef struct	s_pair
{
	int		val;
	bool	is_fixed;
}				t_pair;

int				g_fixed_cnt;
int				g_condition_input[16];
int				g_col_condition[2][4];
int				g_row_condition[2][4];
t_pair			g_board[4][4];

void			print_board();
void			val_check(bool *used_val_check, int col_num, int row_num);
bool			is_valid_col(int col_num, bool is_top);
bool			is_valid_row(int row_num, bool is_left);
bool			check_top_bottom_valid(void);
bool			check_condition(void);
bool			recursive_func(int in_num, int unfix_num, int c_num, int r_num);
bool			call_recur(int in_num, int unfix_num, int c_num, int r_num);
int				fix_board_col(void);
int				fix_board_row(void);
bool			do_recursive(int row_idx, int col_idx);
int				is_space(char c);
int				argv_check(char *av, int i, int count);
void			condition(int *condition);
void			init_board(void);
int				check_fill(int i, int j, int value);
void			check_fill_4(int i, int j, int is_row);
#endif
