/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attack_utilities.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:44:53 by evocatur          #+#    #+#             */
/*   Updated: 2023/04/14 17:42:41 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void attack(void *param)
{
	gameobject	*tear;
	t_program	*program;
	gameobject	*current;
	program = (t_program *)param;

	current = program->man.tear_gameobject;
	if(!program->man.tear_gameobject)
	{
		program->man.tear_gameobject = NULL;
		program->man.tear_gameobject = malloc(sizeof(gameobject *));
		if(!program->man.tear_gameobject)
			return ;
		program->man.tear_gameobject->next = NULL;
		new_tear(param,program->man.tear_gameobject);
		tear = program->man.tear_gameobject;
	}
	else
	{
		tear = malloc(sizeof(gameobject *));
		if(!tear)
			return ;
		new_tear(param,tear);
		tear->next = NULL;
		last_node(&current,tear);
		size_list(&program->man.tear_gameobject);
	}
	
	mlx_put_image_to_window(program->mlx, program->window.reference, tear->sprite.img, tear->pos.x, tear->pos.y);

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
		program->man.tear_gameobject = tear;
	}
	else if (tear->exist == 1)
	{
		tear->pos = move_toward(tear->dir,tear->pos,0);
		if(check_out_of_screen(param, *tear) != 0)		
			put_background_sprite(param, tear->b_pos, tear->pos, tear->sprite);
		tear->exist = 2; 
		tear->dir = program->man.dir;
		program->man.tear_gameobject = tear;
	}   
}

void manage_attack(void *param)
{
	size_t N_tears;
	t_program	*program;
	gameobject	*tear;
	gameobject	*current;

	program = (t_program *)param;
	N_tears = 0;
	current = program->man.tear_gameobject;
	while (N_tears < size_list(&program->man.tear_gameobject))
	{
		current = find_node(&program->man.tear_gameobject,N_tears);
		move_tear(param,current); 
		N_tears++;
	}
}

void new_tear(void *param, gameobject *tear)
{
	t_program *program;

	program = (t_program *)param;
	tear->sprite.background_img = mlx_xpm_file_to_image(program->mlx, TEAR_BACKGROUND_PATH, &tear->sprite.width, &tear->sprite.height);
	tear->sprite.img =  mlx_xpm_file_to_image(program->mlx, TEAR_PATH, &tear->sprite.width, &tear->sprite.height);
	tear->pos = pos_near_player(param);
	tear->exist = 1;
}
