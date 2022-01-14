/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 04:50:00 by cberganz          #+#    #+#             */
/*   Updated: 2022/01/14 06:23:47 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	exit_game(void)
{
	printf("game exited\n");
	exit(EXIT_FAILURE);
}

static void	isvalid_wall(t_map *map, int i, int j)
{
	if ((i == 0 || i == map->height - 1 || j == 0 || j == map->width - 1)
		&& map->map[i][j] != '1')
		exit_game();
}

static void	isvalid_char(t_map *map, char c)
{
	if (c == 'P')
		map->count_pos++;
	else if (c == 'E')
		map->count_exit++;
	else if (c == 'C')
		map->count_obj++;
	else if (c == '1' || c == '0')
		return ;
	else
		exit_game();
}

void	check_map(t_map *map)
{
	int	i;
	int	j;

	if (map->height == map->width)
		exit_game();
	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			isvalid_char(map, map->map[i][j]);
			isvalid_wall(map, i, j);
			j++;
		}
		if (j != map->width)
			exit_game();
		i++;
	}
}
