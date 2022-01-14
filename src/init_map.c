/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 20:59:30 by cberganz          #+#    #+#             */
/*   Updated: 2022/01/14 05:50:32 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void printmap(char **map)
{
	while (*map)
	{
		printf("%s\n", *map);
		map++;
	}
}

static int8_t	get_map_from_file(t_map *map, int fd)
{
	char	*line;
	int	i;

	i = 0;
	map->map = malloc(map->height * sizeof(char **));
	if (!map->map)
		return (-1);
	while ((line = get_next_line(fd)) != NULL)
	{
		map->map[i] = line;
		i++;
	}
	map->map[i] = NULL;
	return (1);
}

int8_t	init_map(t_map *map, char *fp)
{
	int	fd;

	fd = open(fp, O_RDONLY);
	if (get_map_from_file(map, fd) == -1)
		return (-1);
	printmap(map->map);
	close(fd);
	return (1);
}
