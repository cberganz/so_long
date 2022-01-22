/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:27:19 by cberganz          #+#    #+#             */
/*   Updated: 2022/01/22 15:51:29 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	display_image(t_tex *t, int i, int j)
{
	mlx_put_image_to_window(w()->mlx, w()->mlx_win, t->img,
		i * img()->format, j * img()->format);
}

void	display_refresh(void)
{
	int	i;
	int	j;

	i = -1;
	while (m()->map[++i])
	{
		j = -1;
		while (m()->map[i][++j])
		{
			if (m()->map[i][j] == '1')
				display_image(&img()->wall, j, i);
			else if (m()->map[i][j] == '0')
				display_image(&img()->ground, j, i);
			else if (m()->map[i][j] == 'E')
				display_image(&img()->exit, j, i);
			else if (m()->map[i][j] == 'C')
				display_image(&img()->collectible, j, i);
			else if (m()->map[i][j] == 'P')
				display_image(&img()->character_current, j, i);
			else if (m()->map[i][j] == 'e')
				display_image(&enmy()->current, j, i);
		}
		display_moves();
	}
}

static void	move(int y_mod, int x_mod, t_tex c)
{
	img()->character_current = c;
	if (m()->map[game()->p_pos_y + y_mod][game()->p_pos_x + x_mod] == '0' ||
			m()->map[game()->p_pos_y + y_mod][game()->p_pos_x + x_mod] == 'C')
	{
		if (m()->map[game()->p_pos_y + y_mod][game()->p_pos_x + x_mod] == 'C')
			game()->collected_coll++;
		m()->map[game()->p_pos_y][game()->p_pos_x] = '0';
		m()->map[game()->p_pos_y + y_mod][game()->p_pos_x + x_mod] = 'P';
		game()->p_pos_x += x_mod;
		game()->p_pos_y += y_mod;
		game()->count_movements++;
	}
	else if (m()->map[game()->p_pos_y][game()->p_pos_x + x_mod] == 'E'
			&& game()->count_coll == game()->collected_coll)
		exit_game(EXIT_SUCCESS, STDOUT_FILENO, "GAME SUCCESS!");
}

int	key_hook(int key, t_display *display)
{
	if (key == D || key == RIGHT)
		move(0, 1, img()->character_right);
	else if (key == A || key == LEFT)
		move(0, -1, img()->character_left);
	else if (key == W || key == TOP)
		move(-1, 0, img()->character_back);
	else if (key == S || key == BOTTOM)
		move(1, 0, img()->character_front);
	else if (key == ESC)
		exit_game(EXIT_SUCCESS, STDOUT_FILENO, "Game exited by user.\n");
	enemy_patrol();
	display_refresh();
	(void)display;
	return (0);
}

void	game_play(void)
{
	display_refresh();
	mlx_key_hook(w()->mlx_win, key_hook, w());
	mlx_loop_hook(w()->mlx, enemy_sprite, 0);
}
