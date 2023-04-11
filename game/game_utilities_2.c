/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utilities_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:40:28 by evocatur          #+#    #+#             */
/*   Updated: 2023/04/11 16:45:06 by evocatur         ###   ########.fr       */
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
int put_background_sprite(void *param,vector2 pos_b,vector2 pos_s,t_data sprite)
{
    t_program	*program;
    
    program = (t_program *)param;
    mlx_put_image_to_window(program->mlx, program->window.reference, sprite.background_img, pos_b.x, pos_b.y);
    mlx_put_image_to_window(program->mlx, program->window.reference, sprite.img, pos_s.x, pos_s.y);
    return (0);
}
