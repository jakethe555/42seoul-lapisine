/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyoule <jaeyoule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 17:16:49 by jaeyoule          #+#    #+#             */
/*   Updated: 2021/04/13 21:44:42 by jaeyoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int			ft_strcmp(char *s1, char *s2)
{
	int i;
	int diff;
	int loop_out;

	i = 0;
	loop_out = 0;
	while (loop_out == 0)
	{
		diff = s1[i] - s2[i];
		if (diff != 0)
			loop_out = 1;
		if (s1[i] == '\0')
		{
			diff = 0 - s2[i];
			loop_out = 1;
		}
		if (s2[i] == '\0')
		{
			diff = s1[i] - 0;
			loop_out = 1;
		}
		++i;
	}
	return (diff);
}

char		**sorting(int ac, char **av)
{
	int		i;
	char	*temp;

	i = 1;
	if (ac == 2)
		return (av);
	while (i < ac - 1)
	{
		if (ft_strcmp(av[i], av[i + 1]) > 0)
		{
			temp = av[i];
			av[i] = av[i + 1];
			av[i + 1] = temp;
		}
		++i;
	}
	av = sorting(--ac, av);
	return (av);
}

int			main(int ac, char **av)
{
	int i;
	int j;

	if (ac == 1)
		return (0);
	av = sorting(ac, av);
	i = 1;
	j = 0;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			write(1, &av[i][j], 1);
			++j;
		}
		write(1, "\n", 1);
		++i;
	}
}
