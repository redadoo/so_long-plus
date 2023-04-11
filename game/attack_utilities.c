/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attack_utilities.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:44:53 by evocatur          #+#    #+#             */
/*   Updated: 2023/04/11 16:57:03 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void attack_exist(void *param)
{
    t_program *program = (t_program *)param;
    gameobject tear;
    tear = program->man.attack_gameobject;
    tear.sprite.img =  mlx_xpm_file_to_image(program->mlx, TEAR_PATH, &tear.sprite.width, &tear.sprite.height);
    tear.pos = pos_near_player(param);
    mlx_put_image_to_window(program->mlx, program->window.reference,  tear.sprite.img ,tear.pos.x, tear.pos.y);
}

void attack(void *param)
{
	gameobject tear;
	t_program *program;

    program = (t_program *)param;
	tear = program->man.attack_gameobject;
	tear.pos = pos_near_player(param);
	mlx_put_image_to_window(program->mlx, program->window.reference, tear.sprite.img, tear.pos.x, tear.pos.y);
	tear.exist = 1;
	program->man.attack_gameobject = tear;
}

void move_tear()
{
    
}