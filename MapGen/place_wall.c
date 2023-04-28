/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:43:22 by evocatur          #+#    #+#             */
/*   Updated: 2023/04/28 13:25:19 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../so_long.h"

void insert_wall(t_program program)
{
	int		img_width; 
	int		img_height;
	int     space;
	t_data  wall;

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
	t_data  wall;

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
	t_data  wall;

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
	t_data  wall;

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

void insert_wall_enviroment(t_program program)
{
	int		i;
	int		j;
	int		img_width; 
	int		img_height;
	char	**matrix;
	t_data  wall;

	i = 0;
	j = 0;
	matrix = program.map.matrix_map;
	wall.img = mlx_xpm_file_to_image(program.mlx, "Asset/Map/wall_e.xpm", &img_width, &img_height); 
	wall.b_img = mlx_xpm_file_to_image(program.mlx, "Asset/Enviroment/colonna.xpm", &img_width, &img_height); 
	while (i < program.map.height)
	{
		while (j < program.map.widht)
		{
			if ((matrix[i][j] == '1') && (i > 0) && (i < program.map.height - 1) && (j > 0)  && (j != program.map.widht - 2) && ((matrix[i][j + 1] == '1') || (matrix[i][j - 1] == '1')))
				mlx_put_image_to_window(program.mlx,program.window.reference, wall.img, j * 50, i * 100);
			else if((matrix[i][j] == '1') && (i > 0) && (i < program.map.height - 1) && (j > 0)  && (j != program.map.widht - 2) && (matrix[i][j + 1] != '1'))
				mlx_put_image_to_window(program.mlx,program.window.reference, wall.b_img, j * 60, i * 70);
			j++;
		}
		j = 0;
		i++;
	} 
}
