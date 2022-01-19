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

/*
**	Tiles
*/

# define GROUND "./Ressources/ground.xpm"
# define WALL "./Ressources/wall.xpm"
# define COLLECTIBLE "./Ressources/collectible.xpm"
# define EXIT "./Ressources/exit.xpm"
# define CHARACTER_FRONT "./Ressources/Character_front.xpm"
# define CHARACTER_BACK "./Ressources/Character_back.xpm"
# define CHARACTER_RIGHT "./Ressources/Character_right.xpm"
# define CHARACTER_LEFT "./Ressources/Character_left.xpm"
# define FORMAT 64


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
	char	*relative_path;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		img_height;
	int		img_width;
}	t_display;

//typedef struct	s_game
//{
//
//}	t_game;

/*
** Initialise
*/

void	structure_initialize(char *file_path);
void	map_initialize(char *file_path);
void	check_map(void);
t_map	*map(void);

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

/*
**	Exit game
*/

void	clear_map(void);
void	exit_game(int exit, int STD, char *message);

#endif
