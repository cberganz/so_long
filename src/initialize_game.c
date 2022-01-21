/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_game.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 14:11:32 by cberganz          #+#    #+#             */
/*   Updated: 2022/01/20 18:02:17 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_game	*game(void)
{
	static t_game	game;

	return (&game);
}

void	game_initialize(void)
{
	game()->count_coll = m()->count_obj;
	game()->count_movements = 0;
	game()->collected_coll = 0;
}
