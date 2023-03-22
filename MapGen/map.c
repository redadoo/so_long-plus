/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:43:22 by evocatur          #+#    #+#             */
/*   Updated: 2023/03/22 12:29:52 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../so_long.h"

void place_background(t_program program)
{
    t_data background;

    int		img_width = 256;
	int		img_height = 256;
    background.img = mlx_xpm_file_to_image(program.mlx, "Asset/Map/TX-Tileset-Grass.xpm", &img_width, &img_height); 
    mlx_put_image_to_window(program.mlx,program.window.reference, background.img, 100, 100);
}

void generatemap(t_program program)
{
    void *img2;
    char **Matrix;
    int row;
    int colum;
    int		img_width = 256;
	int		img_height = 256;
    int j,i;
    t_data wall;
    row = program.window.size.x /10;
    colum = program.window.size.y /10;
    Matrix = CreateCubeMap(colum,row);
    i = 0;
    j = 0;
    place_background(program);
/*     while (i != colum)
    {
        while (j != row)
        {
            if(Matrix[j][i] == '0')
            {
                wall.img = mlx_xpm_file_to_image(program.mlx, "Asset/Map/paviment.xpm", &img_width, &img_height); 
                mlx_put_image_to_window(program.mlx,program.window.reference, wall.img, j * 10, i * 10);
            }
            else if (Matrix[j][i] == '1')
            {
                wall.img = mlx_xpm_file_to_image(program.mlx, "Asset/Map/paviment.xpm", &img_width, &img_height); 
                mlx_put_image_to_window(program.mlx,program.window.reference, wall.img, j * 10, i * 10);
            }
            j++;
        }
        j = 0;
        i++;
    } */
    
}

void readmap(t_program program ,char *file)
{   
    exit(0);
    return;
}