/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwon <ekwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 23:25:01 by ekwon             #+#    #+#             */
/*   Updated: 2021/04/11 17:14:10 by jaeyoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void	set_array(char **key_set, char **value_set, char *fstr, int idx)
{
	int temp;
	int i;
	int j;
	int k;

	i = 0;
	while (fstr[++idx] != '\0')
	{
		j = 0;
		k = 0;
		fstr_check_front(fstr, &idx, &k);
		temp = idx - 1;
		while (j < k)
			key_set[i][j++] = fstr[temp--];
		fstr_check_middle(fstr, &idx);
		j = 0;
		while (fstr[idx] != '\n')
		{
			fstr_check_back(fstr, &idx);
			if (fstr[idx] != '\n')
				value_set[i][j++] = fstr[idx++];
		}
		delete_space_b(value_set, i);
		i++;
	}
}

int		is_valid_file(char *fstr, char **argv, int argc)
{
	if (argc == 2)
	{
		g_key_num = open_file(fstr, "./numbers.dict");
		if (g_key_num == 0)
			return (0);
		return (g_key_num);
	}
	else if (argc == 3)
	{
		g_key_num = open_file(fstr, argv[1]);
		if (g_key_num == 0)
			return (0);
		return (g_key_num);
	}
	else
		return (-1);
}

void	create_target(char *argv, char *target)
{
	int i;
	int max;

	i = 0;
	max = null_return(argv);
	target[max--] = '\0';
	while (argv[i])
	{
		target[max] = argv[i];
		++i;
		--max;
	}
}

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

void	get_result(char *str, char *fstr, char **key_set, char **value_set)
{
	int		i;

	i = 0;
	set_array(key_set, value_set, fstr, -1);
	i = -1;
	while (++i < 1000)
		g_print[i] = 0;
	parsing(key_set, value_set, str, 0);
	if (g_error == 1)
	{
		g_print[null_return(g_print) - 1] = '\0';
		ft_putstr(g_print);
	}
	else
		ft_putstr("Dict Error");
}
