/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyoule <jaeyoule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 23:42:42 by jaeyoule          #+#    #+#             */
/*   Updated: 2021/04/15 19:07:47 by jaeyoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		queen_check(int board[10], int x)
{
	int test_x;
	int test_y;

	test_x = 0;
	test_y = 0;
	while (test_x < x)
	{
		while (test_y < board[x]
		if( board[x] == test_y
		++test_x;
	}
}

void	queen_recursive(int board[10], int *poss, int x)
{
	int i;

	i = 0;
	if (x == 10)
	{
		*poss++;
		print();
	}
	else
		while (i < 9)
			if (check
			queen_recursive(board, poss, x + 1;



	
}

int		ft_ten_queens_puzzle(void)
{
	int poss;
	int board[10];
	i = 0;

	while (i < 10)
	{
		board[i] = -1;
		++i;
	}
	poss = 0;
	queen_recursive(board, &poss, 0);
	return (poss);

}
