/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyoule <jaeyoule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 17:24:41 by jaeyoule          #+#    #+#             */
/*   Updated: 2021/04/15 18:22:41 by jaeyoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int					str_len(char *av)
{
	int		i;

	i = 0;
	while (av[i])
		++i;
	return (i);
}

char				*str_copy(char *av)
{
	int		i;
	char	*copy;
	int		length;

	length = str_len(av);
	copy = malloc(sizeof(char) * (length + 1));
	if (copy == 0)
		return (0);
	i = 0;
	while (av[i])
	{
		copy[i] = av[i];
		++i;
	}
	copy[i] = 0;
	return (copy);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*s_str;

	i = 0;
	s_str = malloc(sizeof(t_stock_str) * (ac + 1));
	if (s_str == 0)
		return (0);
	while (av[i])
	{
		s_str[i].size = str_len(av[i]);
		s_str[i].str = av[i];
		s_str[i].copy = str_copy(av[i]);
		++i;
	}
	s_str[i].size = 0;
	s_str[i].str = 0;
	s_str[i].copy = 0;
	return (s_str);
}
