/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 12:20:32 by cberganz          #+#    #+#             */
/*   Updated: 2022/01/20 18:02:15 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_right(void)
{	
	if (map()->board[game()->p_pos_y][game()->p_pos_x + 1] == '0'
			|| map()->board[game()->p_pos_y][game()->p_pos_x + 1] == 'C')
	{
		if (map()->board[game()->p_pos_y][game()->p_pos_x + 1] == 'C')
			game()->collected_coll++;
		map()->board[game()->p_pos_y][game()->p_pos_x] = '0';
		map()->board[game()->p_pos_y][game()->p_pos_x + 1] = 'P';
		game()->p_pos_x += 1;
		game()->count_movements++;
		printf("Movement : %d\n", game()->count_movements);
	}
	else if (map()->board[game()->p_pos_y][game()->p_pos_x + 1] == 'E'
			&& game()->count_coll == game()->collected_coll)
		exit_game(EXIT_SUCCESS, STDOUT_FILENO, "GAME SUCCESS!");
	img()->character_current = img()->character_right;
}

void	move_left(void)
{
	if (map()->board[game()->p_pos_y][game()->p_pos_x - 1] == '0'
			|| map()->board[game()->p_pos_y][game()->p_pos_x - 1] == 'C')
	{
		if (map()->board[game()->p_pos_y][game()->p_pos_x - 1] == 'C')
			game()->collected_coll++;
		map()->board[game()->p_pos_y][game()->p_pos_x] = '0';
		map()->board[game()->p_pos_y][game()->p_pos_x - 1] = 'P';
		game()->p_pos_x -= 1;
		game()->count_movements++;
		printf("Movement : %d\n", game()->count_movements);
	}
	else if (map()->board[game()->p_pos_y][game()->p_pos_x - 1] == 'E'
			&& game()->count_coll == game()->collected_coll)
		exit_game(EXIT_SUCCESS, STDOUT_FILENO, "GAME SUCCESS!");
	img()->character_current = img()->character_left;
}

void	move_top(void)
{
	if (map()->board[game()->p_pos_y - 1][game()->p_pos_x] == '0'
			|| map()->board[game()->p_pos_y - 1][game()->p_pos_x] == 'C')
	{
		if (map()->board[game()->p_pos_y - 1][game()->p_pos_x] == 'C')
			game()->collected_coll++;
		map()->board[game()->p_pos_y][game()->p_pos_x] = '0';
		map()->board[game()->p_pos_y - 1][game()->p_pos_x] = 'P';
		game()->p_pos_y -= 1;
		game()->count_movements++;
		printf("Movement : %d\n", game()->count_movements);
	}
	else if (map()->board[game()->p_pos_y - 1][game()->p_pos_x] == 'E'
			&& game()->count_coll == game()->collected_coll)
		exit_game(EXIT_SUCCESS, STDOUT_FILENO, "GAME SUCCESS!");
	img()->character_current = img()->character_back;
}

void	move_bottom(void)
{
	if (map()->board[game()->p_pos_y + 1][game()->p_pos_x] == '0'
			|| map()->board[game()->p_pos_y + 1][game()->p_pos_x] == 'C')
	{
		if (map()->board[game()->p_pos_y + 1][game()->p_pos_x] == 'C')
			game()->collected_coll++;
		map()->board[game()->p_pos_y][game()->p_pos_x] = '0';
		map()->board[game()->p_pos_y + 1][game()->p_pos_x] = 'P';
		game()->count_movements++;
		game()->p_pos_y += 1;
		printf("Movement : %d\n", game()->count_movements);
	}
	else if (map()->board[game()->p_pos_y + 1][game()->p_pos_x] == 'E'
			&& game()->count_coll == game()->collected_coll)
		exit_game(EXIT_SUCCESS, STDOUT_FILENO, "GAME SUCCESS!");
	img()->character_current = img()->character_front;
}
