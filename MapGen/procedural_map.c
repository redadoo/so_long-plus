/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   procedural_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 23:48:05 by evocatur          #+#    #+#             */
/*   Updated: 2023/03/22 12:06:51 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char **CreateCubeMap(int ysize,int xsize)
{
	int     i;
	char **Map;
	int x;
	int y;

	y = ysize;//colonne
	x = xsize;//righe
	i = ysize * xsize;//quantita di spazi dentro la tabella
	Map = (char **)calloc(xsize + 1, (sizeof(char *)));
	if(!Map || ysize <=2 ||xsize <=2)
		return (NULL);
	while (x)
	{
		x--;
		Map[x] = (char *)malloc(ysize + 1 * (sizeof(char)));
		if(!Map)
			return (NULL);
		if(x == 0 || x == xsize - 1)
			Map[x] = FillMatrix(true,Map[x],ysize);
		else
			Map[x] = FillMatrix(false,Map[x],ysize);
	}
	Map = ProceduralMap(Map,i,ysize,xsize);
	Map = MapPlace(Map,i,ysize,xsize);
	PrintMatrix(Map);
	return (Map);
}

char *FillMatrix(bool wall, char *row,int size)
{
	char c;
	int x;

	row[size] = '\0';
	x = size -1;
	while (size)
	{
		size--;
		if(size == 0 || size == x || wall)
			row[size] = '1';
		else
		{
			row[size] = '0';
		}
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

char    **ProceduralMap(char **map,int lenghtmatrix,int colum,int row)
{
	char c;
	int x;
	int j;
	int m;

	m = 30;
	while (m)
	{
		j = random_int(0,colum);
		x = random_int(0,row);
		LongWall(map,x,j,colum,row);
		m--;
	}
	m = 12;
	while (m)
	{
		j = random_int(0,colum);
		x = random_int(0,row);
		PlaceSmallWall(map,x,j,colum,row);
		m--;
	}
	return (map);
}