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
		free(map()->board);
	}
}

void	exit_game(int EXIT_CODE, int STD, char *message)
{
	clear_map();
	ft_putstr_fd(message, STD);
	exit(EXIT_CODE);
}

