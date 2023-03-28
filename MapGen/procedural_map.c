/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   procedural_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 23:48:05 by evocatur          #+#    #+#             */
/*   Updated: 2023/03/28 13:52:49 by evocatur         ###   ########.fr       */
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
		if(width == 0 || width == xsize - 1)
			Map[width] = FillMatrix(true,Map[width],ysize,program);
		else
			Map[width] = FillMatrix(false,Map[width],ysize,program);
	}
	wall_manage(program);
	//Map = ProceduralMap(Map,xsize * ysize,ysize,xsize,program);
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
	char c;
	int x;
	int j;
	int m;
	int l;

	x = RandomMax(colum);
	j = RandomMax(row);
	if(map[j][x] != '1')
	{
		map[j][x] = 'E';
	}
	else
	{
		while (map[j][x] == '1')
		{
			x = RandomMax(colum);
			j = RandomMax(row);  
		}
		map[j][x] = 'E';
	}
	l = j;
	m = x;
	x = RandomMax(colum);
	j = RandomMax(row);
	if(map[j][x] != '1' && Distance(x,j,l,m) > 23)
	{
		map[j][x] = 'P';
	}
	else
	{
		while (Distance(x,j,l,m) < 23 && map[j][x] == '1')
		{
			x = RandomMax(colum);
			j = RandomMax(row);  
		}
		map[j][x] = 'P';
	}
	printf("%i\n",Distance(x,j,l,m));
	m = random_int(8,50);
	while (m)
	{
		x = RandomMax(colum);
		j = RandomMax(row);
		if(map[j][x] != '1')
			map[j][x] = 'C';
		m--;
	}
	return (map);
}

char    **ProceduralMap(char **map,int lenghtmatrix,int colum,int row,t_program program)
{
	char c;
	int x;
	int j;
	int m;

 	m = (row * colum) / 100;
	while (m)
	{
		j = random_int(0,colum);
		x = random_int(0,row);
		PlaceSmallWall(map,x,j,colum,row,program);
		m--;
	}
	return (map);
}
void wall_manage(t_program program)
{
    insert_background(program);
    insert_wall(program);
    insert_lateral(program);
    insert_corner(program);
    return ;
}