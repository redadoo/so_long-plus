/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 11:26:25 by evocatur          #+#    #+#             */
/*   Updated: 2023/04/05 15:30:36 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void special_action(int keycode,void *param)
{
    t_program *program = (t_program *)param;

    if(keycode == 53)
        exit(0);
}

bool check_move(char **map,int x,int y)
{
    x /=10;
    y /=10;
    if(map[y][x] == '0')
    {
        return (true);
    }
    return (false);
}
