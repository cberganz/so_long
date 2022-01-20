/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 22:23:51 by cberganz          #+#    #+#             */
/*   Updated: 2022/01/18 11:12:20 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	clear_map(void)
{
	int	i;

	i = 0;
	if (map())
	{
		while (map()->board[i])
		{
			free(map()->board[i]);
			i++;
		}
		free(map()->board);
	}
}

void	clear_img(void)
{
	if (img())
	{
		mlx_destroy_image(display()->mlx, img()->ground);
		mlx_destroy_image(display()->mlx, img()->wall);
		mlx_destroy_image(display()->mlx, img()->collectible);
		mlx_destroy_image(display()->mlx, img()->exit);
		mlx_destroy_image(display()->mlx, img()->character_front);
		mlx_destroy_image(display()->mlx, img()->character_left);
		mlx_destroy_image(display()->mlx, img()->character_right);
		mlx_destroy_image(display()->mlx, img()->character_left);
		mlx_destroy_image(display()->mlx, img()->character_current);
	}
}

void	exit_game(int EXIT_CODE, int STD, char *message)
{
	clear_map();
	mlx_destroy_image(display()->mlx, display()->img);
//	clear_img();
	mlx_destroy_window(display()->mlx, display()->mlx_win);
	mlx_destroy_display(display()->mlx);
	ft_putstr_fd(message, STD);
	exit(EXIT_CODE);
}

