/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbuczyns <gbuczyns@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:42:46 by ssuchane          #+#    #+#             */
/*   Updated: 2024/11/20 16:55:11 by gbuczyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"
#include <stdio.h>
#include <stdlib.h>

// Function to generate textures, returning a pointer to the allocated memory
void	generate_textures(int ***table, int texWidth, int texHeight)
{
	int	**textures;

	textures = (int **)malloc(TEX_COUNT * sizeof(int *));
	*table = textures;
	if (textures == NULL)
	{
		perror("Failed to allocate memory for textures");
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < TEX_COUNT; i++)
	{
		textures[i] = (int *)malloc(texWidth * texHeight * sizeof(int));
		if (textures[i] == NULL)
		{
			perror("Failed to allocate memory for texture");
			exit(EXIT_FAILURE);
		}
	}
	for (int x = 0; x < texWidth; x++)
	{
		for (int y = 0; y < texHeight; y++)
		{
			textures[0][texWidth * y + x] = COLOR_WHITE;
			textures[1][texWidth * y + x] = COLOR_GRAY;
			textures[2][texWidth * y + x] = COLOR_BRICK_RED;
			textures[3][texWidth * y + x] = COLOR_RED;
			textures[4][texWidth * y + x] = COLOR_TURQUOISE;
			textures[5][texWidth * y + x] = COLOR_MAGENTA;
			textures[6][texWidth * y + x] = COLOR_YELLOW;
			textures[7][texWidth * y + x] = COLOR_BLUE;
		}
	}
}

void	init_player(t_data *data)
{
	data->angle = 90;
	data->initial_plane = INITIAL_PLANE__SIZE;
	data->initial_playerdir = INITIAL_PLAYERDIR;
	data->playerdir.x = data->initial_playerdir * sin(data->angle * M_PI / 180);
	data->playerdir.y = data->initial_playerdir * cos(data->angle* M_PI / 180);
	data->plane.x = data->initial_plane * cos(data->angle * M_PI / 180);
	data->plane.y = data->initial_plane * sin(data->angle * M_PI / 180);
	data->time = 0;
	data->oldTime = 0;
	data->game->player.pos.x = 10.0;
	data->game->player.pos.y = 11.5;
	data->game->player.step_size = STEP_SIZE;
	data->game->player.step_side_side.y = data->game->player.step_size * sin(data->angle* M_PI / 180);
	data->game->player.step_side_side.x = data->game->player.step_size * cos(data->angle* M_PI / 180);
	data->game->player.step_top_down.y = data->game->player.step_size * cos(data->angle* M_PI / 180);
	data->game->player.step_top_down.x = -data->game->player.step_size * sin(data->angle* M_PI / 180);
}

int	main(int ac, char **av)
{
	t_game	data;

	if (ac != 2)
		return (ft_error(1, "Error: Input a map in format *.cub.\n"));
	data.a.game = &data;
	// handle_input(av, &data);
	init_player(&data.a);
	generate_textures(&data.a.texture, TEX_WIDTH, TEX_HEIGHT);
	init_display(&data);
	mlx_loop(data.display.mlx);
	return (0);
}
