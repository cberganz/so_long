/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_map_checker.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 04:50:00 by cberganz          #+#    #+#             */
/*   Updated: 2022/01/18 11:51:09 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	isvalid_border(int y, int x)
{
	if ((y == 0 || y == map()->height - 1 || x == 0 || x == map()->width - 1)
		&& map()->board[y][x] != '1')
		exit_game(EXIT_SUCCESS, STDERR_FILENO, "Error\nMap borders are not clear.\n");
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
		exit_game(EXIT_SUCCESS, STDERR_FILENO, "Error\nInvalid character in map.\n");
}

void	check_map(void)
{
	int	x;
	int	y;

	if (map()->height == map()->width)
		exit_game(EXIT_SUCCESS, STDERR_FILENO, "Error\nMap is a square.\n");
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
			exit_game(EXIT_SUCCESS, STDERR_FILENO,"Error\nMap rows must have the same width.\n");
		y++;
	}
	if (map()->count_pos > 1 || map()->count_pos < 0)
		exit_game(EXIT_SUCCESS, STDERR_FILENO, "Error\nInvalid number of start positions in map.\n");
	if (map()->count_exit > 1 || map()->count_exit < 1)
		exit_game(EXIT_SUCCESS, STDERR_FILENO, "Error\nInvalid number of exits in map.\n");
	if (map()->count_obj < 1)
		exit_game(EXIT_SUCCESS, STDERR_FILENO, "Error\nNo collectibles in map.\n");
}
