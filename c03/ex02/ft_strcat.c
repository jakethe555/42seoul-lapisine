/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyoule <jaeyoule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:18:58 by jaeyoule          #+#    #+#             */
/*   Updated: 2021/04/08 19:45:14 by jaeyoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int i;
	int find_i;

	i = 0;
	find_i = 0;
	while (dest[find_i])
		++find_i;
	while (src[i])
	{
		dest[find_i] = src[i];
		++i;
		++find_i;
	}
	dest[find_i] = '\0';
	return (dest);
}
