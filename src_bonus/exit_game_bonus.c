/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 22:23:51 by cberganz          #+#    #+#             */
/*   Updated: 2022/01/25 13:41:55 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	exit_button(char *msg)
{
	exit_game(EXIT_SUCCESS, STDOUT_FILENO, msg, 0);
	return (0);
}

void	clear_map(void)
{
	int	i;

	i = 0;
	if (m())
	{
		while (m()->map[i])
		{
			free(m()->map[i]);
			i++;
		}
		free(m()->map);
	}
}

void	clear_img(void)
{
	if (img()->ground.img)
		mlx_destroy_image(w()->mlx, img()->ground.img);
	if (img()->wall.img)
		mlx_destroy_image(w()->mlx, img()->wall.img);
	if (img()->collectible.img)
		mlx_destroy_image(w()->mlx, img()->collectible.img);
	if (img()->exit.img)
		mlx_destroy_image(w()->mlx, img()->exit.img);
	if (img()->character_front.img)
		mlx_destroy_image(w()->mlx, img()->character_front.img);
	if (img()->character_back.img)
		mlx_destroy_image(w()->mlx, img()->character_back.img);
	if (img()->character_right.img)
		mlx_destroy_image(w()->mlx, img()->character_right.img);
	if (img()->character_left.img)
		mlx_destroy_image(w()->mlx, img()->character_left.img);
	if (img()->character_left.img)
		mlx_destroy_image(w()->mlx, img()->character_die.img);
}

void	clear_enemy(void)
{
	if (enmy()->frame1.img)
		mlx_destroy_image(w()->mlx, enmy()->frame1.img);
	if (enmy()->frame2.img)
		mlx_destroy_image(w()->mlx, enmy()->frame2.img);
	if (enmy()->frame3.img)
		mlx_destroy_image(w()->mlx, enmy()->frame3.img);
	if (enmy()->frame4.img)
		mlx_destroy_image(w()->mlx, enmy()->frame4.img);
	if (enmy()->frame5.img)
		mlx_destroy_image(w()->mlx, enmy()->frame5.img);
	if (enmy()->frame6.img)
		mlx_destroy_image(w()->mlx, enmy()->frame6.img);
	if (enmy()->frame7.img)
		mlx_destroy_image(w()->mlx, enmy()->frame7.img);
	if (enmy()->frame8.img)
		mlx_destroy_image(w()->mlx, enmy()->frame8.img);
}

int	exit_game(int EXIT_CODE, int STD, char *message, int delay)
{
	if (delay != 1)
	{
		mlx_loop_end(w()->mlx);
		display_refresh();
	}
	clear_map();
	if (STD != STDERR_FILENO)
	{
		clear_img();
		clear_enemy();
		mlx_destroy_window(w()->mlx, w()->mlx_win);
		ft_delay(delay);
		mlx_destroy_display(w()->mlx);
		free(w()->mlx);
	}
	ft_putstr_fd(message, STD);
	exit(EXIT_CODE);
	return (0);
}
