/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attack_utilities.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:44:53 by evocatur          #+#    #+#             */
/*   Updated: 2023/04/13 18:10:17 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void attack(void *param)
{
	gameobject tear;
	t_program *program;
    int		 	img_width;
	int		 	img_height;

    program = (t_program *)param;
	tear = new_tear(param);
	mlx_put_image_to_window(program->mlx, program->window.reference, tear.sprite.img, tear.pos.x, tear.pos.y);
	tear.exist = 1;
	program->man.attack_gameobject = tear;
}

void move_tear(void *param, gameobject *tear)
{
	t_program 	*program;

	program = (t_program *)param;
    tear->b_pos = tear->pos;
	if (tear->exist == 2)
	{
		tear->pos = move_toward(tear->dir,tear->pos,6);
		if(check_out_of_screen(param, *tear) != 0)
			put_background_sprite(param, tear->b_pos, tear->pos, tear->sprite);
		else
		{
			put_sprite(param, tear->b_pos, tear->sprite.background_img);
			tear->exist = 0;
		}
		program->man.attack_gameobject = *tear;
	}
	else if (tear->exist == 1)
	{
		tear->pos = move_toward(tear->dir,tear->pos,0);
		if(check_out_of_screen(param, *tear) != 0)		
			put_background_sprite(param, tear->b_pos, tear->pos, tear->sprite);
		tear->exist = 2; 
		tear->dir = program->man.dir;
		program->man.attack_gameobject = *tear;
	}   
}

gameobject new_tear(void *param)
{
    t_program *program;
    gameobject tear;

    program = (t_program *)param;
    tear.sprite.background_img = mlx_xpm_file_to_image(program->mlx, TEAR_BACKGROUND_PATH, &tear.sprite.width, &tear.sprite.height);
	tear.sprite.img =  mlx_xpm_file_to_image(program->mlx, TEAR_PATH, &tear.sprite.width, &tear.sprite.height);
    tear.pos = pos_near_player(param);
    return (tear);
}

void manage_attack(void *param)
{
	t_program 	*program;

	program = (t_program *)param;
	gameobject *tear;

	tear = &program->man.attack_gameobject;
	
	move_tear(param,tear); 

}