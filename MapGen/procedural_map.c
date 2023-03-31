/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   procedural_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 23:48:05 by evocatur          #+#    #+#             */
/*   Updated: 2023/03/31 16:44:24 by evocatur         ###   ########.fr       */
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
		if((width >= 0 && width <=5) || (width >=  xsize - 9 && width <= xsize - 1))
			Map[width] = FillMatrix(true,Map[width],ysize,program);
		else
			Map[width] = FillMatrix(false,Map[width],ysize,program);
	}
	wall_manage(program);
	Map = ProceduralMap(Map,xsize * ysize,ysize,xsize,program);
	spawn_manage(program,Map);
	PrintMatrix(Map);
	return (Map);
}

char *FillMatrix(bool wall, char *row,int size,t_program program)
{
	int x;
	int i;
	row[size] = '\0';
	x = size -1;
	while (size)
	{
		size--;
		if(size == 0 || size == x || wall)
			row[size] = '1';
		else 
			row[size] = '0';
	}
	return (row);
}

char    **MapPlace(char **map,int lenghtmatrix,int colum,int row)
{
	return (map);
}

char    **ProceduralMap(char **map,int lenghtmatrix,int colum,int row,t_program program)
{
	char c;
	int m;
	vector2 pos;

	program.map.matrix_map = map;
	pos = random_pos(program);
	map[pos.x][pos.y] = 'P';
	
	pos = random_pos(program);
	map[pos.x][pos.y] = 'E';

	return(map);

}
void wall_manage(t_program program)
{
    insert_background(program);
    insert_wall(program);
    insert_lateral(program);
    insert_corner(program);
    return ;
}
