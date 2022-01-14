#include "../includes/so_long.h"

t_map	*map(void)
{
	static t_map	map;

	return (&map);
}

static void	get_map_info(char *file_path)
{
	int	fd;
	char	*line;

	map()->height = 0;
	fd = open(file_path, O_RDONLY);
	while ((line = get_next_line(fd)))
	{
		if (map()->height == 0)
			map()->width = (int)ft_strlen(line);
		map()->height++;
		free(line);
	}
	close(fd);
}

static void	get_map_formated(char *file_path)
{
	char	*line;
	int	fd;
	int	i;

	map()->board = malloc(map()->height * sizeof(char **));
	if (!map()->board)
		exit_game();
	fd = open(file_path, O_RDONLY);
	i = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		map()->board[i] = line;
		i++;
	}
	map()->board[i] = NULL;
	close(fd);
}

void	map_initialize(char *file_path)
{
	get_map_info(file_path);
	get_map_formated(file_path);
	check_map();
}
