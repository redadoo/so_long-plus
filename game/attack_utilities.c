/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attack_utilities.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:44:53 by evocatur          #+#    #+#             */
/*   Updated: 2023/04/26 13:24:27 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void attack(void *param)
{
	t_program	*program;

	program = (t_program *)param;
	spawn_tear(param);
}

void spawn_tear(void *param)
{
	int				w;
	int				h;
	t_program		*program;
	t_gameobject	*tear;
	t_gameobject	*last;

	program = (t_program *)param;
	tear = malloc(sizeof(t_gameobject));
	tear->next = NULL;
	tear->sprite.img = mlx_xpm_file_to_image(program->mlx, TEAR_PATH, &w, &h);
	tear->sprite.b_img = mlx_xpm_file_to_image(program->mlx, TEAR_BACKGROUND_PATH	, &w, &h);
	back_sprite(param, pos_near_player(param), tear->sprite);
	tear->pos = pos_near_player(param);
	tear->dir = program->man.dir;
	tear->exist = 1;
	if (!program->man.tear_gameobject)
	{
		program->man.tear_gameobject = tear;
	}
	else
	{
		last = program->man.tear_gameobject;
		while (last->next != NULL)
		{
			last = last->next;
		}
		last->next = tear;
	}
}
void manage_attack(void *param)
{
	t_program		*program;
	t_gameobject	*tear;
	
	program = (t_program *)param;
	tear = program->man.tear_gameobject;
	if (tear)
	{
		while (tear != NULL)
		{
			move_tear(param,tear);
			tear = tear->next;
		}
	}	
}

void move_tear(void *param,t_gameobject *tear)
{
	t_program		*program;
	t_vector2		pos_t;
	int				dir;
	program = (t_program *)param;
	pos_t = tear->pos;
 	if (check_out_of_screen(param,tear) == 0)
	{
		//printf("\n%i\n",(int)size_list(&program->man.tear_gameobject));
		mlx_put_image_to_window(program->mlx, program->window.reference, tear->sprite.b_img, pos_t.x, pos_t.y);
		return ;
	} 
	mlx_put_image_to_window(program->mlx, program->window.reference, tear->sprite.b_img, pos_t.x, pos_t.y);
	pos_t = move_toward(tear->dir, pos_t, 6);
	put_sprite(param, pos_t, tear->sprite.img);
	tear->pos = pos_t;
}

