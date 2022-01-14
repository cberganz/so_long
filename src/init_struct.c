/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 04:19:31 by cberganz          #+#    #+#             */
/*   Updated: 2022/01/14 06:23:45 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	get_map_size(t_map *map, char *file_path)
{
	int	fd;
	char	*line;

	fd = open(file_path, O_RDONLY);
	while ((line = get_next_line(fd)))
	{
		if (map->height == 0)
			map->width = (int)ft_strlen(line);
		free(line);
		map->height++;
	}
	close(fd);
}

t_root	*init_struct(char *file_path)
{
	t_root	*root;
	t_map	*map;

	root = malloc(sizeof(*root));
	if (!root)
		return (NULL);
	map = malloc(sizeof(*map));
	if (!map)
	{
		clear_root(root);
		return (NULL);
	}
	root->map = map;
	map->height = 0;
	get_map_size(map, file_path);
	init_map(root->map, file_path);
	check_map(map);
	return (root);
}
