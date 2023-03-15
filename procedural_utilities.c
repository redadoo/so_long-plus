/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   procedural_utilities.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 11:12:07 by evocatur          #+#    #+#             */
/*   Updated: 2023/03/14 11:12:07 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int Random01()
{
    int i = rand() % 2;
    
    if (i == 0)
        return 0;    
    else
        return 1;
}

int RandomMax(int max)
{
    int i = rand() % max;
    if (i == 0 || i == max)
        return RandomMax(max);    
    else
        return i;
}

int random_int(int min, int max)
{
   return min + rand() % (max+1 - min);
}

void PrintMatrix(char **Matrix)
{
    char *str;
    while (*Matrix)
    {
        str = *Matrix;
        while (*str)
        {
            printf("\033[0m");
            if(*str == 'P')
                printf("\x1b[32m");
            if(*str == 'C')
                printf("\x1b[33m");
            if(*str == 'E')
                printf("\x1b[34m");
            printf("%c",*str);
            str++;
        }
        printf("\n");
        Matrix++;
    }
    return;
}

int Distance(int x1,int x2,int y1,int y2)
{
    int x;
    if(x1 > y2)
    {
        x = x1 - y2;
    }
    else
    {
        x = y2 - x1;
    }
    if(x2 > y1)
    {
        x += x2 - y1;
    }
    else    
    {
        x += y1 - x2;
    }
    return (x);
}