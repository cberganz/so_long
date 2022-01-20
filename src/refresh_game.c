/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:27:19 by cberganz          #+#    #+#             */
/*   Updated: 2022/01/20 18:02:28 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_display	*display(void)
{
	static t_display	display;

	return (&display);
}

static void	display_image(t_tex *t, int i, int j)
{
	mlx_put_image_to_window(display()->mlx, display()->mlx_win, t->img, i * img()->format, j * img()->format);
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
				display_image(&img()->wall, j, i);
			else if (map()->board[i][j] == '0')
				display_image(&img()->ground, j, i);
			else if (map()->board[i][j] == 'E')
				display_image(&img()->exit, j, i);
			else if (map()->board[i][j] == 'C')
				display_image(&img()->collectible, j, i);
			else if (map()->board[i][j] == 'P')
				display_image(&img()->character_current, j, i);
			j++;
		}
		i++;
	}
}

int	key_hook(int keycode, t_display *display)
{
	if (keycode == 100 || keycode == 65363)
		move_right();
	else if (keycode == 97 || keycode == 65361)
		move_left();
	else if (keycode == 119 || keycode == 65362)
		move_top();
	else if (keycode == 115 || keycode == 65364)
		move_bottom();
	else if (keycode == 65307)
		exit_game(EXIT_SUCCESS, STDOUT_FILENO, "Game exited by user.\n");
	display_map();
//	printf("%d\n", keycode);
	(void)display;
	return (0);
}

void	init_display(void)
{
	display()->mlx = mlx_init();
	game_initialize();
	display()->screen_height = map()->height * img()->format;
	display()->screen_width = map()->width * img()->format;
	display()->mlx_win = mlx_new_window(display()->mlx, display()->screen_width, display()->screen_height, "./so_long");
	mlx_hook(display()->mlx_win, 17, 0, exit_button, "Game exited by user\n");
	display_map();
	mlx_key_hook(display()->mlx_win, key_hook, display());
	mlx_loop(display()->mlx);
}
