/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_setting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 23:48:05 by evocatur          #+#    #+#             */
/*   Updated: 2023/04/26 16:09:01 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char **CreateCubeMap(int ysize,int xsize,t_program program)
{
	int     i;
	char **Map;
	int width;
	int height;

	height = ysize;
	width = xsize;
	Map = (char **)calloc((width + 1), (sizeof(char *)));
	if(!Map)
		return (NULL);
	while (width)
	{
		width--;
		Map[width] = (char *)malloc((ysize + 1) * (sizeof(char)));
		if(!Map)
			return (NULL);
		if((width >= 0 && width <=6) || (width >= xsize - 9 && width <= xsize - 1))
			Map[width] = assign_rows(true,Map[width],ysize,program);
		else
			Map[width] = assign_rows(false,Map[width],ysize,program);
	}
	background_instance(program);
	Map = spawn_obj(Map, ysize, xsize, program);
	Map = procedural_map(Map);

	//PrintMatrix(Map);
	return (Map);
}

char *assign_rows(bool wall, char *row,int size,t_program program)
{
	int x;
	int i;
	row[size] = '\0';
	x = size -1;
	while (size)
	{
		size--;
		if(size == 0 || size == x || wall|| size == x - 1)
			row[size] = '1';
		else 
			row[size] = '0';
	}
	return (row);
}

char    **spawn_obj(char **map, int colum, int row, t_program program)
{
	t_vector2 pos;

	program.map.matrix_map = map;
	pos = random_pos(program);
	map[pos.x][pos.y] = 'P';
	
	pos = random_pos(program);
	map[pos.x][pos.y] = 'E';
	spawn_manage(program,map);
	return(map);
}

void background_instance(t_program program)
{
    insert_background(program);
    insert_wall(program);
    insert_lateral(program);
    insert_corner(program);
    return ;
}
