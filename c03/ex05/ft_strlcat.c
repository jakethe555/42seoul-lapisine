/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyoule <jaeyoule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:18:58 by jaeyoule          #+#    #+#             */
/*   Updated: 2021/04/07 21:42:30 by jaeyoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char			*ft_strncat(char *dest, char *src, unsigned int nb)
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

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int length;
	unsigned int dest_size;
	unsigned int src_size;

	dest_size = 0;
	src_size = 0;
	while (dest[dest_size])
		++dest_size;
	while (src[src_size])
		++src_size;
	if (size > dest_size)
	{
		ft_strncat(dest, src, size - dest_size - 1);
		length = dest_size + src_size;
	}
	else
		length = size + src_size;
	return (length);
}
