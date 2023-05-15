/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utilities_4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 11:11:31 by evocatur          #+#    #+#             */
/*   Updated: 2023/05/15 13:25:52 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void collect_coin(void *param)
{
	t_program		*program;
	t_gameobject 	*coins;

	program = (t_program *)param;
	program->man.collider = player_collider_updatate(param);
	if (program->env.coins.coin != NULL)
	{
		coins = program->env.coins.coin;
		while (coins != NULL)
		{
			if (!check_overlap_rectangle(param,coins->collider,program->man.collider) && coins->exist != 0)
			{
				put_sprite(param,coins->pos,program->env.coins.sprite0.b_img);
				program->man.coin.value++;
				coins->exist = 0;
			}
			coins = coins->next;
		}
	}
}
bool check_overlap_rectangle(void *param,t_Rect obj1,t_Rect obj2)
{
	if ((  obj1.X1.x  <  obj2.Y2.x  )  &&  (   obj1.Y2.x   >  obj2.X1.x  )  && (  obj1.X1.y  <  obj2.Y2.y  )  && (  obj1.Y2.y  >  obj2.X1.y  ))
		return (false);
	return (true);
}
bool check_overlap_circle(void *param,t_gameobject obj1,t_gameobject obj2)
{
	int			r1;
	int			r2;
	double		d;
	t_vector2	pos1;
	t_vector2	pos2;

	pos1 = obj1.pos;
	pos2 = obj2.pos;
	r1 = obj1.sprite.width / 2;
	r2 = obj2.sprite.width / 2;
	d = sqrt((pos1.x - pos2.x) * (pos1.x - pos2.x) + (pos1.y - pos2.y) * (pos1.y - pos2.y));
    if (d <= r1 - r2) 
		return (true);
    else if (d <= r2 - r1) 
		return (true);
    else if (d < r1 + r2) 
		return (true);
    else if (d == r1 + r2) 
    	return (true);
	return (false);
    
}
void hud_update(void *param)
{
	int 			step_count;
	char			*str_step;
	char			*str_coin;
	t_program		*program;
	t_data			back;

	program = (t_program *)param;
	str_step = ft_itoa(program->man.step.value);
	str_coin = ft_itoa(program->man.coin.value);
	back.img = give_sprite(param,BLACKB);
	//printf("\n%i",program->man.coin.value);
	mlx_put_image_to_window(program->mlx,program->window.reference,back.img,155,program->window.size.y + 20);
	mlx_string_put(program->mlx,program->window.reference, 155,program->window.size.y + 20,0xccccff,str_step);
	mlx_put_image_to_window(program->mlx,program->window.reference,back.img,155,program->window.size.y + 50);
	mlx_string_put(program->mlx,program->window.reference, 155,program->window.size.y + 50,0xccccff,str_coin);
}
