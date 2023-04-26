/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 16:09:40 by evocatur          #+#    #+#             */
/*   Updated: 2023/04/26 16:24:38 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void place_background(void *param)
{
	t_program *program;
	int		img_width; 
	int		img_height;
	int     space;
	int     len;
	t_data  wall;

	program = (t_program *)param;
	space = 0;
	wall.img = mlx_xpm_file_to_image(program->mlx, "Asset/Map/grass.xpm", &img_width, &img_height); 
	mlx_put_image_to_window(program->mlx,program->window.reference, wall.img, 140, 300);
/* 	len = 0;
 	while (len < program->map.height * 10)
	{
		while (space <= program->map.widht * 10)
		{
			wall.img = mlx_xpm_file_to_image(program->mlx, "Asset/Map/grass.xpm", &img_width, &img_height); 
			mlx_put_image_to_window(program->mlx,program->window.reference, wall.img, 100, 100);
			space += 124;
		}
		space = 0;
		len +=img_height;
	}  */
}

void make_file_map(void *param, char **map)
{
	int width;
	int height;
	t_program *program;

	program = (t_program *)param;
	place_background(param);
}