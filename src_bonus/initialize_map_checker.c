/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_map_checker.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 04:50:00 by cberganz          #+#    #+#             */
/*   Updated: 2022/01/21 12:40:33 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	isvalid_border(int y, int x)
{
	if ((y == 0 || y == m()->height - 1 || x == 0 || x == m()->width - 1)
		&& m()->map[y][x] != '1')
		exit_game(EXIT_SUCCESS, STDERR_FILENO, ERR_BORDERS);
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
	if (!m()->map[0])
		exit_game(EXIT_SUCCESS, STDERR_FILENO, ERR_NOMAP);
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
			exit_game(EXIT_SUCCESS, STDERR_FILENO, ERR_WIDTH);
		y++;
	}
	if (m()->count_pos > 1 || m()->count_pos < 1)
		exit_game(EXIT_SUCCESS, STDERR_FILENO, ERR_STARTP);
	if (m()->count_exit > 1 || m()->count_exit < 1)
		exit_game(EXIT_SUCCESS, STDERR_FILENO, ERR_EXIT);
	if (m()->count_obj < 1)
		exit_game(EXIT_SUCCESS, STDERR_FILENO, ERR_NOCOLL);
}
