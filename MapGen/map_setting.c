/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_setting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 23:48:05 by evocatur          #+#    #+#             */
/*   Updated: 2023/05/16 13:50:04 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
