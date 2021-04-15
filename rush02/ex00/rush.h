/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwon <ekwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 05:17:08 by ekwon             #+#    #+#             */
/*   Updated: 2021/04/11 17:16:05 by jaeyoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_H
# define RUSH_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define BUFF_SIZE 10000
# define MAX_LEN 1000

int		g_error;
char	g_print[1000];
int		g_key_num;
int		g_max_digit;

void	ft_putstr(char *str);
void	get_result(char *str, char *fstr, char **key_set, char **value_set);
int		find_match(char **key_set, char *target);
int		null_return(char *target);
void	call_dict(char **key_set, char **value_set, char *target);
int		digit_return(char *str);
void	zero_call(char **key_set, char **value_set, char *num, int i);
void	one_digit_call(char **key_set, char **value_set, char *num, int i);
void	two_digit_call(char **key_set, char **value_set, char *num, int i);
void	three_digit_call(char **key_set, char **value_set, char *num, int i);
void	four_digit_call(char **key_set, char **value_set, char *num, int i);
void	parsing(char **key_set, char **value_set, char *num, int i);
int		find_key_num(char *fstr);
void	create_target(char *argv, char *target);
int		memory_init(char **array_set, int key_num);
char	**key_memory_allocate(char **out_key_set, int key_num);
char	**value_memory_allocate(char **out_value_set, int key_num);
void	memory_free(char **key_set, char **value_set);
void	set_array(char **key_set, char **value_set, char *fstr, int idx);
int		open_file(char *fstr, char *path);
int		is_valid_file(char *fstr, char **argv, int argc);
void	show_errors(char **argv, int argc);
void	show_errors_two(char **argv, int argc);
void	reset(char *array, int max);
void	fstr_check_front(char *fstr, int *idx, int *k);
void	fstr_check_middle(char *fstr, int *idx);
void	fstr_check_back(char *fstr, int *idx);
void	delete_space_b(char **value_set, int i);

#endif
