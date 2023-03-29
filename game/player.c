/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:57:00 by evocatur          #+#    #+#             */
/*   Updated: 2023/03/29 13:06:59 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_player set_player(t_program program,char **map)
{
	t_player 	player;
    int		 	img_width = 30;
	int		 	img_height = 30;
	int 		*list;

	list = obj_pos('P',map);
    player.sprite.img = mlx_xpm_file_to_image(program.mlx, "Asset/player/player0.xpm", &img_width, &img_height);
	mlx_put_image_to_window(program.mlx, program.window.reference,  player.sprite.img ,list[1] * 10,list[0] * 10);
	player.pos.x = list[1] * 10;
	player.pos.y = list[0] * 10;
	program.man = player;
	return (player);
}
