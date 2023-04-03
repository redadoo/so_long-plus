/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   procedural_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 10:48:15 by evocatur          #+#    #+#             */
/*   Updated: 2023/04/03 11:10:45 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../so_long.h"

void procedural_map(t_program program)
{
    int     i;
    int     j;
    char    **map;

    map = program.map.matrix_map;
    
    t_data      env;
    vector2     env_pos;
    int		 	img_width;
	int		 	img_height;
 
    env.img = mlx_xpm_file_to_image(program.mlx, "Asset/Map/up_wall.xpm", &img_width, &img_height);
    mlx_put_image_to_window(program.mlx, program.window.reference,  env.img ,100,100);
    //PrintMatrix(map);
}