/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 21:06:10 by cberganz          #+#    #+#             */
/*   Updated: 2022/01/20 17:51:11 by cberganz         ###   ########.fr       */
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

# define ERR_STARTP "Error\nInvalid number of start positions in map.\n"
# define ERR_WIDTH "Error\nMap rows must have the same width.\n"
# define ERR_EXIT "Error\nInvalid number of exits in map.\n"
# define ERR_NOCOLL "Error\nNo collectibles in map.\n"
# define ERR_STARTP "Error\nInvalid number of start positions in map.\n"
# define ERR_INVALIDCHAR "Error\nInvalid character in map.\n"
# define ERR_BORDERS "Error\nMap borders are not clear.\n"

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
}	t_display;

typedef struct	s_game
{
	int	p_pos_x;
	int	p_pos_y;
	int	count_coll;
	int	collected_coll;
	int	count_movements;
}	t_game;

typedef struct s_tex
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			height;
	int			width;
}	t_tex;

typedef struct	s_img
{
	t_tex	ground;
	t_tex	wall;
	t_tex	collectible;
	t_tex	exit;
	t_tex	character_front;
	t_tex	character_back;
	t_tex	character_right;
	t_tex	character_left;
	t_tex	character_current;
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
int	exit_game(int exit, int STD, char *message);
int	exit_button(char *msg);

#endif
