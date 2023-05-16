/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utilities.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 11:12:07 by evocatur          #+#    #+#             */
/*   Updated: 2023/05/16 16:31:42 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void    PrintMatrix(char **Matrix)
{
	char *str;
	if(!Matrix)
		return ;
	while (*Matrix)
	{
		str = *Matrix;
		while (*str)
		{
			printf("\033[0m");
			if(*str == 'P')
				printf("\x1b[32m");
			if(*str == 'C')
				printf("\x1b[33m");
			if(*str == 'E')
				printf("\x1b[34m");
			printf("%c",*str);
			str++;
		}
		Matrix++;
	}
	printf("\n");
	return;
}

t_gameobject    *put_wall_env(t_program program,int x, int y,int type)
{
	int 			width;
	int 			height;
	t_vector2 		temp;
	t_gameobject 	*last;

	last = malloc(sizeof(t_gameobject *));
	if (type == 0)
	{
		last->sprite.img = mlx_xpm_file_to_image(program.mlx, COLONNA, &width, &height);
		mlx_put_image_to_window(program.mlx, program.window.reference, last->sprite.img, x * 50,  y * 100);
		last->pos.y = y * 100;
		last->pos.x = x * 50;
		temp.x = (last->pos.x - width / 2) + 19;
		temp.y = (last->pos.y - height / 2);
		last->collider.tl = temp;
		temp.x = (last->pos.x + width / 2)  + 23;
		temp.y = (last->pos.y + height / 2) + 27;
		last->collider.br = temp;
		return (last);
	}
	return (NULL);
}
bool check_collide_wall(void *param,int x,int y)
{
	t_program		*program;
	t_gameobject 	*last;

	program = (t_program *)param;
	program->man.collider = fixed_player_collider_updatate(param,x,y);
	last = program->map.wall;
	printf("\n player H%i ",program->man.collider.tl.x);
	printf("\n wall H %i ",last->collider.br.x);
	if(!check_overlap_rectangle(param,program->man.collider,last->collider))
	{
		if(!check_overlap_rectangle(param,program->man.collider,last->collider))
			return (false);
		last = last->next;
	} 
	return (true);
}

bool collide_wall_tears(void *param,t_gameobject *tear)
{
	t_program		*program;
	t_gameobject 	*last;

	program = (t_program *)param;
	last = program->map.wall;
 	while (last != NULL)
	{
		if(overlap_circle_rectangle(last->collider, tear))
			return (false);
		last = last->next;
	} 
	return (true);
}
