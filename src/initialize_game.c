#include "../includes/so_long.h"

t_game	*game(void)
{
	static t_game	game;

	return (&game);
}

t_img	*img(void)
{
	static t_img	img;

	return (&img);
}

static void	img_initialize(void)
{
	img()->format = 64;
	img()->img_height = img()->format;
	img()->img_width = img()->format;
	img()->ground = mlx_xpm_file_to_image(display()->mlx, "./Ressources/ground.xpm", &img()->img_width, &img()->img_height);
	img()->wall = mlx_xpm_file_to_image(display()->mlx, "./Ressources/wall.xpm", &img()->img_width, &img()->img_height);
	img()->collectible = mlx_xpm_file_to_image(display()->mlx, "./Ressources/collectible.xpm", &img()->img_width, &img()->img_height);
	img()->exit = mlx_xpm_file_to_image(display()->mlx, "./Ressources/exit.xpm", &img()->img_width, &img()->img_height);
	img()->character_front = mlx_xpm_file_to_image(display()->mlx, "./Ressources/Character_front.xpm", &img()->img_width, &img()->img_height);
	img()->character_back = mlx_xpm_file_to_image(display()->mlx, "./Ressources/Character_back.xpm", &img()->img_width, &img()->img_height);
	img()->character_right = mlx_xpm_file_to_image(display()->mlx, "./Ressources/Character_right.xpm", &img()->img_width, &img()->img_height);
	img()->character_left = mlx_xpm_file_to_image(display()->mlx, "./Ressources/Character_left.xpm", &img()->img_width, &img()->img_height);
	img()->character_current = img()->character_front;
}

void	game_initialize(void)
{
	game()->count_coll = map()->count_obj;
	game()->count_movements = 0;
	game()->collected_coll = 0;
	img_initialize();
}
