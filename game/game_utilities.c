/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utilities.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 12:31:33 by evocatur          #+#    #+#             */
/*   Updated: 2023/03/29 12:55:15 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int *obj_pos(char c,char **map)
{
    char *str;
    int *list;
    int x;
    int j;

    x = 0;
    j = 0;
    while (*map)
    {
        str = *map;
        while (*str)
        {
            if(*str == c)
            {
                list = calloc(sizeof(int) , 2);
                list[0] = x;
                list[1] = j;
                return (list);
            }
            j++;
            str++;
        }
        j = 0;
        x++;
        map++;
    }
    return (NULL);
}