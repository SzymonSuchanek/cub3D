/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ja <ja@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:44:12 by ssuchane          #+#    #+#             */
/*   Updated: 2024/11/16 17:29:43 by ja               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../lib/lib_ft/libft.h"
# include "error_message.h"
# include "structs.h"
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

// libmlx
# include "../lib/minilibx/mlx.h"
# include "color.h"
# include "key_linux.h"
# include "xfdf.h"

// Math
// # define M_PI 3.142

# define MINIMAP_SCALE 10
# define MINIMAP_PADDING 10
# define PLAYER_COLOR 0xFF0000
# define WALL_COLOR 0x808080
# define FLOOR_COLOR 0x000000
# define MAP_OPACITY 0.5
# define MINIMAP_VIEWPORT_WIDTH 11
# define MINIMAP_VIEWPORT_HEIGHT 11

// Constants
# define SCREEN_WIDTH 1400
# define SCREEN_HEIGHT 600
# define WALL_FACTOR 2
# define FOV 66.0 // Field of view in degrees
# define TILE_SIZE 64
# define MOVE_SPEED 0.05
# define ROT_SPEED 0.05
# define WIDTH 1920
# define MENU_WIDTH 200

# ifndef DEBUG
#  define DEBUG 0
# endif

// Error codes
# define ERR_MAP_LOAD -1
# define ERR_TEXTURE_LOAD -2
# define ERR_MEMORY -3

// check_map
//	// check_borders.c
int		check_borders(char **map);
//	// check_map.c
void	check_map(char **map);

//	// check_player.c
int		check_player(char **map);

//	// map_utils.c
void	get_player_position(char **map, t_vector *p_pos);
int		get_maps_row_width(const char *row);
int		get_maps_max_row_width(char **map);
int		get_map_height(char **map);
void	free_map(char **map);

// handle_input.c
int		handle_input(char **av, t_game *data);

// utils.c
int		ft_error(int error_code, char *message);
void	print_map(char **map); // temporary
void	print_map_nl(char **map); // temporary

void	select_map(t_game *data);
void	get_player_position(char **map, t_vector *p_pos);
void	init_display(t_game *data);
int		mouse_press(int button, int x, int y, void *param);
int		mouse_release(int button, int x, int y, void *param);
int		mouse_move(int x, int y, void *param);
void	setup_controls(t_display *data);


// colors.c
int		scale_color(int color, float factor);
int		get_color(t_vector current, t_vector start, t_vector end,
			t_vector delta);
// draw.c --
// void	draw_line(t_vector f, t_vector s, t_display *data);
void	draw_line(t_line *line, t_display *data);
void	print_walls(t_game *data);
float		get_distance(t_game *data, float degree);
// math_utils.c
int		ft_min_int(int a, int b);
float	ft_min_float(float a, float b);
int		ft_max(int a, int b);
int		ft_abs(int x);
void	draw(t_game *game);

// minimap.c
void	draw_minimap(t_game *game);

#endif
