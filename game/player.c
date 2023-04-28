/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:57:00 by evocatur          #+#    #+#             */
/*   Updated: 2023/04/28 14:47:50 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_player	set_player(t_program program, char **map)
{
	t_player	player;
	int			img_width;
	int			img_height;
	t_vector2	player_start_pos;
	t_data		enemy;

	player_start_pos = obj_pos('P', map);
	player.sprite.img = mlx_xpm_file_to_image(program.mlx, SPRITE1, &img_width, &img_height);
	mlx_put_image_to_window(program.mlx, program.window.reference, player.sprite.img, player_start_pos.y * 50, player_start_pos.x * 100);
	player.sprite.b_img = mlx_xpm_file_to_image(program.mlx, "Asset/player/grass.xpm", &player.sprite.width, &player.sprite.height);
	player.pos.x = player_start_pos.y * 50;
	player.pos.y = player_start_pos.x * 100;
	return (player);
}
