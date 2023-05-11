/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utilities_4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 11:11:31 by evocatur          #+#    #+#             */
/*   Updated: 2023/05/11 16:48:30 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void collect_coin(void *param)
{
	t_program		*program;
	t_gameobject 	*coins;

	program = (t_program *)param;

	if (program->env.coins.coin != NULL)
	{
		coins = program->env.coins.coin;
		while (coins != NULL)
		{
			if (check_collect(param,coins->pos,program->man.pos))
			{
				printf("\ncollect");
			}
			coins = coins->next;
		}
	}
}

bool check_overlap_rectangle(void *param,t_gameobject obj1,t_gameobject obj2)
{
	t_Rect RectA;
	t_Rect RectB;

	RectA = obj1.collider;
	RectB = obj2.collider;
	if (RectA.X1 < RectB.X2 && RectA.X2 > RectB.X1 && 
			RectA.Y1 > RectB.Y2 && RectA.Y2 < RectB.Y1)		
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

