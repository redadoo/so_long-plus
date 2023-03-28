/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:57:00 by evocatur          #+#    #+#             */
/*   Updated: 2023/03/28 15:50:59 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_player set_player(t_program program)
{
    int		img_width = 30;
	int		img_height = 30;
	t_player player;
	
    player.sprite.img = mlx_xpm_file_to_image(program.mlx, "Asset/Player.xpm", &img_width, &img_height);
	mlx_put_image_to_window(program.mlx, program.window.reference,  player.sprite.img ,100,100);
	program.man = player;
	player.pos.x = 100;
	player.pos.y = 100;
	return (player);
}

t_data img_player(void *param)
{
	t_program *program = (t_program *)param;

	int		img_width = 30;
	int		img_height = 30;

	t_data imag;
	imag.img = mlx_xpm_file_to_image(program->mlx, "Asset/Player.xpm", &img_width, &img_height);
	return(imag);
}
