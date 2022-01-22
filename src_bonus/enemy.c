#include "../includes/so_long_bonus.h"

t_enemy	*enmy(void)
{
	static t_enemy	enmy;

	return (&enmy);
}

static void	del_enemy(void)
{
	int	x;
	int	y;

	y = 0;
	while (m()->map[y])
	{
		x = 0;
		while (m()->map[y][x])
		{
			if (m()->map[y][x] == 'e')
				m()->map[y][x] = '0';
			x++;
		}
		y++;
	}
}

static void	place_enemy(void)
{
	int	x;
	int	y;
	int random;

	y = 0;
	srand(time(NULL));
	while (m()->map[y])
	{
		x = 0;
		while (m()->map[y][x])
		{
			if (m()->map[y][x] == '0')
			{
				random = rand() % 101;
				if (random <= 5)
				{
					m()->map[y][x] = 'e';
					break ;
				}
			}
			x++;
		}
		if (m()->map[y][x] == 'e')
			break ;
		y++;
	}
}

void	load_enemy(void)
{
	load_texture(&enmy()->frame1, "./Ressources/enemy1.xpm");
	load_texture(&enmy()->frame2, "./Ressources/enemy2.xpm");
	load_texture(&enmy()->frame3, "./Ressources/enemy3.xpm");
	load_texture(&enmy()->frame4, "./Ressources/enemy4.xpm");
	load_texture(&enmy()->frame5, "./Ressources/enemy5.xpm");
	load_texture(&enmy()->frame6, "./Ressources/enemy6.xpm");
	load_texture(&enmy()->frame7, "./Ressources/enemy7.xpm");
	load_texture(&enmy()->frame8, "./Ressources/enemy8.xpm");
	enmy()->current = enmy()->frame1;
}

int	enemy_sprite(int param)
{
	static int	i;
	t_tex	arr[8] = { enmy()->frame1, enmy()->frame2, enmy()->frame3, enmy()->frame4, enmy()->frame5, enmy()->frame6, enmy()->frame7, enmy()->frame8 };

	if (i == 8)
		i = 0;
	enmy()->current = arr[i];
	display_refresh();
	ft_delay(0.1);
	i++;
	(void)param;
	return (0);
}

uint8_t	die_zone(void)
{
	int	x;
	int	y;

	y = 0;
	while (m()->map[y])
	{
		x =0;
		while (m()->map[y][x])
		{
			if (m()->map[y][x] == 'e')
				break ;
			x++;
		}
		if (m()->map[y][x] == 'e')
			break ;
		y++;
	}
	if (!m()->map[y])
		return (0);
	if (m()->map[y + 1][x] == 'P' || m()->map[y + 1][x + 1] == 'P'
		|| m()->map[y][x + 1] == 'P' || m()->map[y - 1][x + 1] == 'P'
		|| m()->map[y - 1][x] == 'P' || m()->map[y - 1][x - 1] == 'P'
		|| m()->map[y][x - 1] == 'P' || m()->map[y + 1][x - 1] == 'P'
		|| m()->map[y][x] == 'P')
	{
		display_image(&img()->character_die, y, x);
		return (1);
	}
	return (0);
}

void	enemy_patrol(void)
{
	srand(time(NULL));
	if ((rand() % 101) <= 25)
	{
		del_enemy();
		place_enemy();
	}
	if (die_zone())
	{
		ft_delay(5);
		exit_game(EXIT_SUCCESS, STDOUT_FILENO, "GAME OVER!\n");
	}
//	load_enemy();
//	enemy_loop();
}
