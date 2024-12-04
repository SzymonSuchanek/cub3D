/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuchane <ssuchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:10:52 by ssuchane          #+#    #+#             */
/*   Updated: 2024/12/04 19:30:22 by ssuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	put_pixel2(t_image *img, int y, int x, int color)
{
	int	i;
	int	*image;

	image = (int *)(img->pixel_data);
	image[y * SCREEN_WIDTH + x] = color;
}

void	draw_square(t_image *image, int y, int x, unsigned int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < MINIMAP_SCALE)
	{
		j = 0;
		while (j < MINIMAP_SCALE)
		{
			put_pixel2(image, y + i, x + j, color);
			j++;
		}
		i++;
	}
}

void	draw_player(t_image *image, int y, int x)
{
	draw_square(image, y, x, PLAYER_COLOR);
}

void	draw_wall(t_image *image, int y, int x)
{
	draw_square(image, y, x, WALL_COLOR);
}

void	draw_floor(t_image *image, int y, int x)
{
	draw_square(image, y, x, FLOOR_COLOR);
}

void	draw_minimap_background(t_image *image, int y, int x,
		unsigned int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < (2 * PLAYER_RADIUS) + 1)
	{
		j = 0;
		while (j < (2 * PLAYER_RADIUS) + 1)
		{
			draw_square(image, i * MINIMAP_SCALE + y, j * MINIMAP_SCALE + x,
				color);
			j++;
		}
		i++;
	}
}

void	draw_minimap(t_game *game)
{
	t_vector	p_pos;
	t_vector	render_pos;
	t_vector	map_pos;
	t_vector	off;

	p_pos.x = (int)game->player.pos.x;
	p_pos.y = (int)game->player.pos.y;
	render_pos.y = 0;
	if (p_pos.y <= PLAYER_RADIUS)
		map_pos.y = 0;
	else
		map_pos.y = p_pos.y - PLAYER_RADIUS;
	map_pos.x = p_pos.x - PLAYER_RADIUS;
	off.y = map_pos.y + (2 * PLAYER_RADIUS);
	if (map_pos.y + ((2 * PLAYER_RADIUS) + 1) >= game->map.height)
		map_pos.y = game->map.height - ((2 * PLAYER_RADIUS) + 1);
	while (map_pos.y < off.y)
	{
		render_pos.x = 0;
		if (p_pos.x <= PLAYER_RADIUS)
			map_pos.x = 0;
		else
			map_pos.x = p_pos.x - PLAYER_RADIUS;
		off.x = map_pos.x + (2 * PLAYER_RADIUS) + 1;
		if (map_pos.x + ((2 * PLAYER_RADIUS) + 1) >= game->map.width)
			map_pos.x = game->map.width - ((2 * PLAYER_RADIUS) + 1);
		while (map_pos.x < off.x)
		{
			if ((map_pos.y >= 0 && map_pos.y < game->map.height)
				&& (map_pos.x >= 0 && map_pos.x < game->map.width))
			{
				if (game->map.grid[map_pos.y][map_pos.x] == '1')
					draw_wall(&game->display.img, render_pos.y * MINIMAP_SCALE
						+ MINIMAP_PADDING_Y, render_pos.x * MINIMAP_SCALE
						+ MINIMAP_PADDING_X);
			}
			map_pos.x++;
			render_pos.x++;
		}
		map_pos.y++;
		render_pos.y++;
	}
}
