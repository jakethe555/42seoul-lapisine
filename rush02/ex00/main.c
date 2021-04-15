/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwon <ekwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 23:25:01 by ekwon             #+#    #+#             */
/*   Updated: 2021/04/11 16:40:46 by jaeyoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int		find_key_num(char *fstr)
{
	int i;
	int key_num;

	i = 0;
	key_num = 1;
	while (fstr[i])
	{
		if (fstr[i] == '\n')
			++key_num;
		++i;
	}
	return (key_num);
}

int		open_file(char *fstr, char *path)
{
	int fd;
	int key_num;
	int fstr_num;

	if (0 < (fd = open(path, O_RDONLY)))
	{
		fstr_num = read(fd, fstr, BUFF_SIZE);
		fstr[fstr_num + 1] = '\0';
		key_num = find_key_num(&fstr[0]);
		close(fd);
		return (key_num);
	}
	else
	{
		g_error = 0;
		return (g_error);
	}
}

void	show_errors_two(char **argv, int argc)
{
	int i;
	int j;

	i = (argc == 2) ? 1 : 2;
	j = 0;
	if ((argc == 2 || argc == 3))
	{
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
			{
				write(1, "Error\n", 6);
				g_error = 0;
				break ;
			}
			j++;
		}
	}
}

void	show_errors(char **argv, int argc)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (g_key_num == 0)
	{
		write(1, "Dict Error\n", 11);
		g_error = 0;
	}
	else if (g_key_num == -1)
	{
		write(1, "Error\n", 6);
		g_error = 0;
	}
}

int		main(int argc, char **argv)
{
	char	fstr[BUFF_SIZE];
	char	**key_set;
	char	**value_set;
	char	target[MAX_LEN];

	g_error = 1;
	g_max_digit = 0;
	reset(&target[0], MAX_LEN);
	reset(&fstr[0], BUFF_SIZE);
	show_errors_two(argv, argc);
	if (g_error == 1)
	{
		g_key_num = is_valid_file(fstr, argv, argc);
		show_errors(argv, argc);
	}
	if (g_error == 1)
	{
		key_set = NULL;
		key_set = key_memory_allocate(key_set, g_key_num);
		value_set = NULL;
		value_set = value_memory_allocate(value_set, g_key_num);
		create_target(argc == 2 ? argv[1] : argv[2], &target[0]);
		get_result(&target[0], fstr, key_set, value_set);
		memory_free(key_set, value_set);
	}
}
