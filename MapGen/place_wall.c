/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:43:22 by evocatur          #+#    #+#             */
/*   Updated: 2023/03/29 11:54:13 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../so_long.h"

void insert_wall(t_program program)
{
    int		img_width; 
	int		img_height;
    int     space;
    t_wall  wall;

    img_height = 60;
    img_width = 130;
    space = 0;
    while (space < program.window.size.x - img_width )
    {
        wall.img = mlx_xpm_file_to_image(program.mlx, "Asset/Map/DOWN_WALL.xpm", &img_width, &img_height); 
        mlx_put_image_to_window(program.mlx,program.window.reference, wall.img, space, 0);
        space += 74;
    }
    space = 0;
    while (space < program.window.size.x - img_width )
    {
        wall.img = mlx_xpm_file_to_image(program.mlx, "Asset/Map/DOWN_WALL.xpm", &img_width, &img_height); 
        mlx_put_image_to_window(program.mlx,program.window.reference, wall.img, space, program.window.size.y - img_height);
        space += 73;
    }
}

void insert_lateral(t_program program)
{   
    int		img_width; 
	int		img_height;
    int     space;
    t_wall  wall;

    img_width = 8;
    img_height = 96;
    space = 0;
    while (space < program.window.size.y - img_height)
    {
        wall.img = mlx_xpm_file_to_image(program.mlx, "Asset/Map/LATERAL_WALL.xpm", &img_width, &img_height); 
        mlx_put_image_to_window(program.mlx,program.window.reference, wall.img, 0, space);
        space += 96;
    }
    space = 0;
    while (space < program.window.size.y - img_height)
    {
        wall.img = mlx_xpm_file_to_image(program.mlx, "Asset/Map/LATERAL_WALL.xpm", &img_width, &img_height); 
        mlx_put_image_to_window(program.mlx,program.window.reference, wall.img, program.window.size.x - img_width, space);
        space += 96;
    }
}

void insert_corner(t_program program)
{
    int		img_width; 
	int		img_height;
    int     space;
    t_wall  wall;

    img_width =96;
    img_height = 104;
    space = 0;
    wall.img = mlx_xpm_file_to_image(program.mlx, "Asset/Map/Up_left.xpm", &img_width, &img_height); 
    mlx_put_image_to_window(program.mlx,program.window.reference, wall.img, 0, 0);
    img_width =96;
    img_height = 127;
    wall.img = mlx_xpm_file_to_image(program.mlx, "Asset/Map/left_down.xpm", &img_width, &img_height); 
    mlx_put_image_to_window(program.mlx,program.window.reference, wall.img, 0, program.window.size.y - img_height);
    img_width =96;
    img_height = 104;
    wall.img = mlx_xpm_file_to_image(program.mlx, "Asset/Map/up_right.xpm", &img_width, &img_height); 
    mlx_put_image_to_window(program.mlx,program.window.reference, wall.img, program.window.size.x - img_width, 0);
    img_width =85;
    img_height = 126;
    wall.img = mlx_xpm_file_to_image(program.mlx, "Asset/Map/down_right.xpm", &img_width, &img_height); 
    mlx_put_image_to_window(program.mlx,program.window.reference, wall.img, program.window.size.x - img_width, program.window.size.y - img_height);
}
void insert_background(t_program program)
{
    int		img_width; 
	int		img_height;
    int     space;
    int     len;
    t_wall  wall;

    img_height = 124;
    img_width = 129;
    space = 0;
    len = 0;
    while (len <program.window.size.y)
    {
        while (space <= program.window.size.x)
        {
            wall.img = mlx_xpm_file_to_image(program.mlx, "Asset/Map/grass.xpm", &img_width, &img_height); 
            mlx_put_image_to_window(program.mlx,program.window.reference, wall.img, space, len);
            space += 124;
        }
        space = 0;
        len +=img_height;
    }
}
