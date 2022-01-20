/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 21:06:10 by cberganz          #+#    #+#             */
/*   Updated: 2022/01/18 15:28:49 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/include/libft.h"
# include "../mlx-linux/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdint.h>
# include <limits.h>
# include <stdio.h> // to remove

# define RIGHT 1
# define LEFT 2
# define TOP 3
# define BOTTOM 4

typedef struct	s_map
{
	char	**board;
	int	height;  //hauteur
	int	width;  //largeur
	int	count_exit;
	int	count_obj;
	int	count_pos;
}	t_map;

typedef struct	s_display {
	void	*mlx;
	void	*mlx_win;
	int		screen_height;
	int		screen_width;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		img_height;
	int		img_width;
}	t_display;

typedef struct	s_game
{
	int	p_pos_x;
	int	p_pos_y;
	int	count_coll;
	int	collected_coll;
	int	count_movements;
}	t_game;

typedef struct	s_img
{
	void	*ground;
	void	*wall;
	void	*collectible;
	void	*exit;
	void	*character_front;
	void	*character_back;
	void	*character_right;
	void	*character_left;
	void	*character_current;
	int		img_height;
	int		img_width;
	int		format;
}	t_img;

/*
** Initialise
*/

void	structure_initialize(char *file_path);
void	map_initialize(char *file_path);
void	check_map(void);
t_map	*map(void);
t_game	*game(void);
void	game_initialize(void);

/*
**	Display
*/

void	printmap(char **board);
void	init_display(void);
t_display	*display(void);

/*
**	Game loop
*/

void	game_loop(void);
void	move_right(void);
void	move_left(void);
void	move_top(void);
void	move_bottom(void);
t_img	*img(void);

/*
**	Exit game
*/

void	clear_map(void);
void	exit_game(int exit, int STD, char *message);

#endif
