/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_setting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 23:48:05 by evocatur          #+#    #+#             */
/*   Updated: 2023/05/15 11:10:45 by evocatur         ###   ########.fr       */
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
	background_instance(program, 0);
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

t_gameobject	*background_instance(t_program program,int i)
{
    insert_background(program);
    insert_wall(program);
    insert_lateral(program);
    insert_corner(program);
	if (i == 1)
		return (insert_wall_enviroment(program));
    return (NULL);
}
