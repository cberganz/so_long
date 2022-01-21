#include "../includes/so_long.h"

t_display	*w(void)
{
	static t_display	display;

	return (&display);
}

void	window_initialize(void)
{
	w()->screen_height = m()->height * img()->format;
	w()->screen_width = m()->width * img()->format;
	w()->mlx_win = mlx_new_window(w()->mlx, w()->screen_width, w()->screen_height, "./so_long");
	mlx_hook(w()->mlx_win, 17, 0, exit_button, "Game exited by user\n");
}
