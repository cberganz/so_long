/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_map_checker.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 04:50:00 by cberganz          #+#    #+#             */
/*   Updated: 2022/01/14 06:23:47 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	isvalid_border(int i, int j)
{
	if ((i == 0 || i == map()->height - 1 || j == 0 || j == map()->width - 1)
		&& map()->board[i][j] != '1')
		exit_game(EXIT_SUCCESS, STDERR_FILENO, "Error\nMap borders are not clear.\n");
}

static void	isvalid_char(char c)
{
	if (c == 'P')
		map()->count_pos++;
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
	int	i;
	int	j;

	if (map()->height == map()->width)
		exit_game(EXIT_SUCCESS, STDERR_FILENO, "Error\nMap is a square.\n");
	i = 0;
	while (map()->board[i])
	{
		j = 0;
		while (map()->board[i][j])
		{
			isvalid_char(map()->board[i][j]);
			isvalid_border(i, j);
			j++;
		}
		if (j != map()->width)
			exit_game(EXIT_SUCCESS, STDERR_FILENO,"Error\nMap rows must have the same width.\n");
		i++;
	}
	if (map()->count_pos > 1 || map()->count_pos < 0)
		exit_game(EXIT_SUCCESS, STDERR_FILENO, "Error\nInvalid number of start positions in map.\n");
	if (map()->count_exit > 1 || map()->count_exit < 1)
		exit_game(EXIT_SUCCESS, STDERR_FILENO, "Error\nInvalid number of exits in map.\n");
	if (map()->count_obj < 1)
		exit_game(EXIT_SUCCESS, STDERR_FILENO, "Error\nNo collectibles in map.\n");
}
