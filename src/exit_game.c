/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 22:23:51 by cberganz          #+#    #+#             */
/*   Updated: 2022/01/20 18:02:04 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	exit_button(char *msg)
{
	exit_game(EXIT_SUCCESS, STDOUT_FILENO, msg);
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
	mlx_destroy_image(w()->mlx, img()->ground.img);
	mlx_destroy_image(w()->mlx, img()->wall.img);
	mlx_destroy_image(w()->mlx, img()->collectible.img);
	mlx_destroy_image(w()->mlx, img()->exit.img);
	mlx_destroy_image(w()->mlx, img()->character_front.img);
	mlx_destroy_image(w()->mlx, img()->character_back.img);
	mlx_destroy_image(w()->mlx, img()->character_right.img);
	mlx_destroy_image(w()->mlx, img()->character_left.img);
}

int	exit_game(int EXIT_CODE, int STD, char *message)
{
	clear_img();
	clear_map();
	mlx_destroy_window(w()->mlx, w()->mlx_win);
	mlx_destroy_display(w()->mlx);
	mlx_loop_end(w()->mlx);
	free(w()->mlx);
	ft_putstr_fd(message, STD);
	exit(EXIT_CODE);
	return (0);
}
