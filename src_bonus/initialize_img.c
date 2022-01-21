/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_img.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 11:51:14 by cberganz          #+#    #+#             */
/*   Updated: 2022/01/21 12:31:22 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_img	*img(void)
{
	static t_img	img;

	return (&img);
}

static void	load_texture(t_tex *t, char *path)
{
	t->img = mlx_xpm_file_to_image(w()->mlx, path, &t->width, &t->height);
	t->addr = mlx_get_data_addr(t->img, &t->bits_per_pixel,
			&t->line_length, &t->endian);
}

void	img_initialize(void)
{
	img()->format = 64;
	load_texture(&img()->ground, "./Ressources/ground.xpm");
	load_texture(&img()->wall, "./Ressources/wall.xpm");
	load_texture(&img()->collectible, "./Ressources/collectible.xpm");
	load_texture(&img()->exit, "./Ressources/exit.xpm");
	load_texture(&img()->character_front, "./Ressources/Character_front.xpm");
	load_texture(&img()->character_back, "./Ressources/Character_back.xpm");
	load_texture(&img()->character_right, "./Ressources/Character_right.xpm");
	load_texture(&img()->character_left, "./Ressources/Character_left.xpm");
	img()->character_current = img()->character_front;
}
