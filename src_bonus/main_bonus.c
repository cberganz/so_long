/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 20:59:20 by cberganz          #+#    #+#             */
/*   Updated: 2022/01/21 12:33:15 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr_fd(ERR_ARGS, 2);
		return (EXIT_SUCCESS);
	}
	map_initialize(argv[1]);
	w()->mlx = mlx_init();
	img_initialize();
	load_enemy();
	window_initialize(w());
	game_initialize();
	game_play();
	mlx_loop(w()->mlx);
	return (EXIT_SUCCESS);
}
