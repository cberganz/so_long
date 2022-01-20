/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_map_checker.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 04:50:00 by cberganz          #+#    #+#             */
/*   Updated: 2022/01/20 18:02:22 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	isvalid_border(int y, int x)
{
	if ((y == 0 || y == map()->height - 1 || x == 0 || x == map()->width - 1)
		&& map()->board[y][x] != '1')
		exit_game(EXIT_SUCCESS, STDERR_FILENO, ERR_BORDERS);
}

static void	isvalid_char(char c, int y, int x)
{
	if (c == 'P')
	{
		map()->count_pos++;
		game()->p_pos_x = x;
		game()->p_pos_y = y;
	}
	else if (c == 'E')
		map()->count_exit++;
	else if (c == 'C')
		map()->count_obj++;
	else if (c == '1' || c == '0')
		return ;
	else
		exit_game(EXIT_SUCCESS, STDERR_FILENO, ERR_INVALIDCHAR);
}

void	check_map(void)
{
	int	x;
	int	y;

	y = 0;
	while (map()->board[y])
	{
		x = 0;
		while (map()->board[y][x])
		{
			isvalid_char(map()->board[y][x], y, x);
			isvalid_border(y, x);
			x++;
		}
		if (x != map()->width)
			exit_game(EXIT_SUCCESS, STDERR_FILENO, ERR_WIDTH);
		y++;
	}
	if (map()->count_pos > 1 || map()->count_pos < 0)
		exit_game(EXIT_SUCCESS, STDERR_FILENO, ERR_STARTP);
	if (map()->count_exit > 1 || map()->count_exit < 1)
		exit_game(EXIT_SUCCESS, STDERR_FILENO, ERR_EXIT);
	if (map()->count_obj < 1)
		exit_game(EXIT_SUCCESS, STDERR_FILENO, ERR_NOCOLL);
}
