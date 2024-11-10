/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbuczyns <gbuczyns@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:42:46 by ssuchane          #+#    #+#             */
/*   Updated: 2024/11/10 18:06:01 by gbuczyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	main(int ac, char **av)
{
	t_game	data;
	int		i;


	if (ac != 2)
		return (ft_error(1, "Error: Input a map in format *.cub.\n"));
	handle_input(av, &data);
	init_display(&data);
	mlx_loop(data.display.mlx);
	return (0);
}
