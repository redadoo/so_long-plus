/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attack_utilities.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:44:53 by evocatur          #+#    #+#             */
/*   Updated: 2023/04/17 18:14:47 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void attack(void *param)
{
	t_gameobject	*tear;
	t_program	*program;
	t_gameobject	*current;

	program = (t_program *)param;
	current = program->man.tear_t_gameobject;
	if (check_attack(param) == 1)
	{
		if (!program->man.tear_t_gameobject)
		{
			program->man.tear_t_gameobject = NULL;
			program->man.tear_t_gameobject = malloc(sizeof(t_gameobject *));
			if(!program->man.tear_t_gameobject)
				return ;
			program->man.tear_t_gameobject->next = NULL;
			new_tear(param,program->man.tear_t_gameobject);
			tear = program->man.tear_t_gameobject;
		}
		else
		{
			tear = malloc(sizeof(t_gameobject *));
			if(!tear)
				return ;
			new_tear(param,tear);
			tear->next = NULL;
			last_node(&current,tear);
		}
		mlx_put_image_to_window(program->mlx, program->window.reference, tear->sprite.img, tear->pos.x, tear->pos.y);	
	}
}

void move_tear(void *param, t_gameobject *tear)
{
	t_program 	*program;

	program = (t_program *)param;
	tear->b_pos = tear->pos;
	if (tear->exist == 2)
	{
		tear->pos = move_toward(tear->dir,tear->pos,6);
		if (check_out_of_screen(param, tear) != 0)
			back_sprite(param, tear->b_pos, tear->pos, tear->sprite);
		else
		{
			put_sprite(param, tear->b_pos, tear->sprite.b_img);
			free_node_(&program->man.tear_t_gameobject,tear);
			return ;
		}
	}
	else if (tear->exist == 1)
	{
		tear->pos = move_toward(tear->dir,tear->pos,0);
		if (check_out_of_screen(param, tear) != 0)
		{
			back_sprite(param, tear->b_pos, tear->pos, tear->sprite);
			tear->exist = 2;
			tear->dir = program->man.dir;
		}
		else
			free_node_(&program->man.tear_t_gameobject,tear);
	}   
}

void manage_attack(void *param)
{
	size_t		len_list;
	size_t		N_tears;
	t_program	*program;
	t_gameobject	*tear;
	t_gameobject	*current;

	program = (t_program *)param;
	len_list = size_list(&program->man.tear_t_gameobject);
	N_tears = 0;
	while (len_list != 0 && N_tears < len_list)
	{
		current = find_node(&program->man.tear_t_gameobject,N_tears);
		move_tear(param,current); 
		N_tears++;
	}
}

void new_tear(void *param, t_gameobject *tear)
{
	t_program *program;

	program = (t_program *)param;
	tear->sprite.b_img = mlx_xpm_file_to_image(program->mlx, TEAR_BACKGROUND_PATH, &tear->sprite.width, &tear->sprite.height);
	tear->sprite.img =  mlx_xpm_file_to_image(program->mlx, TEAR_PATH, &tear->sprite.width, &tear->sprite.height);
	tear->pos = pos_near_player(param);
	tear->exist = 1;
}

int check_attack(void *param)
{
	t_program	*program;
	size_t		len_list;
	vector2		pos;

	program = (t_program *)param;
	pos = pos_near_player(param);
	len_list = size_list(&program->man.tear_t_gameobject);
	if (len_list >3)
		return (0);
	if (check_out_of_screen_vector(param,pos) == 0)
		return (0);
	return (1);
}