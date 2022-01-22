/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:14:51 by cberganz          #+#    #+#             */
/*   Updated: 2022/01/22 15:44:37 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	init_arr(t_tex *arr)
{
	arr[0] = enmy()->frame1;
	arr[1] = enmy()->frame2;
	arr[2] = enmy()->frame3;
	arr[3] = enmy()->frame4;
	arr[4] = enmy()->frame5;
	arr[5] = enmy()->frame6;
	arr[6] = enmy()->frame7;
	arr[7] = enmy()->frame8;
}

int	enemy_sprite(int param)
{
	static int	i;
	t_tex		arr[8];

	init_arr(arr);
	if (i == 8)
		i = 0;
	enmy()->current = arr[i];
	display_refresh();
	ft_delay(0.1);
	i++;
	(void)param;
	return (0);
}

static int	you_die(int x, int y)
{
	if (m()->map[y + 1][x] == 'P' || m()->map[y + 1][x + 1] == 'P'
		|| m()->map[y][x + 1] == 'P' || m()->map[y - 1][x + 1] == 'P'
		|| m()->map[y - 1][x] == 'P' || m()->map[y - 1][x - 1] == 'P'
		|| m()->map[y][x - 1] == 'P' || m()->map[y + 1][x - 1] == 'P'
		|| m()->map[y][x] == 'P')
	{
		img()->character_current = img()->character_die;
		display_refresh();
		return (1);
	}
	return (0);
}

uint8_t	die_zone(void)
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
				break ;
			x++;
		}
		if (m()->map[y][x] == 'e')
			break ;
		y++;
	}
	if (!m()->map[y])
		return (0);
	if (you_die(x, y))
		return (1);
	return (0);
}
