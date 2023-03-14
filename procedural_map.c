/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Untitled-1                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 23:48:05 by evocatur          #+#    #+#             */
/*   Updated: 2023/03/13 23:48:05 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char **CreateCubeMap(int ysize,int xsize)
{
    int     i;
    char **Map;
    int x;
    int y;

    y = ysize;
    x = xsize;
    i = ysize * xsize;
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
    PrintMatrix(Map);
    return (Map);
}

char *FillMatrix(bool wall, char *row,int size)
{
    row[size] = '\0';
    char c;
    int x;

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

void PrintMatrix(char **Matrix)
{
    while (*Matrix)
    {
        printf("%s\n",*Matrix);
        Matrix++;
    }
    
}
