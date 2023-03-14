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
    Map = MapPlace(Map,i,ysize,xsize);
    Map = ProceduralMap(Map,i,ysize,xsize);
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

    m = 0;
    x = RandomMax(colum);
    j = RandomMax(row);
    map[j][x] = 'E'; 
    x = RandomMax(colum);
    j = RandomMax(row);
    map[j][x] = 'P';
    m = RandomMax(50);
    while (m)
    {
        x = RandomMax(colum);
        j = RandomMax(row);
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

    m = 4;
    while (m)
    {
        j = random_int(0,colum);
        x = random_int(0,row);
        LongWall(map,x,j);
        m--;
    }
    printf("%i %i\n",j,x);
    return (map);
}