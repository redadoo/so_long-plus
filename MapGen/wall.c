/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:07:12 by evocatur          #+#    #+#             */
/*   Updated: 2023/03/31 16:21:45 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"


void PlaceSmallWall(char **map,int x,int j,int colum,int row,t_program program)
{    
    int		img_width; 
	int		img_height;
    t_data  wall;
    if(j + 1 > colum)
    {
        j -= 2;
    }
    if(x + 1 > row)
    {
        x -= 2;
    }
    if(map[x][j] != '1' && map[x + 1][j] != '1' && map[x][j + 1] != '1' && map[x + 1][j + 1] != '1')
    {
        map[x][j] = '1'; 
        map[x + 1][j] = '1'; 
        map[x ][j + 1] = '1'; 
        map[x + 1][j + 1] = '1';
    }
    img_width = 65;
    img_height = 100;
/*     wall.img = mlx_xpm_file_to_image(program.mlx, "Asset/Map/colonna.xpm", &img_width, &img_height); 
    mlx_put_image_to_window(program.mlx,program.window.reference, wall.img, x * 10, j * 10); */
    return;
}

void LongWall(char **map,int x,int j,int colum,int row)
{
    if(x + 2 > row || j + 2 > colum)
        return ;
    if(map[x][j] != '1' && map[x + 1][j] != '1' && map[x + 2][j] != '1' && map[x ][j + 2] != '1'&& map[x + 2][j + 2] != '1')
    {
        map[x][j] = '1'; 
        map[x + 1][j] = '1';
        map[x + 2][j] = '1';
        map[x][j + 1] = '1';
        map[x + 1][j+ 1] = '1';
        map[x + 2][j+ 1] = '1';
    }
    return;
}
