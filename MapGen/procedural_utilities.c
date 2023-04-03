/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   procedural_utilities.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 11:12:07 by evocatur          #+#    #+#             */
/*   Updated: 2023/04/03 12:54:17 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int Random01()
{
    int i = rand() % 2;
    
    if (i == 0)
        return 0;    
    else
        return 1;
}
int random_int(int min, int max)
{
   return min + rand() % (max+1 - min);
}

void PrintMatrix(char **Matrix)
{
    char *str;
    if(!Matrix)
        return ;
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

vector2 random_pos(t_program program)
{
    vector2     pos;
    char        **map;

    map = program.map.matrix_map;
    pos.y = random_int(2 , program.map.widht - 2);
    pos.x = random_int(7 , program.map.height - 10);
    return (pos);
    
}
