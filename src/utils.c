#include "../includes/so_long.h"

void	print_moves(void)
{
	ft_putstr_fd("Moves : ", 1);
	ft_putnbr_fd(game()->count_movements, 1);
	ft_putchar_fd('\n', 1);
}
