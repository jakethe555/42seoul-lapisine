/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyoule <jaeyoule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:18:58 by jaeyoule          #+#    #+#             */
/*   Updated: 2021/04/08 19:45:35 by jaeyoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	int				find_i;

	i = 0;
	find_i = 0;
	while (dest[find_i])
		++find_i;
	while (src[i] && i < nb)
	{
		dest[find_i] = src[i];
		++i;
		++find_i;
	}
	dest[find_i] = '\0';
	return (dest);
}
