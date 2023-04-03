/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   procedural_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 10:48:15 by evocatur          #+#    #+#             */
/*   Updated: 2023/04/03 13:57:41 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../so_long.h"

char **procedural_map(char **map)
{
    vector2 player_pos;
    vector2 seeker_pos;
    int     time;
    int     dir;
    player_pos = obj_pos('P',map);
    seeker_pos.x = 8;
    seeker_pos.y = 3;
    time = random_int(1,48);
    return (map);
}