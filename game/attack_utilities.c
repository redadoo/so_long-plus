/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attack_utilities.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:44:53 by evocatur          #+#    #+#             */
/*   Updated: 2023/04/14 14:47:42 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void attack(void *param)
{
	gameobject	*tear;
	t_program	*program;

	program = (t_program *)param;

	push(&program->man.attack_gameobject, param, 1);
	push(&program->man.attack_gameobject, param, 2);
	push(&program->man.attack_gameobject, param, 3);

	ft_lstlast(program->man.attack_gameobject);

	//printf("\n%i\n",tear->exist);

	mlx_put_image_to_window(program->mlx, program->window.reference, tear->sprite.img, tear->pos.x, tear->pos.y);

	//tear = ft_lstlast(tear);

}

/* void move_tear(void *param, gameobject *tear)
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
} */

void manage_attack(void *param)
{
	t_program 	*program;

	program = (t_program *)param;
	gameobject *tear;

/* 	tear = &program->man.attack_gameobject;
	
	move_tear(param,tear);  */

}