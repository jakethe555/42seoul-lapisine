/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyoule <jaeyoule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:36:24 by jaeyoule          #+#    #+#             */
/*   Updated: 2021/04/08 19:49:46 by jaeyoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		compare(int i, int found, char *str, char *to_find)
{
	int str_l;
	int j;
	int idx;

	idx = 0;
	str_l = 0;
	while (to_find[idx++])
		++str_l;
	j = 0;
	found = 1;
	while (j < str_l)
	{
		if (str[i + j] != to_find[j])
			found = 0;
		++j;
	}
	return (found);
}

char	*ft_strstr(char *str, char *to_find)
{
	int		i;
	int		found;
	char	*ptr;

	found = 0;
	i = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[i] && found == 0)
	{
		if (str[i] == to_find[0])
			found = compare(i, found, str, to_find);
		++i;
	}
	ptr = str + i - 1;
	if (found == 0)
		return (0);
	return (ptr);
}
