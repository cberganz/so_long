/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:11:58 by cberganz          #+#    #+#             */
/*   Updated: 2022/01/24 11:11:30 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

t_enemy	*enmy(void)
{
	static t_enemy	enmy;

	return (&enmy);
}

static void	del_enemy(void)
{
	int	x;
	int	y;

	y = 0;
	while (m()->map[y])
	{
		x = 0;
		while (m()->map[y][x])
		{
			if (m()->map[y][x] == 'e')
				m()->map[y][x] = '0';
			x++;
		}
		y++;
	}
}

static void	place_enemy(void)
{
	int	x;
	int	y;
	int	random;
	int	count;

	y = -1;
	count = 0;
	srand(time(NULL));
	random = rand() % (m()->count_ground + 1);
	while (m()->map[++y])
	{
		x = -1;
		while (m()->map[y][++x])
		{
			if (m()->map[y][x] == '0')
			{
				if (count == random)
					m()->map[y][x] = 'e';
				count++;
			}
		}
	}
}

void	load_enemy(void)
{
	load_texture(&enmy()->frame1, "./Ressources/enemy1.xpm");
	load_texture(&enmy()->frame2, "./Ressources/enemy2.xpm");
	load_texture(&enmy()->frame3, "./Ressources/enemy3.xpm");
	load_texture(&enmy()->frame4, "./Ressources/enemy4.xpm");
	load_texture(&enmy()->frame5, "./Ressources/enemy5.xpm");
	load_texture(&enmy()->frame6, "./Ressources/enemy6.xpm");
	load_texture(&enmy()->frame7, "./Ressources/enemy7.xpm");
	load_texture(&enmy()->frame8, "./Ressources/enemy8.xpm");
	enmy()->current = enmy()->frame1;
}

void	enemy_patrol(void)
{
	srand(time(NULL));
	if ((rand() % 101) < game()->count_movements / 2)
	{
		del_enemy();
		place_enemy();
	}
	if (die_zone())
	{
		exit_game(EXIT_SUCCESS, STDOUT_FILENO, "GAME OVER!\n", 5);
	}
}
