/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawn_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 15:15:30 by evocatur          #+#    #+#             */
/*   Updated: 2023/03/31 15:49:23 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../so_long.h"

void spawn_manage(t_program program,char **map)
{
    spawn_enviroment(program,map);
    spawn_collectable(program,map);
}

void spawn_collectable(t_program program,char **map)
{
    t_data      env;
    vector2     env_pos;
    int		 	img_width;
	int		 	img_height;
 
    //env.img = mlx_xpm_file_to_image(program.mlx, "Asset/Enviroment/Door.xpm", &img_width, &img_height);
	//env_pos = obj_pos('P',map);
    //mlx_put_image_to_window(program.mlx, program.window.reference,  env.img ,env_pos.y * 10,env_pos.x * 10);
}

void spawn_enviroment(t_program program,char **map)
{
    t_data      env;
    vector2     env_pos;
    int		 	img_width;
	int		 	img_height;
 
    env.img = mlx_xpm_file_to_image(program.mlx, "Asset/Enviroment/Door.xpm", &img_width, &img_height);
	env_pos = obj_pos('E',map);
    mlx_put_image_to_window(program.mlx, program.window.reference,  env.img ,env_pos.y * 10,env_pos.x * 10);
}