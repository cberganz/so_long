/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 22:23:13 by cberganz          #+#    #+#             */
/*   Updated: 2022/01/21 12:36:54 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

t_map	*m(void)
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

	m()->height = 0;
	fd = open(file_path, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		if (m()->height == 0)
			m()->width = (int)ft_strlen(line);
		m()->height++;
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

	m()->map = malloc((m()->height + 1) * sizeof(char **));
	if (!m()->map)
		exit_game(EXIT_FAILURE, STDERR_FILENO, ERR_MEM);
	fd = open(file_path, O_RDONLY);
	y = 0;
	line = get_next_line(fd);
	while (line)
	{
		m()->map[y] = line;
		y++;
		line = get_next_line(fd);
	}
	m()->map[y] = NULL;
	close(fd);
}

void	map_initialize(char *file_path)
{
	if (is_not_ber(file_path))
	{
		ft_putstr_fd(ERR_BER, 2);
		exit(EXIT_SUCCESS);
	}
	get_map_info(file_path);
	get_map_formated(file_path);
	check_map();
}
