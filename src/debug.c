#include "../includes/so_long.h"

void printmap(char **board)
{
	while (*board)
	{
		printf("%s\n", *board);
		board++;
	}
}

