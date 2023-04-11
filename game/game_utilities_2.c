/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utilities_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:40:28 by evocatur          #+#    #+#             */
/*   Updated: 2023/04/11 16:21:57 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

vector2 move_toward(int dir,vector2 pos,int dist)
{
    if(dir == UP_DIR)
        pos.y -= dist;
    else if(dir == DOWN_DIR)
        pos.y += dist;
    else if(dir == RIGHT_DIR)
        pos.x += dist;
    else if(dir == LEFT_DIR)
        pos.x -= dist;
    return (pos);
}

void attack_exist(void *param)
{
    t_program *program = (t_program *)param;
    gameobject tear;
    tear = program->man.attack_gameobject;
    tear.sprite.img =  mlx_xpm_file_to_image(program->mlx, "Asset/player/tear.xpm", &tear.sprite.width, &tear.sprite.height);
    tear.pos = pos_near_player(param);
    mlx_put_image_to_window(program->mlx, program->window.reference,  tear.sprite.img ,tear.pos.x, tear.pos.y);
}

vector2 pos_near_player(void *param)
{
    t_program *program = (t_program *)param;
    vector2 pos;

    if(program->man.dir == UP_DIR)
	{
		pos.x = program->man.pos.x + 5; 
		pos.y = program->man.pos.y - 13;
	}
	if(program->man.dir == DOWN_DIR)
	{
		pos.x = program->man.pos.x + 5; 
		pos.y = program->man.pos.y + 52;
	}
	if(program->man.dir == LEFT_DIR)
	{
		pos.x = program->man.pos.x - 15; 
		pos.y = program->man.pos.y + 10;
	}
	if(program->man.dir == RIGHT_DIR)
	{
		pos.x = program->man.pos.x + 25; 
		pos.y = program->man.pos.y + 10;
	}
    return (pos);
}

int put_sprite(void *param,vector2 pos,void *img_ptr)
{
    t_program	*program;
    
    program = (t_program *)param;
    mlx_put_image_to_window(program->mlx, program->window.reference, img_ptr, pos.x, pos.y);
    return (0);
}