/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuchane <ssuchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 18:43:07 by gbuczyns          #+#    #+#             */
/*   Updated: 2024/12/04 17:33:28 by gbuczyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"


void	fps_counter(t_game *game, int frame_time)
{
	static int	i = 0;
	static int	arr[20] = {0};
	int			avg;
	int			fps;

	avg = 0;
	fps = 1000 / frame_time; // Obliczanie FPS na podstawie czasu klatki.
	arr[i] = fps;            // Przypisanie bieżącego FPS do tablicy.
	i = (i + 1) % 20;        // Cycliczny wskaźnik do tablicy.
	// Obliczanie średniej FPS.
	for (int j = 0; j < 20; j++)
		avg += arr[j];
	avg /= 20;
	mlx_string_put(game->display.mlx, game->display.win, 1315, 30, 0xFFFFFF,
		"FPS: ");
	mlx_string_put(game->display.mlx, game->display.win, 1350, 30, 0xFFFFFF,
		ft_itoa(avg));
}

void	set_times(t_game *game)
{
	game->time.new_time = get_time();
	game->time.frame_time = game->time.new_time - game->time.old_time;
	game->time.old_time = game->time.new_time;
	fps_counter(game, (int)game->time.frame_time);
	game->rc.time_ratio = game->time.frame_time / 16.0;
}

void	debug(t_game *game)
{
	printf("pos.y %d pox.x %d \n", (int)game->player.pos.y,
		(int)game->player.pos.x);
	printf("fps: %f\n", 1000.0 / game->time.frame_time);
	printf("pos.x: %f pos.y%f angle %f player.dir.x:"
			"%f playerdir.y	%f planedir.x %f planedir.y %f\n",
			game->player.pos.x,
			game->player.pos.y,
			game->rc.angle,
			game->player.dir.x,
			game->player.dir.y,
			game->player.plane.y,
			game->player.plane.x);
}

void update_frame_nbr(t_raycaster *rc)
{
	rc->sec_part += 1.0 / FPS;
	if (rc->sec_part > 1)
		rc->sec_part -= 1;
	// printf("sec_part: %f\n", rc->sec_part);
}
int	draw(t_game *game)
{
	t_display	*display;
	void		*mlx_img;
	t_raycaster	*rc;

	game->time.start_time = get_time();
	rc = &game->rc;
	display = &game->display;
	draw_background(game, display);
	draw_object(game, '1');
	draw_object(game, 'B');
	render_compass(game);
	add_minimap(game);
	mlx_put_image_to_window(display->mlx, display->win, display->mlx_img, 0, 0);
	limit_fps(game);
	set_times(game);
	move(game);
	// debug(game);
	update_frame_nbr(rc);
	return (0);
}

/*
static void	draw_ceiling(t_display *display, double jump_factor)
{
	int		*image;
	int		i;
	int		j;
	double	factor;
	int		color;

	image = (int *)(display->img.pixel_data);
	i = 0;
	while (i < SCREEN_HEIGHT / 2)
	{
		factor = ((double)(i * i) / ((SCREEN_HEIGHT / 2.0) * (SCREEN_HEIGHT
						/ 2.0)));
		color = scale_color(CEILING, factor);
		j = 0;
		while (j < SCREEN_WIDTH)
		{
			image[(int)((i + jump_factor) * SCREEN_WIDTH + j)] = color;
			j++;
		}
		i++;
	}
}

static void	draw_floor(t_display *display, double jump_factor)
{
	int		*image;
	int		i;
	int		j;
	double	factor;
	int		color;

	image = (int *)(display->img.pixel_data);
	i = SCREEN_HEIGHT / 2;
	while (i < SCREEN_HEIGHT)
	{
		factor = ((double)((SCREEN_HEIGHT - i) * (SCREEN_HEIGHT - i))
				/ ((SCREEN_HEIGHT / 2.0) * (SCREEN_HEIGHT / 2.0)));
		color = scale_color(FLOOR, factor);
		j = 0;
		while (j < SCREEN_WIDTH)
		{
			image[(int)((i + jump_factor) * SCREEN_WIDTH + j)] = color;
			j++;
		}
		i++;
	}
}

void	draw_background(t_game *game)
{
	int			i;
	double		factor;
	double		jump_factor;
	t_display	*display;

	jump_factor = 0;
	display = &game->display;
	i = 0;
	if (game->params.jump)
	{
		if (i < 30 * game->rc.time_ratio)
		{
			factor = 0.5 + ((double)(i * i) / (30.0 * 30.0));
			jump_factor = factor * 10;
				// Adjust the multiplier as needed for the jump effect
		}
		else if (i < 60 * game->rc.time_ratio)
		{
			factor = 1.0 - ((double)(i - 30) * (i - 30) / (30.0 * 30.0));
			jump_factor = factor * 10;
				// Adjust the multiplier as needed for the jump effect
		}
		i++;
		if (i == 60 * game->rc.time_ratio)
		{
			game->params.jump = 0;
			i = 0;
		}
	}
	draw_ceiling(display, jump_factor);
	draw_floor(display, jump_factor);
}
 */
