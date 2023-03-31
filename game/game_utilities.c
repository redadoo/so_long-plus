/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utilities.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 12:31:33 by evocatur          #+#    #+#             */
/*   Updated: 2023/03/31 15:13:42 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

vector2 obj_pos(char c,char **map)
{
    char *str;
    vector2 pos;
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
                //pos = malloc(sizeof(*vector2));
                pos.x = x;
                pos.y = j;
                return (pos);
            }
            j++;
            str++;
        }
        j = 0;
        x++;
        map++;
    }
    return (pos);
}