/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:07:12 by evocatur          #+#    #+#             */
/*   Updated: 2023/03/22 12:06:58 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"


void PlaceSmallWall(char **map,int x,int j,int colum,int row)
{
    if(x + 1 > row || j + 1 > colum)
        return ;
    if(map[x][j] != '1' && map[x + 1][j] != '1' && map[x][j + 1] != '1' && map[x + 1][j + 1] != '1')
    {
        map[x][j] = '1'; 
        map[x + 1][j] = '1'; 
        map[x ][j + 1] = '1'; 
        map[x + 1][j + 1] = '1';
    }
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