#include "./libft/include/libft.h"
#include <fcntl.h>

int	main(void)
{
	int	fd;
	char	*line;

	fd = open("./maps/first_map.ber", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
