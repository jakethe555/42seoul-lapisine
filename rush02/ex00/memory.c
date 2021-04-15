/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwon <ekwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 23:25:01 by ekwon             #+#    #+#             */
/*   Updated: 2021/04/11 07:15:27 by jaeyoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int		memory_init(char **array_set, int key_num)
{
	int i;
	int j;

	i = 0;
	if (array_set == 0)
	{
		write(1, "memory allocate failure\n", 24);
		return (0);
	}
	while (i <= key_num)
	{
		j = 0;
		while (j < MAX_LEN)
		{
			array_set[i][j] = 0;
			j++;
		}
		i++;
	}
	return (1);
}

char	**key_memory_allocate(char **out_key_set, int key_num)
{
	int i;

	i = 0;
	out_key_set = (char **)malloc(sizeof(char *) * key_num + 1);
	if (out_key_set == 0)
	{
		write(1, "memory allocate failure\n", 24);
		return (0);
	}
	while (i <= key_num)
	{
		out_key_set[i] = (char*)malloc(sizeof(char) * MAX_LEN);
		if (out_key_set[i] == 0)
		{
			write(1, "memory allocate failure\n", 24);
			return (0);
		}
		i++;
	}
	if (memory_init(out_key_set, key_num) == 0)
	{
		write(1, "memory allocate failure\n", 24);
		return (0);
	}
	return (out_key_set);
}

char	**value_memory_allocate(char **out_value_set, int key_num)
{
	int i;

	i = 0;
	out_value_set = (char **)malloc(sizeof(char *) * key_num + 1);
	if (out_value_set == 0)
	{
		write(1, "memory allocate failure\n", 24);
		return (0);
	}
	while (i <= key_num)
	{
		out_value_set[i] = (char*)malloc(sizeof(char) * MAX_LEN);
		if (out_value_set[i] == 0)
		{
			write(1, "memory allocate failure\n", 24);
			return (0);
		}
		i++;
	}
	if (memory_init(out_value_set, key_num) == 0)
	{
		write(1, "memory allocate failure\n", 24);
		return (0);
	}
	return (out_value_set);
}

void	memory_free(char **key_set, char **value_set)
{
	int i;

	i = -1;
	while (++i <= g_key_num)
	{
		free(key_set[i]);
		free(value_set[i]);
	}
	free(key_set);
	free(value_set);
}

void	reset(char *array, int max)
{
	int i;

	i = 0;
	while (i < max)
	{
		array[i] = 0;
		++i;
	}
}
