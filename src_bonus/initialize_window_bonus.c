/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_window_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 11:52:24 by cberganz          #+#    #+#             */
/*   Updated: 2022/01/24 11:07:36 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

t_display	*w(void)
{
	static t_display	display;

	return (&display);
}

void	window_initialize(t_display *w)
{
	w->screen_height = m()->height * img()->format;
	w->screen_width = m()->width * img()->format;
	w->mlx_win = mlx_new_window(w->mlx, w->screen_width, w->screen_height,
			"./so_long");
	mlx_hook(w->mlx_win, 17, 0, exit_button, "Game exited by user\n");
}
