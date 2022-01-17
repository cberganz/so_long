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

//static void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
//{
//	char	*dst;
//
//	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
//	*(unsigned int*)dst = color;
//}

static t_display	*display(void)
{
	static t_display	display;

	return (&display);
}

static void	new_image(void)
{
	display()->img = mlx_new_image(display()->mlx, display()->screen_height, display()->screen_width);
	display()->addr = mlx_get_data_addr(display()->img, &display()->bits_per_pixel, &display()->line_length, &display()->endian);
}

static void	display_image(void)
{
//	void	*img;
	
	display()->relative_path = "./test.xpm";
	display()->img = mlx_xpm_file_to_image(display()->mlx, display()->relative_path, &display()->img_width, &display()->img_height);
	mlx_put_image_to_window(display()->mlx, display()->mlx_win, display()->img, 0, 0);
	mlx_put_image_to_window(display()->mlx, display()->mlx_win, display()->img, 0, 451);
}

static void	init_display(void)
{
	display()->screen_height = 1980;
	display()->screen_width = 1080;
	display()->mlx = mlx_init();
	display()->mlx_win = mlx_new_window(display()->mlx, display()->screen_height, display()->screen_width, "Hello world !");
	new_image();
	display_image();
	mlx_loop(display()->mlx);
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
	init_display();
	structure_initialize(argv[1]);
	printmap(map()->board);
	return (0);
}
