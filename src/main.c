/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 20:59:20 by cberganz          #+#    #+#             */
/*   Updated: 2022/01/16 01:45:09 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	get_image(void)
{
	void	*mlx;
	void	*img;
	char	*relative_path = "./test.xpm";
	int		img_width;
	int		img_height;

	mlx = mlx_init();
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
}

//void	mlx_test(void)
//{
//	void	*mlx;
//	void	*mlx_win;
//	t_data	img;
//
//	mlx = mlx_init();
//	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
//	img.img = mlx_new_image(mlx, 1920, 1080);
//	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
//								&img.endian);
//	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
//	my_mlx_pixel_put(&img, 10, 10, 0x00FF0000);
//	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
//	mlx_loop(mlx);
//}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	get_image();
	structure_initialize(argv[1]);
	printmap(map()->board);
	return (0);
}
