/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 22:23:13 by cberganz          #+#    #+#             */
/*   Updated: 2022/01/20 18:02:19 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_map	*map(void)
{
	static t_map	map;

	return (&map);
}

static uint8_t	is_not_ber(char *path)
{
	int	len;

	len = ft_strlen(path);
	if (ft_strcmp(path + len - 4, ".ber"))
		return (1);
	else
		return (0);
}

static void	get_map_info(char *file_path)
{
	int		fd;
	char	*line;

	map()->height = 0;
	fd = open(file_path, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		if (map()->height == 0)
			map()->width = (int)ft_strlen(line);
		map()->height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

static void	get_map_formated(char *file_path)
{
	char	*line;
	int		fd;
	int		y;

	map()->board = malloc((map()->height + 1) * sizeof(char **));
	if (!map()->board)
		exit_game(EXIT_FAILURE, STDERR_FILENO,
			"Error\nMemory allocation error.\n");
	fd = open(file_path, O_RDONLY);
	y = 0;
	line = get_next_line(fd);
	while (line)
	{
		map()->board[y] = line;
		y++;
		line = get_next_line(fd);
	}
	map()->board[y] = NULL;
	close(fd);
}

void	map_initialize(char *file_path)
{
	if (is_not_ber(file_path))
	{
		write(2, "Error.\nInvalid map format. \".ber\" map required.\n", 48);
		exit(EXIT_SUCCESS);
	}
	get_map_info(file_path);
	get_map_formated(file_path);
	check_map();
}
