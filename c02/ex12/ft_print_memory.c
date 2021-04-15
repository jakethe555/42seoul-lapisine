/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyoule <jaeyoule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 20:09:13 by jaeyoule          #+#    #+#             */
/*   Updated: 2021/04/06 22:37:30 by jaeyoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	hex_conversion(int num, char *hex_num, int i)
{
	if (i == -1)
		return ;
	hex_num[i] = "0123456789abcdef"[num % 16];
	hex_conversion(num / 16, hex_num, --i);
}

void	char_to_hex(char *str, unsigned int last)
{
	char				hex_code[2];
	unsigned int		i;

	i = 0;
	while (i != last)
	{
		hex_code[0] = "0123456789abcdef"[str[i] / 16];
		hex_code[1] = "0123456789abcdef"[str[i] % 16];
		write(1, &hex_code, 2);
		if (i % 2 == 1)
			write(1, " ", 1);
		i++;
	}
	if (i != 16)
	{
		while (i != 16)
		{
			write(1, "  ", 2);
			if (i % 2 == 1)
				write(1, " ", 1);
			i++;
		}
	}
}

void	print_str(char *str, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < size)
	{
		if (str[i] < 32 || str[i] == 127)
			write(1, ".", 1);
		else
			write(1, &str[i], 1);
		i++;
	}
}

void	ft_print_memory_one(void *addr, unsigned int size)
{
	unsigned int	num;
	char			hex_num[16];
	char			*str;
	int				i;

	i = -1;
	str = (char *)addr;
	while (++i < 16)
		hex_num[i] = '0';
	num = (unsigned int)addr;
	hex_conversion(num, &hex_num[0], 15);
	write(1, &hex_num[0], 16);
	write(1, ": ", 2);
	char_to_hex(str, size);
	print_str(str, size);
	write(1, "\n", 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	int				print;

	i = 0;
	print = 0;
	while (i < size)
	{
		if (i % 16 == 0)
		{
			if (print == size / 16)
				ft_print_memory_one(&addr[i], size % 16);
			else
				ft_print_memory_one(&addr[i], 16);
			print++;
		}
		i++;
	}
	return (addr);
}
