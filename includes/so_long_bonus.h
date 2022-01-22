/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 21:06:10 by cberganz          #+#    #+#             */
/*   Updated: 2022/01/21 16:07:24 by cberganz         ###   ########.fr       */
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
# include <time.h>
# include <stdio.h> // to remove

/*
** Erro Messages
*/

# define ERR_ARGS "Error.\nInvalid number of arguments.\n"
# define ERR_NOMAP "Error.\nInvalid path for map, or map is empty.\n"
# define ERR_STARTP "Error.\nInvalid number of start positions in map.\n"
# define ERR_WIDTH "Error.\nMap rows must have the same width.\n"
# define ERR_EXIT "Error.\nInvalid number of exits in map.\n"
# define ERR_NOCOLL "Error.\nNo collectibles in map.\n"
# define ERR_STARTP "Error.\nInvalid number of start positions in map.\n"
# define ERR_INVALIDCHAR "Error.\nInvalid character in map.\n"
# define ERR_BORDERS "Error.\nMap borders are not clear.\n"
# define ERR_MEM "Error.\nMemory error while running malloc().\n"
# define ERR_BER "Error.\nInvalid map format. \".ber\" map required.\n"

/*
** Keyboard keys
*/

# define D 100
# define A 97
# define W 119
# define S 115
# define RIGHT 65363
# define LEFT 65361
# define TOP 65362
# define BOTTOM 65364
# define ESC 65307

/*
**	Structures
*/

typedef struct s_map
{
	char	**map;
	int		height;
	int		width;
	int		count_exit;
	int		count_obj;
	int		count_pos;
	int		count_ground;
}	t_map;

typedef struct s_display
{
	void	*mlx;
	void	*mlx_win;
	int		screen_height;
	int		screen_width;
}	t_display;

typedef struct s_game
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

typedef struct s_img
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
	t_tex	character_die;
	int		format;
}	t_img;

typedef struct s_enemy
{
	t_tex	frame1;
	t_tex	frame2;
	t_tex	frame3;
	t_tex	frame4;
	t_tex	frame5;
	t_tex	frame6;
	t_tex	frame7;
	t_tex	frame8;
	t_tex	current;
}	t_enemy;

/*
** Initialise map
*/

void		map_initialize(char *file_path);
void		check_map(void);
t_map		*m(void);

/*
**	Initialize window
*/

void		window_initialize(t_display *w);
t_display	*w(void);

/*
**	Initialize img
*/

void		load_texture(t_tex *t, char *path);
void		img_initialize(void);
t_img		*img(void);

/*
**	Game
*/

t_game		*game(void);
void		game_initialize(void);
void		game_play(void);
void		display_refresh(void);
int			enemy_sprite(int param);
void		display_image(t_tex *t, int i, int j);

/*
**	Enemy
*/

void	load_enemy(void);
void	enemy_patrol(void);
t_enemy	*enmy(void);
uint8_t	die_zone(void);

/*
**	Exit game
*/

void		clear_map(void);
int			exit_game(int exit, int STD, char *message);
int			exit_button(char *msg);

/*
**	Utils
*/

void	display_moves(void);
void	ft_delay(float seconds);

#endif
