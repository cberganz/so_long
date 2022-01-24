/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_map_checker_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 04:50:00 by cberganz          #+#    #+#             */
/*   Updated: 2022/01/24 11:23:51 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	isvalid_border(int y, int x)
{
	if ((y == 0 || y == m()->height - 1 || x == 0 || x == m()->width - 1)
		&& m()->map[y][x] != '1')
		exit_game(EXIT_SUCCESS, STDERR_FILENO, ERR_BORDERS, 1);
}

static void	isvalid_char(char c, int y, int x)
{
	if (c == 'P')
	{
		m()->count_pos++;
		game()->p_pos_x = x;
		game()->p_pos_y = y;
	}
	else if (c == 'E')
		m()->count_exit++;
	else if (c == 'C')
		m()->count_obj++;
	else if (c == '0')
		m()->count_ground++;
	else if (c == '1')
		return ;
	else
		exit_game(EXIT_SUCCESS, STDERR_FILENO, ERR_INVALIDCHAR, 1);
}

void	check_map(void)
{
	int	x;
	int	y;

	y = 0;
	if (!m()->map[0])
		exit_game(EXIT_SUCCESS, STDERR_FILENO, ERR_NOMAP, 1);
	while (m()->map[y])
	{
		x = 0;
		while (m()->map[y][x])
		{
			isvalid_char(m()->map[y][x], y, x);
			isvalid_border(y, x);
			x++;
		}
		if (x != m()->width)
			exit_game(EXIT_SUCCESS, STDERR_FILENO, ERR_WIDTH, 1);
		y++;
	}
	if (m()->count_pos > 1 || m()->count_pos < 1)
		exit_game(EXIT_SUCCESS, STDERR_FILENO, ERR_STARTP, 1);
	if (m()->count_exit > 1 || m()->count_exit < 1)
		exit_game(EXIT_SUCCESS, STDERR_FILENO, ERR_EXIT, 1);
	if (m()->count_obj < 1)
		exit_game(EXIT_SUCCESS, STDERR_FILENO, ERR_NOCOLL, 1);
}
