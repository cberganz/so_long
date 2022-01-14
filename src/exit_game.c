#include "../includes/so_long.h"

void	clear_map(void)
{
	int	i;

	i = 0;
	if (map())
	{
		while (map()->board[i])
		{
			free(map()->board[i]);
			i++;
		}
	}
	free(map()->board);
}

void	exit_game(void)
{
	printf("game exited\n");
	clear_map();
	exit(EXIT_SUCCESS);
}

