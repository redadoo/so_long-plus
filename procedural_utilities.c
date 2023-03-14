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