/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:27:19 by cberganz          #+#    #+#             */
/*   Updated: 2022/01/18 15:41:47 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_display	*display(void)
{
	static t_display	display;

	return (&display);
}

static void	new_image(void)
{
	display()->img = mlx_new_image(display()->mlx, display()->screen_height, display()->screen_width);
	display()->addr = mlx_get_data_addr(display()->img, &display()->bits_per_pixel, &display()->line_length, &display()->endian);
}

static void	display_image(char *path, int i, int j)
{
	display()->img = mlx_xpm_file_to_image(display()->mlx, path, &display()->img_width, &display()->img_height);
	mlx_put_image_to_window(display()->mlx, display()->mlx_win, display()->img, i * FORMAT, j * FORMAT);
}

static void	display_map(void)
{
	int	i;
	int	j;

	i = 0;
	while (map()->board[i])
	{
		j = 0;
		while (map()->board[i][j])
		{
			if (map()->board[i][j] == '1')
				display_image(WALL, j, i);
			else if (map()->board[i][j] == '0')
				display_image(GROUND, j, i);
			else if (map()->board[i][j] == 'E')
				display_image(EXIT, j, i);
			else if (map()->board[i][j] == 'C')
				display_image(COLLECTIBLE, j, i);
			else if (map()->board[i][j] == 'P')
				display_image(CHARACTER_FRONT, j, i);
			j++;
		}
		i++;
	}
}

int	key_hook(int keycode, t_display *display)
{
	printf("key:%d\n", keycode);
	(void)display;
	return (0);
}

void	init_display(void)
{
	display()->screen_height = map()->height * FORMAT;
	display()->screen_width = map()->width * FORMAT;
	display()->mlx = mlx_init();
	display()->mlx_win = mlx_new_window(display()->mlx, display()->screen_width, display()->screen_height, "So_Long");
	new_image();
	display_map();
//	game_loop();
	mlx_key_hook(display()->mlx_win, key_hook, display());
	mlx_loop(display()->mlx);
}
