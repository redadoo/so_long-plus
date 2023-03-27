/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:43:22 by evocatur          #+#    #+#             */
/*   Updated: 2023/03/27 12:17:44 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../so_long.h"

int insert_upper_wall(int d,t_program program)
{
    int		img_width; 
	int		img_height;
    t_wall wall;
    img_height = 60;
    img_width = 130;

    wall.img = mlx_xpm_file_to_image(program.mlx, "Asset/Map/UP_WALL.xpm", &img_width, &img_height); 
    mlx_put_image_to_window(program.mlx,program.window.reference, wall.img, d, 0);
    return (d + 127);
}
int insert_down_wall(int d,t_program program)
{
    int		img_width; 
	int		img_height;
    t_wall wall;
    img_height = 60;
    img_width = 130;

    wall.img = mlx_xpm_file_to_image(program.mlx, "Asset/Map/DOWN_WALL.xpm", &img_width, &img_height); 
    mlx_put_image_to_window(program.mlx,program.window.reference, wall.img, d, 540);
    return (d + 127);
}
int insert_right_wall(int d,t_program program)
{
    int		img_width; 
	int		img_height;
    t_wall wall;
    img_height = 60;
    img_width = 130;

    wall.img = mlx_xpm_file_to_image(program.mlx, "Asset/Map/DOWN_WALL.xpm", &img_width, &img_height); 
    mlx_put_image_to_window(program.mlx,program.window.reference, wall.img, d, 0);
    return (d + 127);
}
int insert_left_wall(int d,t_program program)
{
    int		img_width; 
	int		img_height;
    t_wall wall;
    img_height = 60;
    img_width = 130;

    wall.img = mlx_xpm_file_to_image(program.mlx, "Asset/Map/DOWN_WALL.xpm", &img_width, &img_height); 
    mlx_put_image_to_window(program.mlx,program.window.reference, wall.img, d, 0);
    return (d + 127);
}
void insert_colum(int x,int y,t_program program)
{
    int		img_width; 
	int		img_height;
    t_wall colum;
    img_height = 100;
    img_width = 65;
    colum.img = mlx_xpm_file_to_image(program.mlx, "Asset/Map/colonna.xpm", &img_width, &img_height); 
    mlx_put_image_to_window(program.mlx,program.window.reference, colum.img, x, y);
    return ;
}